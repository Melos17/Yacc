#include "pch.h"
#include "dfa.h"
#include <iostream>

DFA DfaFactory::produce(string regex, int acceptId) {
	RegexParse parse;
	AbstractTreeNode* tree = parse.parse(regex, acceptId);

	DFA dfa;
	calculateDFA(parse, tree, dfa);
	return dfa;
}


DFA DfaFactory::produce(vector<pair<string, int>> regexes) {
	RegexParse parse;
	AbstractTreeNode* tree = parse.parse(regexes);

	DFA dfa;
	calculateDFA(parse, tree, dfa);
	return dfa;
}


void DfaFactory::calculateDFA(RegexParse& parse, AbstractTreeNode* tree, DFA& dfa) {
	size_t symbolsCount = parse.getSymbols().size();
	dfa.dfa.resize(symbolsCount);

	unordered_map<AbstractTreeLeaf*, vector<AbstractTreeLeaf*>> follows = calculateFollows(tree);
	unordered_set<AbstractTreeLeaf*> statusSet = tree->getFirstPos();
	queue<size_t> uncheckedStatusSetIds;
	uncheckedStatusSetIds.push(getStatusSetId(statusSet));

	while (!uncheckedStatusSetIds.empty()) {
		size_t statusSetId = uncheckedStatusSetIds.front();
		uncheckedStatusSetIds.pop();
		unordered_set<AbstractTreeLeaf*> statusSet = getStatusSet(statusSetId);

		for (size_t symbolsId = 0; symbolsId < symbolsCount; ++symbolsId) {
			unordered_set<AbstractTreeLeaf*> newStatus;
			bool accepted = false;
			int acceptedId = -1;

			for (AbstractTreeLeaf* status : statusSet) {
				if (parse.getSymbol(symbolsId) == status->getSymbols()) {
					for (AbstractTreeLeaf* follow : follows[status]) {
						if (follow->getType() == AbstractTreeNode::End) {
							accepted = true;
							AbstractTreeEndLeaf* endLeaf = (AbstractTreeEndLeaf*)follow;
							if(acceptedId == -1 || acceptedId > endLeaf->getAcceptId()) acceptedId = endLeaf->getAcceptId();
						}
						newStatus.emplace(follow);
					}
				}
			}

			if (newStatus.size() > 0) {
				bool has = hasStatusSet(newStatus);
				size_t newStatusSetId = getStatusSetId(newStatus);
				if (!has) {
					uncheckedStatusSetIds.push(newStatusSetId);
				}
				if (accepted) {
					dfa.acceptStatus[newStatusSetId] = acceptedId;
				}

				if (dfa.dfa[symbolsId].size() <= statusSetId) {
					dfa.dfa[symbolsId].resize(statusSetId + 1, -1);
				}
				dfa.dfa[symbolsId][statusSetId] = (int)newStatusSetId;
			}
		}
	}

	for (vector<int>& column : dfa.dfa) {
		column.resize(getStatusCount(), -1);
	}

	for (size_t symbolsId = 0; symbolsId < symbolsCount; ++symbolsId) {
		SymbolCollection& symbol = parse.getSymbol(symbolsId);
		for (size_t i = 0; i < 128; ++i) {
			if (symbol.test(i)) {
				dfa.symbolIndex[i] = symbolsId;
			}
		}
	}

	/*
	int c = 0;
	for (auto column : dfa.dfa) {
		std::cout << c++ << ": ";
		for (auto val : column) {
			std::cout << val << '\t';
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t symbolsId = 0; symbolsId < symbolsCount; ++symbolsId) {
		std::cout << "!" << symbolsId << ":" << parse.getSymbol(symbolsId).getContent() << std::endl;
	}


	for (size_t i = 0; i < 128; ++i) {
		std::cout << i << ":" << dfa.symbolIndex[i] << ";";
	}
	std::cout << std::endl;
	*/
	
}

unordered_map<AbstractTreeLeaf*, vector<AbstractTreeLeaf*>> DfaFactory::calculateFollows(AbstractTreeNode* tree) {
	unordered_map<AbstractTreeLeaf*, vector<AbstractTreeLeaf*>> follows;

	queue<AbstractTreeNode*> nodes;
	nodes.push(tree);
	while (!nodes.empty()) {
		AbstractTreeNode* node = nodes.front();
		nodes.pop();

		AbstractTreeNode* leftNode = NULL;
		AbstractTreeNode* rightNode = NULL;

		if (node->getType() == AbstractTreeNode::Or) {
			leftNode = node->getLeftNode();
			rightNode = node->getRightNode();
			nodes.push(leftNode);
			nodes.push(rightNode);
		}
		else {
			if (node->getType() == AbstractTreeNode::And) {
				leftNode = node->getLeftNode();
				rightNode = node->getRightNode();
			}
			else if (node->getType() == AbstractTreeNode::Closure || node->getType() == AbstractTreeNode::ClosurePlus) {
				leftNode = node->getNode();
				rightNode = node->getNode();
			}

			if (leftNode != NULL && rightNode != NULL) {
				unordered_set<AbstractTreeLeaf*> lastPosSet = leftNode->getLastPos();
				unordered_set<AbstractTreeLeaf*> firstPosSet = rightNode->getFirstPos();
				for (AbstractTreeLeaf* lastPos : lastPosSet) {
					for (AbstractTreeLeaf* firstPos : firstPosSet) {
						follows[lastPos].push_back(firstPos);

						//std::cout << (lastPos ? lastPos->getSymbols().getContent() : "#") << ">" << (firstPos ? firstPos->getSymbols().getContent() : "#") << std::endl; //
					}
				}
				nodes.push(leftNode);
				nodes.push(rightNode);
			}
		}

	}

	return move(follows);
}


size_t DfaFactory::getStatusSetId(unordered_set<AbstractTreeLeaf*>& status) {
	for (size_t i = 0; i < mStatus.size(); ++i) {
		if (mStatus[i] == status) {
			return i;
		}
	}
	mStatus.push_back(status);
	return mStatus.size() - 1;
}


bool DfaFactory::hasStatusSet(unordered_set<AbstractTreeLeaf*>& status) {
	for (size_t i = 0; i < mStatus.size(); ++i) {
		if (mStatus[i] == status) {
			return true;
		}
	}
	return false;
}
