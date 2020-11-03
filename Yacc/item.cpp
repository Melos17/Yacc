#include "item.h"
#include "grammar.h"
#include "unit.h"


weak_ptr<Unit> Lr0Item::getNextUnit() const {
	if (shared_ptr<Grammar> grammar = mGrammar.lock()) {
		return grammar->getChild(mIndex);
	}
	assert(false);
	return weak_ptr<Unit>();
}

bool Lr0Item::hasNext() const {
	if (shared_ptr<Grammar> grammar = mGrammar.lock()) {
		return mIndex < grammar->getChildrenCount();
	}
	return false;
}

Lr0Item Lr0Item::getNextItem() const {
	assert(hasNext());
	return Lr0Item(mGrammar, mIndex + 1);
}

size_t Lr0Item::getHash() const {
	size_t hash = 534381 + mIndex;
	if (shared_ptr<Grammar> grammar = mGrammar.lock()) {
		hash += 31 * hash + grammar->getHash();
	}
	return hash;
}

bool Lr0Item::isEnd() const {
	if (shared_ptr<Grammar> grammar = mGrammar.lock()) {
		return grammar->getChildrenCount() == mIndex;
	}
	return false;
}

bool Lr0Item::isLastUnit() const {
	if (shared_ptr<Grammar> grammar = mGrammar.lock()) {
		return grammar->getChildrenCount() - 1 == mIndex;
	}
	return false;
}

void Lr0Item::show() const {
	if (shared_ptr<Grammar> grammar = mGrammar.lock()) {
		weak_ptr<Unit>  parent = grammar->getParent();
		if (shared_ptr<Unit> _parent = parent.lock()) {
			std::cout << _parent->getName() << " -> ";
			for (size_t i = 0; i < grammar->getChildrenCount() + 1; ++i) {
				if (mIndex == i) {
					std::cout << "^";
				}
				if (i == grammar->getChildrenCount()) break;
				if (shared_ptr<Unit> child = grammar->getChild(i).lock()) {
					if (child->getName()[0] == '\'') {
						std::cout << child->getName().substr(1, 1) << " ";
					}
					else {
						std::cout << child->getName() << " ";
					}
				}
			}
		}
	}
}

string Lr0Item::getContent() const {
	string content;
	if (shared_ptr<Grammar> grammar = mGrammar.lock()) {
		weak_ptr<Unit>  parent = grammar->getParent();
		if (shared_ptr<Unit> _parent = parent.lock()) {
			content += _parent->getName() + " -> ";
			for (size_t i = 0; i < grammar->getChildrenCount() + 1; ++i) {
				if (mIndex == i) {
					content += "^";
				}
				if (i == grammar->getChildrenCount()) break;
				if (shared_ptr<Unit> child = grammar->getChild(i).lock()) {
					if (child->getName()[0] == '\'') {
						content += child->getName().substr(1, 1) + " ";
					}
					else {
						content += child->getName() + " ";
					}
				}
			}
		}
	}
	return content;
}



bool operator==(weak_ptr<LalrItem> item1, weak_ptr<LalrItem> item2) {
	return item1.lock() == item2.lock();
}

void LalrItem::addFollowTerminal(weak_ptr<Unit> unit) {
	if (shared_ptr<Unit> _unit = unit.lock()) {
		assert(_unit->isTerminal());
	}
	if (mFollowTerminals.find(unit) == mFollowTerminals.end()) {
		mFollowTerminals.emplace(unit);
	}
}

void LalrItem::addFollowTerminals(unordered_set<weak_ptr<Unit>>& units) {
	size_t oriSize = mFollowTerminals.size();
	mFollowTerminals.insert(units.begin(), units.end());
	if (mFollowTerminals.size() != oriSize) {
		for (weak_ptr<LalrItem>& transitiveItem : mTransitiveItems) {
			if (shared_ptr<LalrItem> _transitiveItem = transitiveItem.lock()) {
				_transitiveItem->addFollowTerminals(units);
			}
		}
	}
}

void LalrItem::show() const {
	Lr0Item::show();
	std::cout << " [ ";
	for (weak_ptr<Unit> unit : mFollowTerminals) {
		if (shared_ptr<Unit> _unit = unit.lock()) {
			std::cout << _unit->getName() << " ";
		}
	}
	std::cout << "]";
	std::cout << std::endl;
}

string LalrItem::getContent() const {
	string content = Lr0Item::getContent();
	content += " [ ";
	for (weak_ptr<Unit> unit : mFollowTerminals) {
		if (shared_ptr<Unit> _unit = unit.lock()) {
			content += _unit->getName() + " ";
		}
	}
	content += "]";
	return content;
}

void LalrItem::addTransitiveItem(weak_ptr<LalrItem> item) {
	if (find(mTransitiveItems.begin(), mTransitiveItems.end(), item) == mTransitiveItems.end()) {
		mTransitiveItems.emplace_back(item);
	}
	if (shared_ptr<LalrItem> _item = item.lock()) {
		_item->addFollowTerminals(mFollowTerminals);
	}
}
