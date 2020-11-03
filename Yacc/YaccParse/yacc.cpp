#include <iostream>
#include <string>
#include <assert.h>

#include "yacc_parse.h"
#include "..\generate.h"

using YaccParse::Parse;
using YaccParse::UnitItem;
using YaccParse::Children;
using YaccParse::ChildrenList;
using YaccParse::Head;
using YaccParse::TerminalUnit;

// part
//	Output String
void Parse::setOutput(TerminalUnit* unit1, TerminalUnit* unit2) {
	mOutput = unit2->word.substr(1, unit2->word.size() - 2);
	delete unit1;
	delete unit2;
}

// part
//	ParseName String
void Parse::setParseName(TerminalUnit* unit1, TerminalUnit* unit2) {
	mParseName = unit2->word.substr(1, unit2->word.size() - 2);
	delete unit1;
	delete unit2;
}

// part
//	WordName String
void Parse::setWordName(TerminalUnit* unit1, TerminalUnit* unit2) {
	mWordName = unit2->word.substr(1, unit2->word.size() - 2);
	delete unit1;
	delete unit2;
}

// part
//	WordName String
void Parse::setWordHeader(TerminalUnit* unit1, TerminalUnit* unit2) {
	mWordHeader = unit2->word.substr(1, unit2->word.size() - 2);
	delete unit1;
	delete unit2;
}

// part
//	Version String
void Parse::setVersion(TerminalUnit* unit1, TerminalUnit* unit2) {
	mVersion = unit2->word.substr(1, unit2->word.size() - 2);
	delete unit1;
	delete unit2;
}

// part
//	Namespace String
void Parse::setNamespace(TerminalUnit* unit1, TerminalUnit* unit2) {
	mNamespace = unit2->word.substr(1, unit2->word.size() - 2);
	delete unit1;
	delete unit2;
}

// part
//	Start String
void Parse::setStart(TerminalUnit* unit1, TerminalUnit* unit2) {
	string unitName = unit2->word.substr(1, unit2->word.size() - 2);
	if (!YaccGenerate::getInstance().hasUnit(unitName)) {
		YaccGenerate::getInstance().addUnit(unitName);
	}
	shared_ptr<Unit> parent = YaccGenerate::getInstance().getUnit(unitName);
	if (YaccGenerate::getInstance().getStartUnit()->getGrammarsCount() == 0) {
		YaccGenerate::getInstance().addStartUnit(parent);
	}
	delete unit1;
	delete unit2;
}

// part
//	Function String
void Parse::setFunction(TerminalUnit* unit1, TerminalUnit* unit2) {
	mFunction = unit2->word.substr(1, unit2->word.size() - 2);
	delete unit1;
	delete unit2;
}


// part
//	Segment_Code_H_Outside
void Parse::addCodeHOutSide(TerminalUnit* unit1) {
	mCodeHOutside += unit1->word.substr(15, unit1->word.size() - 30);;
	delete unit1;
}

// part
//	Segment_Code_H_Public
void Parse::addCodeHPublic(TerminalUnit* unit1) {
	mCodeHPublic += unit1->word.substr(14, unit1->word.size() - 28);;
	delete unit1;
}

// part
//	Segment_Code_H_Private
void Parse::addCodeHPrivate(TerminalUnit* unit1) {
	mCodeHPrivate += unit1->word.substr(15, unit1->word.size() - 30);;
	delete unit1;
}

// part
//	Segment_Code_Cpp
void Parse::addCodeCpp(TerminalUnit* unit1) {
	mCodeCpp += unit1->word.substr(9, unit1->word.size() - 18);;
	delete unit1;
}


// grammar
// head ':' children_list ';'
void Parse::addGrammar(Head* head, TerminalUnit* unit2, ChildrenList* childrenList, TerminalUnit* unit4) {
	string& headName = head->head;
	if (!YaccGenerate::getInstance().hasUnit(headName)) {
		YaccGenerate::getInstance().addUnit(headName);
	}
	shared_ptr<Unit> parent = YaccGenerate::getInstance().getUnit(headName);
	assert(parent->isTerminal()); // check redefinition.
	parent->setIsTerminal(false);
	parent->setClassName(head->className);
	parent->setReduceFunctionName(head->functionName);

	if (YaccGenerate::getInstance().getStartUnit()->getGrammarsCount() == 0) {
		YaccGenerate::getInstance().addStartUnit(parent);
	}
	
	for (shared_ptr<Children> children : childrenList->childrenList) {
		vector<weak_ptr<Unit>> _children;
		for (shared_ptr<UnitItem> unitItem : children->units) {
			if (!YaccGenerate::getInstance().hasUnit(unitItem->name)) {
				YaccGenerate::getInstance().addUnit(unitItem->name);
			}
			weak_ptr<Unit> unit = YaccGenerate::getInstance().getUnit(unitItem->name);
			_children.push_back(unit);
		}
		shared_ptr<Grammar> grammar = shared_ptr<Grammar>(new Grammar(parent, move(_children)));
		grammar->setReduceFunctionName(children->functionName);
		parent->addGrammar(grammar);
	}

	delete head;
	delete unit2;
	delete childrenList;
	delete unit4;
}

// head
// IDENTIFIER
Head* Parse::generateHead(TerminalUnit* unit1) {
	Head* head = new Head();
	head->head = move(unit1->word);
	delete unit1;
	return head;
}

// IDENTIFIER '{' IDENTIFIER '}'
Head* Parse::generateHead(TerminalUnit* unit1, TerminalUnit* unit2, TerminalUnit* unit3, TerminalUnit* unit4) {
	Head* head = new Head();
	head->head = move(unit1->word);
	head->className = move(unit3->word);
	delete unit1;
	delete unit2;
	delete unit3;
	delete unit4;
	return head;
}

// IDENTIFIER '{' '}'
Head* Parse::generateHead(TerminalUnit* unit1, TerminalUnit* unit2, TerminalUnit* unit3) {
	Head* head = new Head();
	head->head = move(unit1->word);
	delete unit1;
	delete unit2;
	delete unit3;
	return head;
}

// IDENTIFIER '{' IDENTIFIER ':' IDENTIFIER '}'
Head* Parse::generateHead(TerminalUnit* unit1, TerminalUnit* unit2, TerminalUnit* unit3, TerminalUnit* unit4, TerminalUnit* unit5, TerminalUnit* unit6) {
	Head* head = new Head();
	head->head = move(unit1->word);
	head->className = move(unit3->word);
	head->functionName = move(unit5->word);
	delete unit1;
	delete unit2;
	delete unit3;
	delete unit4;
	delete unit5;
	delete unit6;
	return head;
}

// IDENTIFIER '{' ':' IDENTIFIER '}'
Head* Parse::generateHead(TerminalUnit* unit1, TerminalUnit* unit2, TerminalUnit* unit3, TerminalUnit* unit4, TerminalUnit* unit5) {
	Head* head = new Head();
	head->head = move(unit1->word);
	head->functionName = move(unit4->word);
	delete unit1;
	delete unit2;
	delete unit4;
	delete unit5;
	return head;
}

// children_list
// children
ChildrenList* Parse::generateChildrenList(Children* unit1) {
	ChildrenList* childrenList = new ChildrenList();
	childrenList->childrenList.emplace_back(unit1);
	return childrenList;
}

// children '{' IDENTIFIER '}'
ChildrenList* Parse::generateChildrenList(Children* unit1, TerminalUnit* unit2, TerminalUnit* unit3, TerminalUnit* unit4) {
	unit1->functionName = move(unit3->word);
	ChildrenList* childrenList = new ChildrenList();
	childrenList->childrenList.emplace_back(unit1);
	delete unit2;
	delete unit3;
	delete unit4;
	return childrenList;
}

// children '{' '}'
ChildrenList* Parse::generateChildrenList(Children* unit1, TerminalUnit* unit2, TerminalUnit* unit3) {
	ChildrenList* childrenList = new ChildrenList();
	childrenList->childrenList.emplace_back(unit1);
	delete unit2;
	delete unit3;
	return childrenList;
}

// children_list '|' children
ChildrenList* Parse::generateChildrenList(ChildrenList* unit1, TerminalUnit* unit2, Children* unit3) {
	unit1->childrenList.emplace_back(unit3);
	delete unit2;
	return unit1;
}

// children_list '|' children '{' IDENTIFIER '}'
ChildrenList* Parse::generateChildrenList(ChildrenList* unit1, TerminalUnit* unit2, Children* unit3, TerminalUnit* unit4, TerminalUnit* unit5, TerminalUnit* unit6) {
	unit3->functionName = move(unit5->word);
	unit1->childrenList.emplace_back(unit3);
	delete unit2;
	delete unit4;
	delete unit5;
	delete unit6;
	return unit1;
}

// children_list '|' children '{' '}'
ChildrenList* Parse::generateChildrenList(ChildrenList* unit1, TerminalUnit* unit2, Children* unit3, TerminalUnit* unit4, TerminalUnit* unit5) {
	unit1->childrenList.emplace_back(unit3);
	delete unit2;
	delete unit4;
	delete unit5;
	return unit1;
}

// children
// unit
Children* Parse::generateChildren(UnitItem* unit1) {
	Children* children = new Children();
	children->units.emplace_back(unit1);
	return children;
}

// children unit
Children* Parse::generateChildren(Children* unit1, UnitItem* unit2) {
	Children* children = new Children();
	unit1->units.emplace_back(unit2);
	return unit1;
}

// unit
// IDENTIFIER
//	CHAR
UnitItem* Parse::generateUnit(TerminalUnit* unit1) {
	UnitItem* unitItem = new UnitItem();
	if (unit1->type == YaccWord::Identifier) {
		unitItem->type = UnitItem::Identifier;
	}
	else if (unit1->type == YaccWord::Char) {
		unitItem->type = UnitItem::Char;
	}
	unitItem->name = unit1->word;
	delete unit1;
	return unitItem;
}
