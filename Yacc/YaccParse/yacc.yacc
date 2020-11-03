
output:"YaccParse/yacc_parse"
function:"YaccParse/yacc_parse_function"
version:"1.1.1"
parsename:"Parse"
wordname:"YaccWord"
wordheader:"yacc_word.h"
namespace:"YaccParse"
start:"yacc"

{Grammar
yacc
	: yacc part
	| part
	;

part
	: Output String {setOutput}
	| ParseName String {setParseName}
	| WordName String {setWordName}
	| WordHeader String {setWordHeader}
	| Version String {setVersion}
	| Namespace String {setNamespace}
	| Start String {setStart}
	| Function String {setFunction}
	| Segment_Grammar_Left grammarList Segment_Grammar_Right
	| Segment_Code_H_Outside {addCodeHOutSide}
	| Segment_Code_H_Public {addCodeHPublic}
	| Segment_Code_H_Private {addCodeHPrivate}
	| Segment_Code_Cpp {addCodeCpp}
	;

grammarList
	: grammarList grammar
	| grammar
	;

grammar
	: head ':' children_list ';' {addGrammar}
	;

head {Head : generateHead}
	: Identifier
	| Identifier '{' Identifier '}'
	| Identifier '{' '}'
	| Identifier '{' Identifier ':' Identifier '}'
	| Identifier '{' ':' Identifier '}'
	;

children_list {ChildrenList : generateChildrenList}
	: children
	| children '{' Identifier '}'
	| children '{' '}'
	| children_list '|' children
	| children_list '|' children '{' Identifier '}'
	| children_list '|' children '{' '}'
	;

children {Children : generateChildren}
	: unit
	| children unit
	;

unit {UnitItem : generateUnit}
	: Identifier
	| Char
	;
Grammar}


{Code-H-Outside
// <user definition
struct UnitItem {
	enum {
		Identifier, Char
	} type;
	string name;
};

struct Children {
	vector<shared_ptr<UnitItem>> units;
	string functionName;
};

struct ChildrenList {
	vector<shared_ptr<Children>> childrenList;
};

struct Head {
	string head;
	string className;
	string functionName;
};
// user definition>
Code-H-Outside}

{Code-H-Public
	// <user definition
	string& getOutput() { return mOutput; }
	string& getParseName() { return mParseName; }
	string& getWordName() { return mWordName; }
	string& getWordHeader() { return mWordHeader; }
	string& getVersion() { return mVersion; }
	string& getNamespace() { return mNamespace; }
	string& getFunction() { return mFunction; }
	
	string& getCodeHOutSide() { return mCodeHOutside; }
	string& getCodeHPublic() { return mCodeHPublic; }
	string& getCodeHPrivate() { return mCodeHPrivate; }
	string& getCodeCpp() { return mCodeCpp; }
	// user definition>
Code-H-Public}

{Code-H-Private
	// <user definition
	void setOutput(TerminalUnit* unit1, TerminalUnit* unit2);
	void setParseName(TerminalUnit* unit1, TerminalUnit* unit2);
	void setWordName(TerminalUnit* unit1, TerminalUnit* unit2);
	void setWordHeader(TerminalUnit* unit1, TerminalUnit* unit2);
	void setVersion(TerminalUnit* unit1, TerminalUnit* unit2);
	void setNamespace(TerminalUnit* unit1, TerminalUnit* unit2);
	void setStart(TerminalUnit* unit1, TerminalUnit* unit2);
	void setFunction(TerminalUnit* unit1, TerminalUnit* unit2);
	
	void addCodeHOutSide(TerminalUnit* unit1);
	void addCodeHPublic(TerminalUnit* unit1);
	void addCodeHPrivate(TerminalUnit* unit1);
	void addCodeCpp(TerminalUnit* unit1);
	
	void addGrammar(Head* unit1, TerminalUnit* unit2, ChildrenList* unit3, TerminalUnit* unit4);
	Head* generateHead(TerminalUnit* unit1);
	Head* generateHead(TerminalUnit* unit1, TerminalUnit* unit2, TerminalUnit* unit3);
	Head* generateHead(TerminalUnit* unit1, TerminalUnit* unit2, TerminalUnit* unit3, TerminalUnit* unit4);
	Head* generateHead(TerminalUnit* unit1, TerminalUnit* unit2, TerminalUnit* unit3, TerminalUnit* unit4, TerminalUnit* unit5, TerminalUnit* unit6);
	Head* generateHead(TerminalUnit* unit1, TerminalUnit* unit2, TerminalUnit* unit3, TerminalUnit* unit4, TerminalUnit* unit5);
	ChildrenList* generateChildrenList(Children* unit1);
	ChildrenList* generateChildrenList(Children* unit1, TerminalUnit* unit2, TerminalUnit* unit3);
	ChildrenList* generateChildrenList(Children* unit1, TerminalUnit* unit2, TerminalUnit* unit3, TerminalUnit* unit4);
	ChildrenList* generateChildrenList(ChildrenList* unit1, TerminalUnit* unit2, Children* unit3);
	ChildrenList* generateChildrenList(ChildrenList* unit1, TerminalUnit* unit2, Children* unit3, TerminalUnit* unit4, TerminalUnit* unit5);
	ChildrenList* generateChildrenList(ChildrenList* unit1, TerminalUnit* unit2, Children* unit3, TerminalUnit* unit4, TerminalUnit* unit5, TerminalUnit* unit6);
	Children* generateChildren(UnitItem* unit1);
	Children* generateChildren(Children* unit1, UnitItem* unit2);
	UnitItem* generateUnit(TerminalUnit* unit1);

	string mOutput;
	string mParseName;
	string mWordName;
	string mWordHeader;
	string mVersion;
	string mNamespace;
	string mFunction;
	string mCodeHOutside;
	string mCodeHPublic;
	string mCodeHPrivate;
	string mCodeCpp;
	// user definition>
Code-H-Private}

