#include "status.h"
#include "grammar.h"

Status::Status(unordered_set<Lr0Item>& items, weak_ptr<Unit> unit) : mUnit(unit) {
	for (Lr0Item lr0Item : items) {
		shared_ptr<LalrItem> lalrItem = shared_ptr<LalrItem>(new LalrItem(lr0Item));
		if (shared_ptr<Grammar> grammar = lalrItem->getGrammar().lock()) {
			if (shared_ptr<Unit> unit = grammar->getParent().lock()) {
				lalrItem->addFollowTerminals(unit->getFollowTerminals());
			}
		}
		mItems.emplace(lalrItem);
	}
}

void Status::calculateNextLr0Items(vector<shared_ptr<Unit>>& units) {
	for (shared_ptr<Unit>& unit : units) {
		for (const shared_ptr<LalrItem>& item : mItems) {
			if (!item->hasNext()) continue;
			shared_ptr<Unit> nextUnit = item->getNextUnit().lock();
			if (nextUnit == unit) {
				Lr0Item nextItem = item->getNextItem();
				mTransitiveItemPairs[unit].push_back(make_pair(item, nextItem));
				mNextItems[unit].emplace(nextItem);
			}
			vector<pair<Lr0Item, bool>>& itemsAndTransitive = nextUnit->getNextItemsAndTransivityByUnit(unit);
			for (pair<Lr0Item, bool>& nextItemAndTransitive : itemsAndTransitive) {
				mNextItems[unit].emplace(nextItemAndTransitive.first);
				if (nextItemAndTransitive.second && item->isLastUnit()) {
					mTransitiveItemPairs[unit].push_back(make_pair(item, nextItemAndTransitive.first));
				}
			}
		}
	}
}

unordered_set<Lr0Item>& Status::getNextLr0Items(weak_ptr<Unit> unit) {
	return mNextItems[unit];
}

void Status::connectToTransitiveItems(Status& status, weak_ptr<Unit> unit) {
	vector<pair<shared_ptr<LalrItem>, Lr0Item>>& pairs = mTransitiveItemPairs[unit];
	for (auto& pair : pairs) {
		for (const shared_ptr<LalrItem>& item : status.mItems) {
			if (*item == pair.second) {
				pair.first->addTransitiveItem(item);
			}
		}
	}
}

bool Status::operator==(unordered_set<Lr0Item>& items) const {
	if (items.size() != mItems.size()) {
		return false;
	}
	for (shared_ptr<LalrItem> item : mItems) {
		if (items.find(*item) == items.end()) {
			return false;
		}
	}
	return true;
}

vector<weak_ptr<Grammar>> Status::getReduce(weak_ptr<Unit> unit) const {
	vector<weak_ptr<Grammar>> grammars;
	for (const shared_ptr<LalrItem>& item : mItems) {
		if (item->isEnd() && item->isFollowWithUnit(unit)) {
			grammars.push_back(item->getGrammar());
		}
	}
	return grammars;
}

void Status::show() const {
	for (auto& s : mItems) {
		s->show();
	}
	std::cout << std::endl;
}

vector<string> Status::getContents() const {
	vector<string> contents;
	for (const shared_ptr<LalrItem>& item : mItems) {
		contents.emplace_back(item->getContent());
	}
	return contents;
}
