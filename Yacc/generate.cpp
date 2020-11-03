#include <queue>
#include <tuple>

#include "generate.h"

using std::queue;
using std::tuple;

const string YaccGenerate::StartUnit = "S`";
const string YaccGenerate::EndUnit = "$";

YaccGenerate::YaccGenerate() {
	addUnit(StartUnit);
	getUnit(StartUnit)->setIsTerminal(false);
	addUnit(EndUnit);
}

void YaccGenerate::addStartUnit(weak_ptr<Unit> start) {
	weak_ptr<Unit> s = getStartUnit();
	vector<weak_ptr<Unit>> child = { start };
	if (shared_ptr<Unit> _s = s.lock()) {
		shared_ptr<Grammar> grammar = shared_ptr<Grammar>(new Grammar(s, move(child)));
		_s->addGrammar(grammar);
	}
}

void YaccGenerate::addUnit(const string& unitName) {
	Unit* unit = new Unit(unitName);
	shared_ptr<Unit> unitPtr = shared_ptr<Unit>(unit);
	mNameToUnits.emplace(unitName, unitPtr);
	mUnits.emplace_back(unitPtr);
}

LALR YaccGenerate::calculate() {
	for (auto unit : mUnits) {
		unit->calculateClosureAndTranstivity();
		unit->calculateFirstTerminals();
	}
	for (auto unit : mUnits) {
		unit->calculateFollowTerminals();
		unit->calculateNextItemsAndTransitive();
	}
	for (auto unit : mUnits) {
		unit->calculateFollowsInSingleGrammar();
	}

	unordered_set<shared_ptr<LalrItem>> startItems;
	vector<shared_ptr<Grammar>>& grammars = getStartUnit()->getGrammars();
	for (shared_ptr<Grammar>& grammar : grammars) {
		Lr0Item lr0Item(grammar, 0);
		LalrItem* lalrItem = new LalrItem(lr0Item);
		lalrItem->addFollowTerminal(getEndUnit());
		startItems.emplace(lalrItem);
	}

	vector<tuple<StatusId, weak_ptr<Unit>, StatusId>> statusWithUnitToNextStatus;
	Status startStatus(startItems, getEndUnit());
	queue<StatusId> statusIndexQueue;
	mStatus.push_back(startStatus);
	mStatus.back().calculateNextLr0Items(mUnits);
	statusIndexQueue.push(0);

	while (!statusIndexQueue.empty()) {
		StatusId statusIndex = statusIndexQueue.front();
		for (shared_ptr<Unit>& unit : mUnits) {
			unordered_set<Lr0Item> nextLr0Items = mStatus[statusIndex].getNextLr0Items(unit);
			if (nextLr0Items.size() > 0) {
				StatusId nextStatusIndex = 0;
				for (; nextStatusIndex < (int) mStatus.size(); ++nextStatusIndex) {
					if (mStatus[nextStatusIndex] == nextLr0Items) {
						break;
					}
				}
				if (nextStatusIndex == mStatus.size()) {
					mStatus.emplace_back(nextLr0Items, unit);
					mStatus.back().calculateNextLr0Items(mUnits);
					statusIndexQueue.push(nextStatusIndex);
				}
				mStatus[statusIndex].connectToTransitiveItems(mStatus[nextStatusIndex], unit);

				tuple<StatusId, weak_ptr<Unit>, StatusId> val(statusIndex, unit, nextStatusIndex);
				statusWithUnitToNextStatus.emplace_back(val);
			}
		}
		statusIndexQueue.pop();
	}

	for (size_t i = 0; i < mStatus.size(); ++i) {
		Status& status = mStatus[i];
		std::cout << "Item" << i << ":" << std::endl;
		status.show();
	}

	TerminalId terminalId = 0;
	NonterminalId nonterminalId = 0;
	GrammarId grammarId = 0;
	unordered_map<weak_ptr<Unit>, TerminalId> terminalUnitToId;
	unordered_map<weak_ptr<Unit>, NonterminalId> nonterminalUnitToId;
	unordered_map<shared_ptr<Grammar>, GrammarId> grammarToId;
	size_t grammarCount = 0;
	for (auto unit : mUnits) {
		vector<shared_ptr<Grammar>>& grammars = unit->getGrammars();
		for (shared_ptr<Grammar>& grammar : grammars) {
			if (grammarToId.find(grammar) == grammarToId.end()) {
				grammarToId[grammar] = grammarId++;
			}
		}
		grammarCount += unit->getGrammarsCount();
		if (unit == getStartUnit()) continue;
		if (unit->isTerminal()) {
			terminalUnitToId[unit] = terminalId++;
		}
		else {
			nonterminalUnitToId[unit] = nonterminalId++;
		}
	}

	LALR lalr(mStatus.size(), terminalUnitToId.size(), nonterminalUnitToId.size());

	for (shared_ptr<Unit> unit : mUnits) {
		if (!unit->isTerminal()) continue;
		for (size_t statusId = 0; statusId < mStatus.size(); ++statusId) {
			Status& status = mStatus[statusId];
			vector<weak_ptr<Grammar>> grammars = status.getReduce(unit);
			if (grammars.size() > 0) {
				assert(grammars.size() == 1);
				if (shared_ptr<Grammar> grammar = grammars[0].lock()) {
					// Reduce-Reduce conflict
					if (!(lalr.action[statusId][terminalUnitToId[unit]].val == 0 && lalr.action[statusId][terminalUnitToId[unit]].type == Action::Error)) {
						assert(false);
					}
					GrammarId grammarId = grammarToId[grammar];
					lalr.action[statusId][terminalUnitToId[unit]] = { Action::Reduce, grammarId };
				}
			}
		}
	}

	for (tuple<StatusId, weak_ptr<Unit>, StatusId> val : statusWithUnitToNextStatus) {
		StatusId fromStatus = std::get<0>(val);
		weak_ptr<Unit> unit = std::get<1>(val);
		StatusId toStatus = std::get<2>(val);
		if (shared_ptr<Unit> _unit = unit.lock()) {
			if (_unit->isTerminal()) {
				// Shift-Reduce Conflict
				// future : output conflict grammars here.
				if (!(lalr.action[fromStatus][terminalUnitToId[unit]].val == 0 && lalr.action[fromStatus][terminalUnitToId[unit]].type == Action::Error)) {
					// assert(false);
				}
				TerminalId id = terminalUnitToId[unit];
				lalr.action[fromStatus][id] = { Action::Shift, toStatus };
			}
			else {
				NonterminalId id = nonterminalUnitToId[unit];
				lalr.goTo[fromStatus][nonterminalUnitToId[unit]] = toStatus;
			}
		}
	}

	for (size_t i = 0; i < grammarCount; ++i) {
		for (auto& value : grammarToId) {
			if (i == value.second) {
				const shared_ptr<Grammar> grammar = value.first;
				weak_ptr<Unit> parent = grammar->getParent();
				if (shared_ptr<Unit> _parent = parent.lock()) {
					string functionName = grammar->getReduceFunctionName();
					if (functionName.empty()) {
						functionName = _parent->getReduceFunctionName();
					}
					lalr.reduce.emplace_back(nonterminalUnitToId[grammar->getParent()], grammar->getChildrenCount(), functionName,
						_parent->getClassName(), grammar->getChildrenTypes(), grammar->getGrammarContent());
				}
			}
		}
	}

	for (auto& unit : mUnits) {
		if (unit->isTerminal()) {
			lalr.wordTypeToId.emplace_back(unit->getName(), terminalUnitToId[unit]);
		}
	}

	// optimizeReduce(lalr);

	for (size_t i = 0; i < mStatus.size(); ++i) {
		Status& status = mStatus[i];
		if (shared_ptr<Unit> unit = status.getUnit().lock()) {
			lalr.statusToUnitName.emplace_back(make_pair((StatusId)i, unit->getName()));
		}
		lalr.statusInfo.emplace_back(status.getContents());
	}

#ifdef false//_DEBUG
	for (auto& unit : mUnits) {
		if (unit->isTerminal()) {
			lalr.terminalWordName[terminalUnitToId[unit]] = unit->getName();
		}
		else {
			lalr.nonterminalWordName[nonterminalUnitToId[unit]] = unit->getName();
		}
	}
	for (size_t i = 0; i < grammarCount; ++i) {
		for (auto& value : grammarToId) {
			if (i == value.second) {
				lalr.grammars[value.second] = value.first->getGrammarContent();
			}
		}
	}
	lalr.show();
#endif
	return lalr;
}

// Fail code: as we have to look at begin and behind status, it seems impossible to optimizeReduce directly. you have to check more info in real case
// (action need to look at current status and next terminal unit; goto need to look at front status and reduce unit
/*
void YaccGenerate::optimizeReduce(LALR& lalr) {
	for (StatusId status = 0; status < (StatusId) lalr.action.size(); ++status) {
		for (TerminalId tid = 0; tid < (TerminalId) lalr.action[status].size(); ++tid) {
			Action& action = lalr.action[status][tid];
			if (action.type == Action::Reduce) {
				GrammarId firstGrammarId = action.val;
				if(lalr.reduce[firstGrammarId].childrenCount != 1) {
					continue;
				}
				string& functionName = lalr.reduce[firstGrammarId].functionName;
				string& parentType = lalr.reduce[firstGrammarId].parentType;

				if (functionName.empty() || parentType.empty() || parentType != "Expression") { //
					continue;
				}

				NonterminalId firstPid = lalr.reduce[firstGrammarId].parent;
				for (int frontStatus = 0; frontStatus < (int) lalr.goTo.size(); ++frontStatus) {
					// replace with a final parent unit when we do same reduce process
					if (lalr.goTo[frontStatus][firstPid] == -1) {
						continue;
					}
					GrammarId lastGrammarId = firstGrammarId;
					while (1) {
						StatusId toStatus = lalr.goTo[frontStatus][lalr.reduce[lastGrammarId].parent];
						if (toStatus != -1 && lalr.action[toStatus][tid].type == Action::Reduce) {
							GrammarId newGrammarId = lalr.action[toStatus][tid].val;
							if(lalr.reduce[newGrammarId].childrenCount == 1 && lalr.reduce[newGrammarId].functionName == functionName && lalr.reduce[newGrammarId].parentType == parentType) {
								assert(lastGrammarId != newGrammarId);
								lastGrammarId = newGrammarId;
								//break;
								continue;
							}
						}
						break;
					}
					
				}
				
			}
		}
	}
}*/

// Undone : check if there is a Nonterminal Unit can not become Terminal Unit with any grammar
bool YaccGenerate::hasDeadCircleGrammar() {
	weak_ptr<Unit> s = getStartUnit();
	if (shared_ptr<Unit> _s = s.lock()) {
		//shared_ptr<Grammar> grammar = shared_ptr<Grammar>(new Grammar(s, move(child)));
		//_s->addGrammar(grammar);
	}
	return false;
}
