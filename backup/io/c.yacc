

translation_unit
	: external_declaration
	| translation_unit external_declaration
	;

external_declaration
	: function_definition
	| declaration
	;

function_definition { : generateFunctionDefinition}
	: declaration_specifiers declarator declaration_list compound_statement
	| declaration_specifiers declarator compound_statement
	| declarator declaration_list compound_statement
	| declarator compound_statement
	;

declaration_list {DeclarationList : generateDeclarationList}
	: declaration
	| declaration_list declaration
	;


declaration {Declaration : generateDeclaration}
	: declaration_specifiers ';'
	| declaration_init_declarator_list ';'
	;


declaration_init_declarator_list {Declaration : generateDeclaration}
	: declaration_specifiers init_declarator
	| declaration_init_declarator_list ',' init_declarator
	;







init_declarator {InitDeclarator : generateInitDeclarator}
	: declarator
	| declarator '=' initializer
	;

declaration_specifiers {DeclarationSpecifiers : generateDeclarationSpecifiers}
	: storage_class_specifier
	| storage_class_specifier declaration_specifiers
	| type_specifier {generateDeclarationSpecifiers}
	| type_specifier declaration_specifiers
	| type_qualifier
	| type_qualifier declaration_specifiers
	;

storage_class_specifier {StorageClassSpecifier : generateStorageClassSpecifier}
	: TYPEDEF
	| EXTERN
	| STATIC
	| REGISTER
	;

declarator {Declarator : generateDeclarator}
	: pointer direct_declarator
	| direct_declarator
	;

pointer {Pointer : generatePointer}
	: '*'
	| '*' type_qualifier_list
	| '*' pointer
	| '*' type_qualifier_list pointer
	;

type_specifier {TypeSpecifier : generateTypeSpecifier}
	: VOID
	| CHAR
	| SHORT
	| INT
	| LONG
	| FLOAT
	| DOUBLE
	| SIGNED
	| UNSIGNED
	| struct_or_union_specifier
	| enum_specifier
	| TYPE_NAME
	;

type_qualifier_list {TypeQualifierList : generateTypeQualifierList}
	: type_qualifier
	| type_qualifier_list type_qualifier
	;

type_qualifier {TypeQualifier : generateTypeQualifier}
	: CONST
	| VOLATILE
	;

direct_declarator {DirectDeclarator : generateDirectDeclarator}
	: IDENTIFIER
	| '(' declarator ')'
	| direct_declarator '[' constant_expression ']'
	| direct_declarator '[' ']'
	| direct_declarator '(' parameter_type_list ')'
	| direct_declarator '(' ')'
	;


enum_specifier {EnumSpecifier : generateEnumSpecifier}
	: ENUM '{' enumerator_list '}'
	| ENUM IDENTIFIER '{' enumerator_list '}'
	| ENUM IDENTIFIER
	;

enumerator_list {EnumeratorList : generateEnumeratorList}
	: enumerator
	| enumerator_list ',' enumerator
	;

enumerator {Enumerator : generateEnumerator}
	: IDENTIFIER
	| IDENTIFIER '=' constant_expression
	;



initializer {Initializer : generateInitializer}
	: assignment_expression
	| '{' initializer_list '}'
	| '{' initializer_list ',' '}'
	;

initializer_list {InitializerList : generateInitializerList}
	: initializer
	| initializer_list ',' initializer
	;
	


struct_or_union_specifier {StructOrUnionSpecifier : generateStructOrUnionSpecifier}
	: struct_or_union IDENTIFIER '{' struct_declaration_list '}'
	| struct_or_union '{' struct_declaration_list '}'
	| struct_or_union IDENTIFIER
	;

struct_or_union {StructOrUnion : generateStructOrUnion}
	: STRUCT
	| UNION
	;

struct_declaration_list {StructDeclarationList : generateStructDeclarationList}
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

struct_declaration {StructDeclaration : generateStructDeclaration}
	: specifier_qualifier_list struct_declarator_list ';'
	;

struct_declarator_list {StructDeclaratorList : generateStructDeclaratorList}
	: struct_declarator
	| struct_declarator_list ',' struct_declarator
	;

struct_declarator {StructDeclarator : generateStructDeclarator}
	: declarator
	| ':' constant_expression
	| declarator ':' constant_expression
	;


statement_list {StatementList : generateStatementList}
	: statement
	| statement_list statement
	;

statement {Statement : generateStatement}
	: labeled_statement
	| compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	;

iteration_statement {IterationStatement : generateIterationStatement}
	: WHILE '(' expression ')' statement
	| DO statement WHILE '(' expression ')' ';'
	| FOR '(' expression_statement expression_statement ')' statement
	| FOR '(' expression_statement expression_statement expression ')' statement
	;

selection_statement {SelectionStatement : generateSelectionStatement}
	: IF '(' expression ')' statement
	| IF '(' expression ')' statement ELSE statement
	| SWITCH '(' expression ')' statement
	;

expression_statement {Expression : generateExpressionStatement}
	: ';'
	| expression ';'
	;

labeled_statement {LabeledStatement : generateLabeledStatement}
	: CASE constant_expression ':' statement
	| DEFAULT ':' statement
	| IDENTIFIER ':' statement
	;

compound_statement {CompoundStatement : generateCompoundStatement}
	: '{' '}'
	| '{' statement_list '}'
	| '{' declaration_list '}'
	| '{' declaration_list statement_list '}'
	;

jump_statement {JumpStatement : generateJumpStatement}
	: GOTO IDENTIFIER ';'
	| CONTINUE ';'
	| BREAK ';'
	| RETURN ';'
	| RETURN expression ';'
	;


assignment_operator {TerminalUnit : generateAssignmentOperator}
	: '='
	| MUL_ASSIGN
	| DIV_ASSIGN
	| MOD_ASSIGN
	| ADD_ASSIGN
	| SUB_ASSIGN
	| LEFT_ASSIGN
	| RIGHT_ASSIGN
	| AND_ASSIGN
	| XOR_ASSIGN
	| OR_ASSIGN
	;

unary_operator {TerminalUnit : generateUnaryOperator}
	: '&'
	| '*'
	| '+'
	| '-'
	| '~'
	| '!'
	;


expression {Expression : generateExpression}
	: assignment_expression
	| expression ',' assignment_expression
	;

assignment_expression {AssignmentExpression : generateAssignmentExpression}
	: conditional_expression
	| unary_expression assignment_operator assignment_expression
	;

constant_expression {ConstantExpression : generateConstantExpression}
	: conditional_expression
	;

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

shift_expression {Expression : generateExpression}
	: additive_expression
	| shift_expression LEFT_OP additive_expression
	| shift_expression RIGHT_OP additive_expression
	;

additive_expression {Expression : generateExpression}
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression
	| additive_expression '-' multiplicative_expression
	;

multiplicative_expression {Expression : generateExpression}
	: cast_expression
	| multiplicative_expression '*' cast_expression
	| multiplicative_expression '/' cast_expression
	| multiplicative_expression '%' cast_expression
	;

cast_expression {CastExpression : generateCastExpression}
	: unary_expression
	| '(' type_name ')' cast_expression
	;

unary_expression {UnaryExpression : generateUnaryExpression}
	: postfix_expression
	| INC_OP unary_expression
	| DEC_OP unary_expression
	| unary_operator cast_expression
	| SIZEOF unary_expression
	| SIZEOF '(' type_name ')'
	;

postfix_expression {PostfixExpression : generatePostfixExpression}
	: primary_expression
	| postfix_expression '[' expression ']'
	| postfix_expression '(' ')'
	| postfix_expression '(' argument_expression_list ')'
	| postfix_expression '.' IDENTIFIER
	| postfix_expression PTR_OP IDENTIFIER
	| postfix_expression INC_OP
	| postfix_expression DEC_OP
	;

primary_expression {PrimaryExpression : generatePrimaryExpression}
	: IDENTIFIER
	| CONSTANT
	| STRING_LITERAL
	| '(' expression ')'
	;

argument_expression_list {ArgumentExpressionList : generateArgumentExpressionList}
	: assignment_expression
	| argument_expression_list ',' assignment_expression
	;






parameter_type_list {ParameterTypeList : generateParameterTypeList}
	: parameter_list
	| parameter_list ',' ELLIPSIS
	;

parameter_list {ParameterList : generateParameterList}
	: parameter_declaration
	| parameter_list ',' parameter_declaration
	;

parameter_declaration {ParameterDeclaration : generateParameterDeclaration}
	: declaration_specifiers declarator
	| declaration_specifiers abstract_declarator
	| declaration_specifiers
	;



type_name {TypeName : generateTypeName}
	: specifier_qualifier_list
	| specifier_qualifier_list abstract_declarator
	;

specifier_qualifier_list {SpecifierQualifierList : generateSpecifierQualifierList}
	: type_specifier specifier_qualifier_list
	| type_specifier
	| type_qualifier specifier_qualifier_list
	| type_qualifier
	;

abstract_declarator {AbstractDeclarator : generateAbstractDeclarator}
	: pointer
	| direct_abstract_declarator
	| pointer direct_abstract_declarator
	;

direct_abstract_declarator {DirectAbstractDeclarator : generateDirectAbstractDeclarator}
	: '(' abstract_declarator ')'
	| '[' ']'
	| '[' constant_expression ']'
	| direct_abstract_declarator '[' ']'
	| direct_abstract_declarator '[' constant_expression ']'
	| '(' ')'
	| '(' parameter_type_list ')'
	| direct_abstract_declarator '(' ')'
	| direct_abstract_declarator '(' parameter_type_list ')'
	;

%%


#include "struct.h"
#include "function.h"
