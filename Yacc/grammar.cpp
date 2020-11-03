#include "grammar.h"
#include "unit.h"


vector<string> Grammar::getChildrenTypes() const {
	vector<string> childrenType;
	for (size_t i = 0; i < getChildrenCount(); ++i) {
		weak_ptr<Unit> child = getChild(i);
		if (shared_ptr<Unit> _child = child.lock()) {
			if (_child->isTerminal()) {
				childrenType.emplace_back("TerminalUnit");
			}
			else {
				childrenType.emplace_back(_child->getClassName());
			}
		}
	}
	return childrenType;
}

bool Grammar::operator==(const Grammar& grammar) const {
	return mParent == grammar.mParent && mChildren == grammar.mChildren;
}

string Grammar::getGrammarContent() const {
	string content;
	if (shared_ptr<Unit> _parent = mParent.lock()) {
		content += _parent->getName() + " -> ";
		for (size_t i = 0; i < mChildren.size(); ++i) {
			if (shared_ptr<Unit> child = mChildren[i].lock()) {
				if (child->getName()[0] == '\'') {
					content += child->getName().substr(1, 1) + " ";
				}
				else {
					content += child->getName() + " ";
				}
			}
		}
	}
	return content;
}