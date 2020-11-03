#include "produce.h"

#include <algorithm>
#include <string>
#include <fstream>

using std::ofstream;
using std::ifstream;
using std::ios;
using std::to_string;
using std::find_if;

void Produce::setOutputPath(const string& str) {
	mOutputPath = str;
	string::size_type pos1 = mOutputPath.find_last_of('/');
	if (pos1 > mOutputPath.size()) pos1 = 0;
	string::size_type pos2 = mOutputPath.find_last_of('\\');
	if(pos2 > mOutputPath.size()) pos2 = 0;
	string::size_type pos = pos1 > pos2 ? pos1 : pos2;
	mHeadName = mOutputPath.substr(pos, mOutputPath.size() - pos);
	if (!mHeadName.empty() && (mHeadName.at(0) == '/' || mHeadName.at(0) == '\\')) {
		mHeadName = mHeadName.substr(1, mHeadName.size() - 1);
	}
}

void Produce::produceHead(string& codeOutside, string& codePublic, string& codePrivate) {
	const string oriHeadPath = "yacc_parse_ori.h";
	ifstream in(oriHeadPath, ios::binary);
	string content;
	in.seekg(0, ios::end);
	long long length = in.tellg();
	in.seekg(0);
	char buf[2048];
	while (length > 0) {
		int bufSize = (int) (length >= 2048 ? 2048 : length);
		in.read(buf, bufSize);
		length -= bufSize;
		content.append(buf, buf + bufSize);
	}
	in.close();
	
	replaceStr(content, "wordheader", mWordHeader);
	replaceStr(content, "ParseClassName", mParseName);
	replaceStr(content, "WordClassName", mWordName);
	if (!mNamespace.empty()) {
		replaceStr(content, "HEAD_H", mNamespace + "_" + mParseName + "_H");
	}
	else {
		replaceStr(content, "HEAD_H", mParseName + "_H");
	}

	if (mNamespace.empty()) {
		replaceStr(content, "// namespace_left", "");
		replaceStr(content, "// namespace_right", "");
	}
	else {
		replaceStr(content, "// namespace_left", "namespace " + mNamespace + " {\n");
		replaceStr(content, "// namespace_right", "}\n");
	}
	
	if (codeOutside.empty()) {
		replaceStr(content, "// CodeHOutSide", "");
	}
	else {
		replaceStr(content, "// CodeHOutSide", codeOutside);
	}
	
	if (codePublic.empty()) {
		replaceStr(content, "	// CodeHPublic", "");
	}
	else {
		replaceStr(content, "	// CodeHPublic", codePublic);
	}
	
	if (codePrivate.empty()) {
		replaceStr(content, "	// CodeHPrivate", "");
	}
	else {
		replaceStr(content, "	// CodeHPrivate", codePrivate);
	}
	
	string filePath = mOutputPath + ".h";
	ofstream out(filePath, ios::binary | ios::trunc);
	out.write(content.data(), content.size());
	out.close();
}

void Produce::produceCpp(LALR& lalr, string& code)
{
	string filePath = mOutputPath + ".cpp";
	ofstream out(filePath, ios::trunc);
	
	out << "#include \"" + mHeadName + ".h\"\n";
	if(!mNamespace.empty()) {
		out << "using namespace " + mNamespace + ";\n";
	}

	out << code << '\n';
	
	out << "void " << mParseName << "::reduce(size_t reduceId) {\n";
	out << "\tswitch(reduceId) {\n";
	for (size_t i = 0; i < lalr.reduce.size(); ++i) {
		Reduce& reduce = lalr.reduce[i];
		if (reduce.functionName == "") continue;
		out << "\tcase " << i << ": {\n\t\t// " << reduce.content << "\n";

		if (1) { // support shared_ptr
			string parameter;
			for (size_t j = reduce.childrenCount; j >= 1; --j) {
				if (reduce.childrenType[j - 1].empty()) continue;
				string sharedPtrNme = "shared_ptr<" + reduce.childrenType[j - 1] + ">";
				out << "\t\t" << sharedPtrNme << " unit" << j << " = dynamic_pointer_cast<" << reduce.childrenType[j - 1] <<">(mUnitStack.top());\n";
				out << "\t\tmUnitStack.pop();\n";
				if (parameter != "") parameter = ", " + parameter;
				parameter = "unit" + to_string(j) + parameter;
			}
			out << "\t\t\n";
			if (reduce.parentType == "") {
				out << "\t\t" << reduce.functionName << "(" + parameter << ");\n";
			}
			else {
				string sharedPtrNme = "shared_ptr<" + reduce.parentType + ">";
				out << "\t\t" << sharedPtrNme << " parent = " << reduce.functionName << "(" + parameter << ");\n";
				out << "\t\tmUnitStack.push(parent);\n";
			}
		}
		else {
			string parameter;
			for (size_t j = reduce.childrenCount; j >= 1; --j) {
				out << "\t\t" << reduce.childrenType[j - 1] << "* unit" << j << " = (" << reduce.childrenType[j - 1] << "*)mUnitStack.top();\n";
				out << "\t\tmUnitStack.pop();\n";
				if (parameter != "") parameter += ", ";
				parameter = parameter + "unit" + to_string(reduce.childrenCount - j + 1);
			}
			out << "\t\t\n";
			if (reduce.parentType == "") {
				out << "\t\t" << reduce.functionName << "(" + parameter << ");\n";
			}
			else {
				out << "\t\t" << reduce.parentType << "* parent = " << reduce.functionName << "(" + parameter << ");\n";
				out << "\t\tmUnitStack.push(parent);\n";
			}
		}

		out << "\t\tbreak;\n";
		out << "\t}\n";
	}
	out << "\tdefault:\n";
	out << "\t\tbreak;\n";
	out << "\t}\n";
	out << "}\n";
	
	out.close();
}

void Produce::produceLalr(LALR& lalr, bool details)
{
	string filePath = mOutputPath + "Init.cpp";
	ofstream out(filePath, std::ios::trunc);
	
	out << "#include \"" + mHeadName + ".h\"\n\n";
	if(!mNamespace.empty()) {
		out << "using namespace " + mNamespace + ";\n\n";
	}
	
	out << "vector<vector<Action>> " << mParseName << "::sAction = {\n";
	if (details) {
		out << "\t//";
		size_t width = lalr.wordTypeToId.size();
		int margin = 0;
		for (size_t i = 0; i < width; ++i) {
			margin += 21;
			auto func = [i](pair<string, TerminalId>& p) { return p.second == i; };
			auto it = find_if(lalr.wordTypeToId.begin(), lalr.wordTypeToId.end(), func);
			if (it != lalr.wordTypeToId.end()) {
				string str = to_string(it->second) + ":" + it->first;
				out << str;
				margin -= str.size();
				while (margin > 0) {
					--margin;
					out << ' ';
				}
			}
			else {
				assert(false);
			}
		}
		out << "\n";
	}
	
	for (size_t i = 0; i < lalr.action.size(); ++i) {
		auto column = lalr.action[i];
		if (details) {
			for (string str : lalr.statusInfo[i]) {
				out << "\t// " << str << "\n";
			}
		}
		out << "\t{";
		for (auto action : column) {
			string typeStr;
			switch (action.type) {
			case Action::Shift:
				typeStr = "Action::S";
				break;
			case Action::Reduce:
				typeStr = "Action::R";
				break;
			case Action::Error:
				typeStr = "Action::E";
				break;
			}
			char str[64];
			snprintf(str, 64, "0x%04x", action.val);
			out << " {" << typeStr << ", " << str << "},";
		}
		out << "},\n";
	}
	out << "};\n\n";

	out << "vector<vector<StatusId>> " << mParseName << "::sGoto = {\n";
	for (auto column : lalr.goTo) {
		out << "\t{";
		for (auto _goto : column) {
			out << "\t" << _goto << ",";
		}
		out << "},\n";
	}
	out << "};\n\n";

	out << "vector<Reduce> " << mParseName << "::sReduce = {\n";
	for (auto reduce : lalr.reduce) {
		out << "\t{ " << reduce.parent << ", " << reduce.childrenCount << "},\n";
	}
	out << "};\n\n";

	out << "unordered_map <StatusId, string> " << mParseName << "::sStatusToUnitName = {\n";
	for (auto statusToUnitName : lalr.statusToUnitName) {
		string name;
		if (statusToUnitName.second.front() == '\'') {
			name = "\"" + statusToUnitName.second.substr(1, statusToUnitName.second.size() - 2) + "\"";
		}
		else {
			name = "\"" + statusToUnitName.second + "\"";
		}
		out << "\t{ " << statusToUnitName.first << ", " << name << "},\n";
	}
	out << "};\n\n";

	out << "unordered_map<int, TerminalId> " << mParseName << "::sWordTypeToId = {\n";
	for (auto val : lalr.wordTypeToId) {
		string enumStr = val.first;
		//if (enumStr == "S`") continue;
		if (enumStr == "$") enumStr = "'\\0'";
		if (enumStr.substr(0, 1) != "'") enumStr = mWordName +  "::" + enumStr;
		out << "\t{ " << enumStr << ", " << to_string(val.second) << "},\n";
	}
	out << "};\n\n";

	out.close();
}

void Produce::produceFunction()
{
	string filePath = mOutputPath + "Func.h";
	ofstream out(filePath, std::ios::trunc);
	
	out.close();
}

void Produce::replaceStr(string& source, const string& from, const string& to) {
	auto n = source.find(from);
	while (n != string::npos) {
		source.replace(n, from.size(), to);
		n = source.find(from);
	}
}

