
output:"YaccParse/test/yacc_parse"
function:"YaccParse/test/yacc_parse_function"
version:"1.1.1"
parsename:"Parse"
wordname:"YaccWord"
wordheader:"yacc_word.h"
namespace:"YaccParse"
start:"conditional_expression"

{Grammar
conditional_expression {ConditionalExpression : generateConditionalExpression}
	: logical_or_expression
	| logical_or_expression '?' expression ':' conditional_expression
	;

logical_or_expression {Expression : generateExpression}
	: logical_and_expression
	| logical_or_expression OR_OP logical_and_expression
	;

logical_and_expression {Expression : generateExpression}
	: inclusive_or_expression
	| logical_and_expression AND_OP inclusive_or_expression
	;

inclusive_or_expression {Expression : generateExpression}
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression
	;

exclusive_or_expression {Expression : generateExpression}
	: and_expression
	| exclusive_or_expression '^' and_expression
	;

and_expression {Expression : generateExpression}
	: equality_expression
	| and_expression '&' equality_expression
	;

equality_expression {Expression : generateExpression}
	: relational_expression
	| equality_expression EQ_OP relational_expression
	| equality_expression NE_OP relational_expression
	;

relational_expression {Expression : generateExpression}
	: shift_expression
	| relational_expression '<' shift_expression
	| relational_expression '>' shift_expression
	| relational_expression LE_OP shift_expression
	| relational_expression GE_OP shift_expression
	;
Grammar}

