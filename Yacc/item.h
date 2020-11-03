#ifndef ITEM_H
#define ITEM_H

#include <memory>
#include <assert.h>
#include <vector>
#include <iostream>
#include <unordered_set>

using std::weak_ptr;
using std::shared_ptr;
using std::unordered_set;
using std::vector;
using std::string;

class Grammar;
class Unit;
namespace std
{
	template<> struct hash<weak_ptr<Unit>>
	{
		size_t operator()(const weak_ptr<Unit> & item) const noexcept
		{
			if (shared_ptr<Unit> _item = item.lock()) {
				hash<shared_ptr<Unit>> h;
				size_t value = h(_item);
				return value;
			}
			return 0xffffffff;
		}
	};
}

class Lr0Item {
public:
	Lr0Item(weak_ptr<Grammar> grammar, size_t index) : mGrammar(grammar) {
		mIndex = index;
	}

	Lr0Item(const Lr0Item& item) : mGrammar(item.mGrammar) {
		mIndex = item.mIndex;
	}

	weak_ptr<Unit> getNextUnit() const;

	virtual bool operator==(const Lr0Item& item) const {
		return mGrammar.lock() == item.mGrammar.lock() && mIndex == item.mIndex;
	}

	bool hasNext() const;
	Lr0Item getNextItem() const;
	weak_ptr<Grammar> getGrammar() const { return mGrammar; }

	size_t getHash() const;
	bool isEnd() const;
	bool isLastUnit() const;
	virtual void show() const;
	virtual string getContent() const;

private:
	weak_ptr<Grammar> mGrammar;
	size_t mIndex;
};


class LalrItem : public Lr0Item {
public:
	LalrItem(Lr0Item ir0Item) : Lr0Item(ir0Item) {
	}

	LalrItem(Lr0Item ir0Item, unordered_set<weak_ptr<Unit>> followTerminals) : Lr0Item(ir0Item), mFollowTerminals(followTerminals) {
	}

	LalrItem(const LalrItem& item) : Lr0Item(item), mFollowTerminals(item.mFollowTerminals) {
	}

	void addFollowTerminal(weak_ptr<Unit> unit);
	void addFollowTerminals(unordered_set<weak_ptr<Unit>>& units);
	bool isFollowWithUnit(weak_ptr<Unit> unit) { return mFollowTerminals.find(unit) != mFollowTerminals.end(); }

	void addTransitiveItem(weak_ptr<LalrItem> item);

	virtual void show() const;
	virtual string getContent() const;

private:
	vector<weak_ptr<LalrItem>> mTransitiveItems;
	unordered_set<weak_ptr<Unit>> mFollowTerminals;
};


namespace std
{
	template<> struct hash<Lr0Item>
	{
		size_t operator()(const Lr0Item & item) const noexcept
		{
			return item.getHash();
		}
	};
}

#endif