#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <memory>
#include <vector>

#include "unit.h"

using std::weak_ptr;
using std::shared_ptr;
using std::vector;

class Grammar {
public:
	Grammar(weak_ptr<Unit> parent, vector<weak_ptr<Unit>> children) : mParent(parent), mChildren(children) {
	}

	void setReduceFunctionName(const string& functionName) { mReduceFunctionName = functionName; }
	string getReduceFunctionName() const { return mReduceFunctionName; }

	vector<string> getChildrenTypes() const;

	weak_ptr<Unit> getParent() const { return mParent; }

	weak_ptr<Unit> getChild(size_t index) const {
		if (index >= mChildren.size()) return weak_ptr<Unit>();
		return mChildren[index];
	}

	size_t getChildrenCount() const { return mChildren.size(); }

	bool operator==(const Grammar& grammar) const;

	size_t getHash() const { return (size_t)this; }

	string getGrammarContent() const;

private:
	vector<weak_ptr<Unit>> mChildren;
	weak_ptr<Unit> mParent;
	string mReduceFunctionName;
	bool mIsDoNothingWhenReduce;
};

#endif