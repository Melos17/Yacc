#ifndef YaccParse_Parse_H
#define YaccParse_Parse_H

#include <assert.h>
#include <stack>
#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include <memory>
#include <iostream>

#include "yacc_word.h"

using std::stack;
using std::string;
using std::unordered_map;
using std::vector;
using std::list;
using std::shared_ptr;
using std::make_shared;
using std::dynamic_pointer_cast;
using std::cout;
using std::endl;

namespace YaccParse {

typedef int StatusId;
typedef int TerminalId;
typedef int NonterminalId;

struct Action {
	enum Type {
		S,
		R,
		E,
	};
	Type type;
	size_t val;
};

struct Reduce {
	NonterminalId parent;
	size_t childrenCount;
};

struct TerminalUnit {
	TerminalUnit(int type, string word) {
		this->type = type;
		this->word = word;
	}

	string word;
	int type;
};

// <user definition
struct UnitItem {
	enum {
		Identifier, Char
	} type;
	string name;
};

struct Children {
	vector<shared_ptr<UnitItem>> units;
	string functionName;
};

struct ChildrenList {
	vector<shared_ptr<Children>> childrenList;
};

struct Head {
	string head;
	string className;
	string functionName;
};
// user definition>

class Parse {
public:
	Parse(string content) : mWord(content) {
	}

	void parse() {
		mStatusStack.emplace(0);
		int id = mWord.GetNextWord();
		while (1) {
			stack<StatusId> statusStack2(mStatusStack);
			list<StatusId> statusList;
			while (!statusStack2.empty()) {
				statusList.emplace_front(statusStack2.top());
				statusStack2.pop();
			}

			// cout << id << ":";
			// for (StatusId id : statusList) {
			// 	cout << id << " ";
			// }
			// printUnit(statusList);

			StatusId status = mStatusStack.top();
			Action action = sAction[status][sWordTypeToId[id]];
			switch (action.type) {
			case Action::E: {
				cout << "Error!" << endl;
				assert(false);
				return;
			}
			case Action::R: {
				if (id == -1 && action.val == 0) {
					//cout << "Accept!" << endl;
					return;
				}
				cout << "Reduce!" << endl;
				for (int i = 0; i < (int)sReduce[action.val].childrenCount; ++i) {
					mStatusStack.pop();
				}
				status = mStatusStack.top();
				StatusId newStatus = sGoto[status][sReduce[action.val].parent];
				mStatusStack.emplace(newStatus);
				reduce(action.val);
				break;
			}
			case Action::S: {
				cout << "Shift!" << id << " " << mWord.getCurWord() << endl;
				mStatusStack.emplace(action.val);
				TerminalUnit* unit = new TerminalUnit(id, mWord.getCurWord());
				mUnitStack.emplace(unit);
				id = mWord.GetNextWord();
				break;
			}
			}
		}
	}

	// <user definition
	string& getOutput() { return mOutput; }
	string& getParseName() { return mParseName; }
	string& getWordName() { return mWordName; }
	string& getWordHeader() { return mWordHeader; }
	string& getVersion() { return mVersion; }
	string& getNamespace() { return mNamespace; }
	string& getFunction() { return mFunction; }
	
	string& getCodeHOutSide() { return mCodeHOutside; }
	string& getCodeHPublic() { return mCodeHPublic; }
	string& getCodeHPrivate() { return mCodeHPrivate; }
	string& getCodeCpp() { return mCodeCpp; }
	// user definition>

private:
	YaccWord mWord;
	stack<void*> mUnitStack;
	stack<StatusId> mStatusStack;

	static vector<vector<Action>> sAction;
	static vector<vector<StatusId>> sGoto;
	static vector<Reduce> sReduce;
	static unordered_map<int, TerminalId> sWordTypeToId;
	static unordered_map <StatusId, string> sStatusToUnitName;
	
	void reduce(size_t reduceId);

	void printUnit(list<StatusId> statusIds) {
		for (StatusId id : statusIds) {
			cout << sStatusToUnitName[id] << " ";
		}
		cout << endl;
	}

	// <user definition
	void setOutput(TerminalUnit* unit1, TerminalUnit* unit2);
	void setParseName(TerminalUnit* unit1, TerminalUnit* unit2);
	void setWordName(TerminalUnit* unit1, TerminalUnit* unit2);
	void setWordHeader(TerminalUnit* unit1, TerminalUnit* unit2);
	void setVersion(TerminalUnit* unit1, TerminalUnit* unit2);
	void setNamespace(TerminalUnit* unit1, TerminalUnit* unit2);
	void setStart(TerminalUnit* unit1, TerminalUnit* unit2);
	void setFunction(TerminalUnit* unit1, TerminalUnit* unit2);
	
	void addCodeHOutSide(TerminalUnit* unit1);
	void addCodeHPublic(TerminalUnit* unit1);
	void addCodeHPrivate(TerminalUnit* unit1);
	void addCodeCpp(TerminalUnit* unit1);
	
	void addGrammar(Head* unit1, TerminalUnit* unit2, ChildrenList* unit3, TerminalUnit* unit4);
	Head* generateHead(TerminalUnit* unit1);
	Head* generateHead(TerminalUnit* unit1, TerminalUnit* unit2, TerminalUnit* unit3);
	Head* generateHead(TerminalUnit* unit1, TerminalUnit* unit2, TerminalUnit* unit3, TerminalUnit* unit4);
	Head* generateHead(TerminalUnit* unit1, TerminalUnit* unit2, TerminalUnit* unit3, TerminalUnit* unit4, TerminalUnit* unit5, TerminalUnit* unit6);
	Head* generateHead(TerminalUnit* unit1, TerminalUnit* unit2, TerminalUnit* unit3, TerminalUnit* unit4, TerminalUnit* unit5);
	ChildrenList* generateChildrenList(Children* unit1);
	ChildrenList* generateChildrenList(Children* unit1, TerminalUnit* unit2, TerminalUnit* unit3);
	ChildrenList* generateChildrenList(Children* unit1, TerminalUnit* unit2, TerminalUnit* unit3, TerminalUnit* unit4);
	ChildrenList* generateChildrenList(ChildrenList* unit1, TerminalUnit* unit2, Children* unit3);
	ChildrenList* generateChildrenList(ChildrenList* unit1, TerminalUnit* unit2, Children* unit3, TerminalUnit* unit4, TerminalUnit* unit5);
	ChildrenList* generateChildrenList(ChildrenList* unit1, TerminalUnit* unit2, Children* unit3, TerminalUnit* unit4, TerminalUnit* unit5, TerminalUnit* unit6);
	Children* generateChildren(UnitItem* unit1);
	Children* generateChildren(Children* unit1, UnitItem* unit2);
	UnitItem* generateUnit(TerminalUnit* unit1);

	string mOutput;
	string mParseName;
	string mWordName;
	string mWordHeader;
	string mVersion;
	string mNamespace;
	string mFunction;
	string mCodeHOutside;
	string mCodeHPublic;
	string mCodeHPrivate;
	string mCodeCpp;
	// user definition>

};

}

#endif