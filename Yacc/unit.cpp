#include <queue>

#include "unit.h"
#include "item.h"
#include "grammar.h"

using std::queue;

Unit::Unit(const string& unitName) : mName(unitName) {
	mIsTerminal = true;
}

void Unit::addGrammar(shared_ptr<Grammar> grammar) {
	assert(grammar->getChildrenCount() > 0);
	if (find(mGrammars.begin(), mGrammars.end(), grammar) == mGrammars.end()) {
		mGrammars.push_back(grammar);
	}
}

void Unit::addFollowTerminal(const weak_ptr<Unit>& unit) {
	if (shared_ptr<Unit> _unit = unit.lock()) {
		assert(_unit->isTerminal());
	}
	if (mFollowTerminals.find(unit) == mFollowTerminals.end()) {
		mFollowTerminals.emplace(unit);
	}
}

void Unit::addFollowTerminals(unordered_set<weak_ptr<Unit>> units) {
	for (const weak_ptr<Unit>& terminal : units) {
		addFollowTerminal(terminal);
	}
}

// calculate closure Lr0Item and the transtivity which means it will transfer following terminal units to closure Lr0Item or not
void Unit::calculateClosureAndTranstivity() {
	queue<pair<Lr0Item, bool>> itemAndTranstivityQueue;
	for (shared_ptr<Grammar>& grammar : mGrammars) {
		Lr0Item item(grammar, 0);
		bool transtivity = grammar->getChildrenCount() == 1;
		mClosureAndTranstivity.emplace_back(make_pair(item, true));
		itemAndTranstivityQueue.push(make_pair(item, transtivity));
	}

	while (!itemAndTranstivityQueue.empty()) {
		Lr0Item item = itemAndTranstivityQueue.front().first;
		bool transivity = itemAndTranstivityQueue.front().second;
		itemAndTranstivityQueue.pop();
		if (shared_ptr<Unit> unit = item.getNextUnit().lock()) {
			vector<shared_ptr<Grammar>>& grammars = unit->getGrammars();
			for (auto& grammar : grammars) {
				Lr0Item newItem(grammar, 0);
				auto lamb = [&](Lr0ItemAndTranstivity& v) {return v.first == newItem; };
				auto it = find_if(mClosureAndTranstivity.begin(), mClosureAndTranstivity.end(), lamb);
				if (it == mClosureAndTranstivity.end()) {
					mClosureAndTranstivity.emplace_back(make_pair(newItem, transivity));
					itemAndTranstivityQueue.push(make_pair(newItem, transivity && grammar->getChildrenCount() == 1));
				}
				else {
					// if there is an old item without transivity and we find a same item with transivity, need to calculate following item again
					if (!it->second && transivity) {
						it->second = true;
						if (grammar->getChildrenCount() == 1) {
							itemAndTranstivityQueue.push(make_pair(newItem, true));
						}
					}
				}
			}
		}
	}
}

void Unit::calculateFirstTerminals() {
	for (Lr0ItemAndTranstivity& itemAndTransivity : mClosureAndTranstivity) {
		weak_ptr<Unit> unit = itemAndTransivity.first.getNextUnit();
		if (shared_ptr<Unit> _unit = unit.lock()) {
			if (_unit->isTerminal()) {
				mFirstTerminals.emplace(unit);
			}
		}
	}
}

// search grammars to calculate the following terminal units
void Unit::calculateFollowTerminals() {
	for (shared_ptr<Grammar>& grammar : mGrammars) {
		weak_ptr<Unit> last = grammar->getChild(0);
		for (size_t i = 1; i < grammar->getChildrenCount(); ++i) {
			weak_ptr<Unit> cur = grammar->getChild(i);
			shared_ptr<Unit> _last = last.lock();
			shared_ptr<Unit> _cur = cur.lock();
			if (_last && _cur && !_last->isTerminal()) {
				if (_cur->isTerminal()) {
					_last->addFollowTerminal(cur);
				}
				else {
					unordered_set<weak_ptr<Unit>>& firstTerminals = _cur->getFirstTerminals();
					_last->addFollowTerminals(firstTerminals);
				}
			}
			last = cur;
		}
	}
}

// bug fixed : because we transfer following terminal units by LalrItem and does not save Non-core Item,
// we have to calculate following terminal units of those case whose grammar has only one non-terminal unit
void Unit::calculateFollowsInSingleGrammar() {
	for (shared_ptr<Grammar>& grammar : mGrammars) {
		if (grammar->getChildrenCount() == 1) {
			weak_ptr<Unit> unit = grammar->getChild(0);
			if (shared_ptr<Unit> _unit = unit.lock()) {
				if (_unit->isTerminal()) { continue; }
				_unit->addFollowTerminals(getFollowTerminals());
				_unit->calculateFollowsInSingleGrammar();
			}
		}
	}
}

void Unit::calculateNextItemsAndTransitive() {
	for (Lr0ItemAndTranstivity& itemAndTransivity : mClosureAndTranstivity) {
		Lr0Item& item = itemAndTransivity.first;
		Lr0Item nextItem = item.getNextItem();
		mNextClosureAndTransivity[item.getNextUnit()].push_back(make_pair(nextItem, itemAndTransivity.second));
	}
}

bool operator==(weak_ptr<Unit> unit1, weak_ptr<Unit> unit2) {
	return unit1.lock() == unit2.lock();
}
