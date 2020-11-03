#include "yacc.h"
#include "yacc_parse.h"

using YACC::Parse;

vector<vector<YACC::Action>> Parse::sAction = {
	{	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Shift, 	5},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Reduce, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Reduce, 	1},	{YACC::Action::Shift, 	6},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Shift, 	5},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Reduce, 	3},	{YACC::Action::Reduce, 	3},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	3},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Shift, 	8},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	6},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Shift, 	9},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Reduce, 	2},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Reduce, 	4},	{YACC::Action::Reduce, 	4},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	4},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Shift, 	11},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Shift, 	14},},
	{	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Shift, 	15},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Shift, 	16},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Shift, 	17},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	15},	{YACC::Action::Reduce, 	15},	{YACC::Action::Reduce, 	15},	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	15},	{YACC::Action::Reduce, 	15},},
	{	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	9},	{YACC::Action::Shift, 	11},	{YACC::Action::Shift, 	18},	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	9},	{YACC::Action::Shift, 	14},},
	{	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	13},	{YACC::Action::Reduce, 	13},	{YACC::Action::Reduce, 	13},	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	13},	{YACC::Action::Reduce, 	13},},
	{	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	16},	{YACC::Action::Reduce, 	16},	{YACC::Action::Reduce, 	16},	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	16},	{YACC::Action::Reduce, 	16},},
	{	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Shift, 	20},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Shift, 	21},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Reduce, 	5},	{YACC::Action::Reduce, 	5},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	5},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Shift, 	11},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Shift, 	14},},
	{	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Shift, 	23},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	14},	{YACC::Action::Reduce, 	14},	{YACC::Action::Reduce, 	14},	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	14},	{YACC::Action::Reduce, 	14},},
	{	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Shift, 	24},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	7},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	11},	{YACC::Action::Shift, 	11},	{YACC::Action::Shift, 	25},	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	11},	{YACC::Action::Shift, 	14},},
	{	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Shift, 	26},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Shift, 	27},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Shift, 	28},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	10},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	10},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	8},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Shift, 	29},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},},
	{	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	12},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Error, 	0},	{YACC::Action::Reduce, 	12},	{YACC::Action::Error, 	0},},
};

vector<vector<StatusId>> Parse::sGoto = {
	{	1,	2,	3,	4,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	7,	4,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	10,	12,	13,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	19,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	22,	13,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	19,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
};

vector<YACC::Reduce> Parse::sReduce = {
	{0,1},
	{0,1},
	{0,2},
	{1,1},
	{1,2},
	{2,4},
	{3,1},
	{3,4},
	{3,6},
	{4,1},
	{4,4},
	{4,3},
	{4,6},
	{5,1},
	{5,2},
	{6,1},
	{6,1},
};

unordered_map <StatusId, string> Parse::sStatusToUnitName = {
	{0,"$"},
	{1,"yacc"},
	{2,"grammar_list"},
	{3,"grammar"},
	{4,"head"},
	{5,"IDENTIFIER"},
	{6,"CODE"},
	{7,"grammar"},
	{8,":"},
	{9,"{"},
	{10,"children_list"},
	{11,"IDENTIFIER"},
	{12,"children"},
	{13,"unit"},
	{14,"CHAR"},
	{15,"IDENTIFIER"},
	{16,";"},
	{17,"|"},
	{18,"{"},
	{19,"unit"},
	{20,":"},
	{21,"}"},
	{22,"children"},
	{23,"IDENTIFIER"},
	{24,"IDENTIFIER"},
	{25,"{"},
	{26,"}"},
	{27,"}"},
	{28,"IDENTIFIER"},
	{29,"}"},
};

unordered_map<int, TerminalId> Parse::sWordTypeToId = {
	{CWord::IDENTIFIER,4},
	{'|',7},
	{'\0',0},
	{CWord::CODE,1},
	{':',2},
	{';',3},
	{'{',5},
	{'}',6},
	{CWord::CHAR,8},
};

void Parse::reduce(size_t reduceId) {
	switch(reduceId) {
	case 1: {
// yacc -> grammar_list 
		GrammarList* unit1 = (GrammarList*)mUnitStack.top();
		mUnitStack.pop();
		
		generateYacc(unit1);
		delete unit1;
		break;
	}
	case 2: {
// yacc -> grammar_list CODE 
		TerminalUnit* unit2 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		GrammarList* unit1 = (GrammarList*)mUnitStack.top();
		mUnitStack.pop();
		
		generateYacc(unit1, unit2);
		delete unit2;
		delete unit1;
		break;
	}
	case 3: {
// grammar_list -> grammar 
		GrammarItem* unit1 = (GrammarItem*)mUnitStack.top();
		mUnitStack.pop();
		
		GrammarList* parent = generateGrammarList(unit1);
		mUnitStack.push(parent);
		break;
	}
	case 4: {
// grammar_list -> grammar_list grammar 
		GrammarItem* unit2 = (GrammarItem*)mUnitStack.top();
		mUnitStack.pop();
		GrammarList* unit1 = (GrammarList*)mUnitStack.top();
		mUnitStack.pop();
		
		GrammarList* parent = generateGrammarList(unit1, unit2);
		mUnitStack.push(parent);
		break;
	}
	case 5: {
// grammar -> head : children_list ; 
		TerminalUnit* unit4 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		ChildrenList* unit3 = (ChildrenList*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit2 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		Head* unit1 = (Head*)mUnitStack.top();
		mUnitStack.pop();
		
		GrammarItem* parent = generateGrammar(unit1, unit2, unit3, unit4);
		mUnitStack.push(parent);
		break;
	}
	case 6: {
// head -> IDENTIFIER 
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		Head* parent = generateHead(unit1);
		mUnitStack.push(parent);
		break;
	}
	case 7: {
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
	case 8: {
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
	case 9: {
// children_list -> children 
		Children* unit1 = (Children*)mUnitStack.top();
		mUnitStack.pop();
		
		ChildrenList* parent = generateChildrenList(unit1);
		mUnitStack.push(parent);
		break;
	}
	case 10: {
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
	case 11: {
// children_list -> children_list \ children 
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
	case 12: {
// children_list -> children_list \ children { IDENTIFIER } 
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
	case 13: {
// children -> unit 
		UnitItem* unit1 = (UnitItem*)mUnitStack.top();
		mUnitStack.pop();
		
		Children* parent = generateChildren(unit1);
		mUnitStack.push(parent);
		break;
	}
	case 14: {
// children -> children unit 
		UnitItem* unit2 = (UnitItem*)mUnitStack.top();
		mUnitStack.pop();
		Children* unit1 = (Children*)mUnitStack.top();
		mUnitStack.pop();
		
		Children* parent = generateChildren(unit1, unit2);
		mUnitStack.push(parent);
		break;
	}
	case 15: {
// unit -> IDENTIFIER 
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		Unit* parent = generateUnit(unit1);
		mUnitStack.push(parent);
		break;
	}
	case 16: {
// unit -> CHAR 
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		Unit* parent = generateUnit(unit1);
		mUnitStack.push(parent);
		break;
	}
	default:
		break;
	}
}
