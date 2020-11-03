#ifndef PARSE_H
#define PARSE_H

#include <stack>
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <iostream>

#include "clex.h"

using std::stack;
using std::string;
using std::unordered_map;
using std::vector;
using std::shared_ptr;

typedef int StatusId;
typedef int TerminalId;
typedef int NonterminalId;
typedef int GrammarId;

struct Action {
	enum Type {
		Shift,
		Reduce,
		Error,
	};
	Type type;
	size_t val;
};


struct Reduce {
	NonterminalId parent;
	size_t childrenCount;
};

struct Unit {
	int type;
};

struct TerminalUnit : Unit {
	TerminalUnit(int type, string word) {
		this->type = type;
		this->word = word;
	}

	string word;
};

class Parse {
public:
	Parse(string content) : mWord(content) {
	}

	void parse() {
		mStatusStack.emplace(0);
		int id = mWord.GetNextWord();
		while (1) {
			stack<StatusId> statusStack2(mStatusStack);
			stack<StatusId> statusStack3;
			while (!statusStack2.empty()) {
				statusStack3.push(statusStack2.top());
				statusStack2.pop();
			}
			std::cout << id << ":";
			while (!statusStack3.empty()) {
				std::cout << statusStack3.top() << " ";
				statusStack3.pop();
			}

			StatusId status = mStatusStack.top();
			Action action = sAction[status][sWordTypeToId[id]];
			switch (action.type) {
			case Action::Error: {
				std::cout << "Error!" << std::endl;
				return;
			}
			case Action::Reduce: {
				if (id == -1 && action.val == 0) {
					std::cout << "Accept!" << std::endl;
					return;
				}
				std::cout << "Reduce!" << std::endl;
				for (int i = 0; i < sReduce[action.val].childrenCount; ++i) {
					mStatusStack.pop();
				}
				status = mStatusStack.top();
				StatusId newStatus = sGoto[status][sReduce[action.val].parent];
				mStatusStack.emplace(newStatus);
				reduce(action.val);
				break;
			}
			case Action::Shift: {
				std::cout << "Shift!" << std::endl;
				mStatusStack.emplace(action.val);
				id = mWord.GetNextWord();
				TerminalUnit* unit = new TerminalUnit(id, mWord.getCurWord());
				mUnitStack.emplace(unit);
				break;
			}
			}
		}
	}

	void reduce(size_t reduceId);

private:
	CWord mWord;
	stack<Unit*> mUnitStack;
	stack<StatusId> mStatusStack;

	static vector<vector<Action>> sAction;
	static vector<vector<StatusId>> sGoto;
	static vector<Reduce> sReduce;
	static unordered_map<int, TerminalId> sWordTypeToId;
	static unordered_map <StatusId, string> sStatusToUnitName;
};


#endif
