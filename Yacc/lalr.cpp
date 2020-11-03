#include "lalr.h"

void Action::show() const {
	if (this->type == Error && this->val == 0) {
		std::cout << "--";
		return;
	}
	switch (this->type) {
	case Shift:
		std::cout << "s";
		break;
	case Reduce:
		std::cout << "r";
		break;
	case Error:
		std::cout << "e";
		break;
	}
	std::cout << this->val;
}

#ifdef _DEBUG

void LALR::show() const {
	std::cout << "Action:" << std::endl;
	for (size_t i = 0; i < terminalWordName.size(); ++i) {
		auto it = terminalWordName.find(i);
		if (it != terminalWordName.end()) {
			std::cout << "\t" << it->second;
		}
	}
	std::cout << std::endl;
	for (auto& column : action) {
		for (auto& action : column) {
			std::cout << "\t";
			action.show();
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Goto:" << std::endl;
	for (size_t i = 0; i < nonterminalWordName.size(); ++i) {
		auto it = nonterminalWordName.find(i);
		if (it != nonterminalWordName.end()) {
			std::cout << "\t" << it->second;
		}
	}
	std::cout << std::endl;
	for (auto& column : goTo) {
		for (auto& statusId : column) {
			if (statusId != -1) {
				std::cout << "\t" << statusId;
			}
			else {
				std::cout << "\t--";
			}
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Grammar:" << std::endl;
	for (auto& grammar : grammars) {
		std::cout << grammar.first << ":" << grammar.second << std::endl;
	}
}

#endif
