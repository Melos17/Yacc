#ifndef STATUS_H
#define STATUS_H

#include <unordered_set>
#include <unordered_map>
#include <memory>

#include "item.h"

using std::unordered_set;
using std::unordered_map;
using std::shared_ptr;
using std::pair;

class Status {
public:
	Status(unordered_set<Lr0Item>& items, weak_ptr<Unit> unit);

	Status(unordered_set<shared_ptr<LalrItem>>& items, weak_ptr<Unit> unit) : mItems(items), mUnit(unit) {
	}

	void calculateNextLr0Items(vector<shared_ptr<Unit>>& units);
	unordered_set<Lr0Item>& getNextLr0Items(weak_ptr<Unit> unit);

	void connectToTransitiveItems(Status& status, weak_ptr<Unit> unit);

	bool operator==(unordered_set<Lr0Item>& items) const;

	vector<weak_ptr<Grammar>> getReduce(weak_ptr<Unit> unit) const;

	// auxiliary info : translate status to the last unit in parse stack
	const weak_ptr<Unit>& getUnit() const { return mUnit; }

	void show() const;

	vector<string> getContents() const;
	
private:
	unordered_set<shared_ptr<LalrItem>> mItems;
	unordered_map<weak_ptr<Unit>, vector<pair<shared_ptr<LalrItem>, Lr0Item>>> mTransitiveItemPairs;
	unordered_map<weak_ptr<Unit>, unordered_set<Lr0Item>> mNextItems;
	weak_ptr<Unit> mUnit;
};

#endif