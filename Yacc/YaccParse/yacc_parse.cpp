#include "yacc_parse.h"
using namespace YaccParse;

void Parse::reduce(size_t reduceId) {
	switch(reduceId) {
	case 3: {
		// part -> Output String 
		TerminalUnit* unit2 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		setOutput(unit1, unit2);
		break;
	}
	case 4: {
		// part -> ParseName String 
		TerminalUnit* unit2 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		setParseName(unit1, unit2);
		break;
	}
	case 5: {
		// part -> WordName String 
		TerminalUnit* unit2 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		setWordName(unit1, unit2);
		break;
	}
	case 6: {
		// part -> WordHeader String 
		TerminalUnit* unit2 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		setWordHeader(unit1, unit2);
		break;
	}
	case 7: {
		// part -> Version String 
		TerminalUnit* unit2 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		setVersion(unit1, unit2);
		break;
	}
	case 8: {
		// part -> Namespace String 
		TerminalUnit* unit2 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		setNamespace(unit1, unit2);
		break;
	}
	case 9: {
		// part -> Start String 
		TerminalUnit* unit2 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		setStart(unit1, unit2);
		break;
	}
	case 10: {
		// part -> Function String 
		TerminalUnit* unit2 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		setFunction(unit1, unit2);
		break;
	}
	case 12: {
		// part -> Segment_Code_H_Outside 
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		addCodeHOutSide(unit1);
		break;
	}
	case 13: {
		// part -> Segment_Code_H_Public 
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		addCodeHPublic(unit1);
		break;
	}
	case 14: {
		// part -> Segment_Code_H_Private 
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		addCodeHPrivate(unit1);
		break;
	}
	case 15: {
		// part -> Segment_Code_Cpp 
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		addCodeCpp(unit1);
		break;
	}
	case 18: {
		// grammar -> head : children_list ; 
		TerminalUnit* unit4 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		ChildrenList* unit3 = (ChildrenList*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit2 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		Head* unit1 = (Head*)mUnitStack.top();
		mUnitStack.pop();
		
		addGrammar(unit1, unit2, unit3, unit4);
		break;
	}
	case 19: {
		// head -> Identifier 
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		Head* parent = generateHead(unit1);
		mUnitStack.push(parent);
		break;
	}
	case 20: {
		// head -> Identifier { Identifier } 
		TerminalUnit* unit4 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit3 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit2 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		Head* parent = generateHead(unit1, unit2, unit3, unit4);
		mUnitStack.push(parent);
		break;
	}
	case 21: {
		// head -> Identifier { } 
		TerminalUnit* unit3 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit2 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		Head* parent = generateHead(unit1, unit2, unit3);
		mUnitStack.push(parent);
		break;
	}
	case 22: {
		// head -> Identifier { Identifier : Identifier } 
		TerminalUnit* unit6 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit5 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit4 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit3 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit2 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		Head* parent = generateHead(unit1, unit2, unit3, unit4, unit5, unit6);
		mUnitStack.push(parent);
		break;
	}
	case 23: {
		// head -> Identifier { : Identifier } 
		TerminalUnit* unit5 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit4 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit3 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit2 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		Head* parent = generateHead(unit1, unit2, unit3, unit4, unit5);
		mUnitStack.push(parent);
		break;
	}
	case 24: {
		// children_list -> children 
		Children* unit1 = (Children*)mUnitStack.top();
		mUnitStack.pop();
		
		ChildrenList* parent = generateChildrenList(unit1);
		mUnitStack.push(parent);
		break;
	}
	case 25: {
		// children_list -> children { Identifier } 
		TerminalUnit* unit4 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit3 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit2 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		Children* unit1 = (Children*)mUnitStack.top();
		mUnitStack.pop();
		
		ChildrenList* parent = generateChildrenList(unit1, unit2, unit3, unit4);
		mUnitStack.push(parent);
		break;
	}
	case 26: {
		// children_list -> children { } 
		TerminalUnit* unit3 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit2 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		Children* unit1 = (Children*)mUnitStack.top();
		mUnitStack.pop();
		
		ChildrenList* parent = generateChildrenList(unit1, unit2, unit3);
		mUnitStack.push(parent);
		break;
	}
	case 27: {
		// children_list -> children_list | children 
		Children* unit3 = (Children*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit2 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		ChildrenList* unit1 = (ChildrenList*)mUnitStack.top();
		mUnitStack.pop();
		
		ChildrenList* parent = generateChildrenList(unit1, unit2, unit3);
		mUnitStack.push(parent);
		break;
	}
	case 28: {
		// children_list -> children_list | children { Identifier } 
		TerminalUnit* unit6 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit5 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit4 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		Children* unit3 = (Children*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit2 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		ChildrenList* unit1 = (ChildrenList*)mUnitStack.top();
		mUnitStack.pop();
		
		ChildrenList* parent = generateChildrenList(unit1, unit2, unit3, unit4, unit5, unit6);
		mUnitStack.push(parent);
		break;
	}
	case 29: {
		// children_list -> children_list | children { } 
		TerminalUnit* unit5 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit4 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		Children* unit3 = (Children*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit2 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		ChildrenList* unit1 = (ChildrenList*)mUnitStack.top();
		mUnitStack.pop();
		
		ChildrenList* parent = generateChildrenList(unit1, unit2, unit3, unit4, unit5);
		mUnitStack.push(parent);
		break;
	}
	case 30: {
		// children -> unit 
		UnitItem* unit1 = (UnitItem*)mUnitStack.top();
		mUnitStack.pop();
		
		Children* parent = generateChildren(unit1);
		mUnitStack.push(parent);
		break;
	}
	case 31: {
		// children -> children unit 
		UnitItem* unit2 = (UnitItem*)mUnitStack.top();
		mUnitStack.pop();
		Children* unit1 = (Children*)mUnitStack.top();
		mUnitStack.pop();
		
		Children* parent = generateChildren(unit1, unit2);
		mUnitStack.push(parent);
		break;
	}
	case 32: {
		// unit -> Identifier 
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		UnitItem* parent = generateUnit(unit1);
		mUnitStack.push(parent);
		break;
	}
	case 33: {
		// unit -> Char 
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		UnitItem* parent = generateUnit(unit1);
		mUnitStack.push(parent);
		break;
	}
	default:
		break;
	}
}
