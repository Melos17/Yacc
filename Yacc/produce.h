#ifndef PRODUCE_H
#define PRODUCE_H

#include "generate.h"

using std::string;


class Produce {
public:
	void produceHead(string& codeOutside, string& codePublic, string& codePrivate);
	void produceCpp(LALR& lalr, string& code);
	void produceLalr(LALR& lalr, bool details = false);
	void produceFunction();

	void setOutputPath(const string& str);
	void setParseName(const string& str) { mParseName = str; }
	void setWordName(const string& str) { mWordName = str; }
	void setWordHeader(const string& str) { mWordHeader = str; }
	void setNamespace(const string& str) { mNamespace = str; }
	void setVersion(const string& str) { mVersion = str; }
private:
	string mOutputPath;
	string mHeadName;
	string mParseName;
	string mWordName;
	string mWordHeader;
	string mNamespace;
	string mVersion;
	
	void replaceStr(string& source, const string& from, const string& to);
};


#endif // OUTPUT_H
