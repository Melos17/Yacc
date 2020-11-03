#ifndef UNIT_H
#define UNIT_H

#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <memory>

#include "item.h"

using std::string;
using std::vector;
using std::stack;
using std::weak_ptr;
using std::shared_ptr;
using std::make_pair;
using std::unordered_map;
using std::unordered_set;
using std::pair;

class Grammar;
class Lr0Item;

class Unit {
	typedef pair<Lr0Item, bool> Lr0ItemAndTranstivity;

public:
	Unit(const string& unitName);

	void setIsTerminal(bool isTerminal) { mIsTerminal = isTerminal; }
	bool isTerminal() const { return mIsTerminal; }
	string getName() const { return mName; }

	void addGrammar(shared_ptr<Grammar> grammar);
	vector<shared_ptr<Grammar>>& getGrammars() { return mGrammars; }
	size_t getGrammarsCount() { return mGrammars.size(); }

	void addFollowTerminal(const weak_ptr<Unit>& unit);
	void addFollowTerminals(unordered_set<weak_ptr<Unit>> units);

	void calculateClosureAndTranstivity();
	void calculateFirstTerminals();
	void calculateFollowTerminals();
	void calculateFollowsInSingleGrammar();
	void calculateNextItemsAndTransitive();

	unordered_set<weak_ptr<Unit>>& getFollowTerminals() { return mFollowTerminals; }
	unordered_set<weak_ptr<Unit>>& getFirstTerminals() { return mFirstTerminals; }
	vector<Lr0ItemAndTranstivity>& getNextItemsAndTransivityByUnit(weak_ptr<Unit> unitId) { return mNextClosureAndTransivity[unitId]; }

	void setClassName(const string& className) { mClassName = className; }
	string getClassName() const { return mClassName; }
	void setReduceFunctionName(const string& reduceFunctionName) { mReduceFunctionName = reduceFunctionName; }
	string getReduceFunctionName() const { return mReduceFunctionName; }

private:
	string mName;
	bool mIsTerminal;
	vector<shared_ptr<Grammar>> mGrammars;

	vector<Lr0ItemAndTranstivity> mClosureAndTranstivity;
	unordered_set<weak_ptr<Unit>> mFirstTerminals;
	unordered_set<weak_ptr<Unit>> mFollowTerminals;
	unordered_map<weak_ptr<Unit>, vector<Lr0ItemAndTranstivity>> mNextClosureAndTransivity;

	string mClassName;
	string mReduceFunctionName;
};

bool operator==(weak_ptr<Unit> unit1, weak_ptr<Unit> unit2);

#endif