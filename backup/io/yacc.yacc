
yacc
	: grammar_list {generateYacc}
	| grammar_list code {generateYacc}
	;

grammar_list
	: grammar
	| grammar_list grammar
	;

grammar
	: head ':' children_list ';' {generateGrammar}
	;

head {Head}
	: IDENTIFIER {generateHead}
	| IDENTIFIER '{' IDENTIFIER '}' {generateHead}
	| IDENTIFIER '{' IDENTIFIER ':' IDENTIFIER '}' {generateHead}
	;

children_list {ChildrenList}
	: children {generateChildrenList}
	| children '{' IDENTIFIER '}' {generateChildrenList}
	| children_list '|' children {generateChildrenList}
	| children_list '|' children '{' IDENTIFIER '}' {generateChildrenList}
	;

children {Children}
	: unit {generateChildren}
	| children unit {generateChildren}
	;

unit {UnitItem}
	: IDENTIFIER {generateUnit}
	| CHAR {generateUnit}
	;

code
	: CODE {generateCode}
	;