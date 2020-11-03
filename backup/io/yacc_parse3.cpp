#include "yacc.h"
#include "yacc_parse.h"

using YACC::Parse;



vector<vector<YACC::Action>> Parse::sAction = {
	{	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Shift, 	5},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Reduce, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Reduce, 	1},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Shift, 	5},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Shift, 	8},},
	{	{YACC::Action::Reduce, 	3},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	3},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	3},},
	{	{YACC::Action::Error, 	0},	{YACC::Action::Shift, 	9},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	7},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Shift, 	10},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Reduce, 	2},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Reduce, 	4},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	4},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	4},},
	{	{YACC::Action::Reduce, 	5},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Shift, 	12},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Shift, 	15},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Shift, 	16},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Shift, 	17},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Shift, 	18},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	16},	{YACC::Action::Reduce, 	16},	{YACC::Action::Reduce, 	16},	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	16},	{YACC::Action::Reduce, 	16},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	10},	{YACC::Action::Shift, 	12},	{YACC::Action::Shift, 	19},	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	10},	{YACC::Action::Shift, 	15},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	14},	{YACC::Action::Reduce, 	14},	{YACC::Action::Reduce, 	14},	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	14},	{YACC::Action::Reduce, 	14},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	17},	{YACC::Action::Reduce, 	17},	{YACC::Action::Reduce, 	17},	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	17},	{YACC::Action::Reduce, 	17},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Error, 	0},	{YACC::Action::Shift, 	21},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Shift, 	22},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Reduce, 	6},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	6},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	6},},
	{	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Shift, 	12},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Shift, 	15},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Shift, 	24},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	15},	{YACC::Action::Reduce, 	15},	{YACC::Action::Reduce, 	15},	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	15},	{YACC::Action::Reduce, 	15},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Shift, 	25},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	8},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	12},	{YACC::Action::Shift, 	12},	{YACC::Action::Shift, 	26},	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	12},	{YACC::Action::Shift, 	15},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Shift, 	27},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Shift, 	28},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Shift, 	29},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	11},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	11},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	9},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Shift, 	30},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	13},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	13},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},},
};

vector<vector<StatusId>> Parse::sGoto = {
	{	1,	2,	-1,	3,	4,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	6,	7,	4,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	11,	13,	14,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	20,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	23,	14,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	20,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
};

vector<YACC::Reduce> Parse::sReduce = {
	{0,1},
	{0,1},
	{0,2},
	{1,1},
	{1,2},
	{2,1},
	{3,4},
	{4,1},
	{4,4},
	{4,6},
	{5,1},
	{5,4},
	{5,3},
	{5,6},
	{6,1},
	{6,2},
	{7,1},
	{7,1},
};

unordered_map <StatusId, string> Parse::sStatusToUnitName = {
	{0,"$"},
	{1,"yacc"},
	{2,"grammar_list"},
	{3,"grammar"},
	{4,"head"},
	{5,"IDENTIFIER"},
	{6,"code"},
	{7,"grammar"},
	{8,"CODE"},
	{9,":"},
	{10,"{"},
	{11,"children_list"},
	{12,"IDENTIFIER"},
	{13,"children"},
	{14,"unit"},
	{15,"CHAR"},
	{16,"IDENTIFIER"},
	{17,";"},
	{18,"|"},
	{19,"{"},
	{20,"unit"},
	{21,":"},
	{22,"}"},
	{23,"children"},
	{24,"IDENTIFIER"},
	{25,"IDENTIFIER"},
	{26,"{"},
	{27,"}"},
	{28,"}"},
	{29,"IDENTIFIER"},
	{30,"}"},
};

unordered_map<int, TerminalId> Parse::sWordTypeToId = {
	{CWord::IDENTIFIER,3},
	{'|',6},
	{'\0',0},
	{':',1},
	{';',2},
	{'{',4},
	{'}',5},
	{CWord::CHAR,7},
	{CWord::CODE,8},
};

void Parse::reduce(size_t reduceId) {
	switch(reduceId) {
	case 5: {
// code -> CODE 
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		generateCode(unit1);
		delete unit1;
		break;
	}
	case 6: {
// grammar -> head : children_list ; 
		TerminalUnit* unit4 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		ChildrenList* unit3 = (ChildrenList*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit2 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		Head* unit1 = (Head*)mUnitStack.top();
		mUnitStack.pop();
		
		generateGrammar(unit1, unit2, unit3, unit4);
		break;
	}
	case 7: {
// head -> IDENTIFIER 
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		Head* parent = generateHead(unit1);
		mUnitStack.push(parent);
		break;
	}
	case 8: {
// head -> IDENTIFIER { IDENTIFIER } 
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
	case 9: {
// head -> IDENTIFIER { IDENTIFIER : IDENTIFIER } 
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
	case 10: {
// children_list -> children 
		Children* unit1 = (Children*)mUnitStack.top();
		mUnitStack.pop();
		
		ChildrenList* parent = generateChildrenList(unit1);
		mUnitStack.push(parent);
		break;
	}
	case 11: {
// children_list -> children { IDENTIFIER } 
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
	case 12: {
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
	case 13: {
// children_list -> children_list | children { IDENTIFIER } 
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
	case 14: {
// children -> unit 
		UnitItem* unit1 = (UnitItem*)mUnitStack.top();
		mUnitStack.pop();
		
		Children* parent = generateChildren(unit1);
		mUnitStack.push(parent);
		break;
	}
	case 15: {
// children -> children unit 
		UnitItem* unit2 = (UnitItem*)mUnitStack.top();
		mUnitStack.pop();
		Children* unit1 = (Children*)mUnitStack.top();
		mUnitStack.pop();
		
		Children* parent = generateChildren(unit1, unit2);
		mUnitStack.push(parent);
		break;
	}
	case 16: {
// unit -> IDENTIFIER 
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		UnitItem* parent = generateUnit(unit1);
		mUnitStack.push(parent);
		break;
	}
	case 17: {
// unit -> CHAR 
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
