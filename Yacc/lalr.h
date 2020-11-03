#ifndef LALR_H
#define LALR_H

#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

using std::string;
using std::unordered_map;
using std::vector;
using std::pair;

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

	Action() {
		this->type = Error;
		this->val = 0;
	}

	Action(Type type, int val) {
		this->type = type;
		this->val = val;
	}

	void show() const;

	Type type;
	size_t val;
};


struct Reduce {
	Reduce(NonterminalId parent, size_t childrenCount, const string& functionName, const string& parentType, const vector<string>& childrenType, const string& content) {
		this->parent = parent;
		this->childrenCount = childrenCount;
		this->functionName = functionName;
		this->parentType = parentType;
		this->childrenType = childrenType;
		this->content = content;
	}

	NonterminalId parent;
	size_t childrenCount;

	// auxiliary info
	string functionName;
	string parentType;
	vector<string> childrenType;
	string content;
};

struct LALR {
	LALR(size_t statusCount, size_t terminalCount, size_t nonterminalCount) : action(statusCount, vector<Action>(terminalCount)), goTo(statusCount, vector<StatusId>(nonterminalCount, -1)) {
	}

	vector<vector<Action>> action;
	vector<vector<StatusId>> goTo;
	vector<pair<string, TerminalId>> wordTypeToId;
	vector<Reduce> reduce;

	// auxiliary info
	vector<pair<StatusId, string>> statusToUnitName;
	vector<vector<string>> statusInfo;

#ifdef _DEBUG
	unordered_map<TerminalId, string> terminalWordName;
	unordered_map<NonterminalId, string> nonterminalWordName;
	unordered_map<GrammarId, string> grammars;

	void show() const;
#endif
};

#endif