

translation_unit
	: external_declaration
	| translation_unit external_declaration
	;

external_declaration
	: function_definition
	| declaration
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement {generateFunctionDefinition}
	| declaration_specifiers declarator compound_statement {generateFunctionDefinition}
	| declarator declaration_list compound_statement {generateFunctionDefinition}
	| declarator compound_statement {generateFunctionDefinition}
	;

declaration_list {DeclarationList}
	: declaration {generateDeclarationList}
	| declaration_list declaration {generateDeclarationList}
	;


declaration {Declaration}
	: declaration_specifiers ';' {generateDeclaration}
	| declaration_init_declarator_list ';' {generateDeclaration}
	;


declaration_init_declarator_list {Declaration}
	: declaration_specifiers init_declarator {generateDeclaration}
	| declaration_init_declarator_list ',' init_declarator {generateDeclaration}
	;







init_declarator {InitDeclarator}
	: declarator {generateInitDeclarator}
	| declarator '=' initializer {generateInitDeclarator}
	;

declaration_specifiers {DeclarationSpecifiers}
	: storage_class_specifier {generateDeclarationSpecifiers}
	| storage_class_specifier declaration_specifiers {generateDeclarationSpecifiers}
	| type_specifier {generateDeclarationSpecifiers}
	| type_specifier declaration_specifiers {generateDeclarationSpecifiers}
	| type_qualifier {generateDeclarationSpecifiers}
	| type_qualifier declaration_specifiers {generateDeclarationSpecifiers}
	;

storage_class_specifier {StorageClassSpecifier}
	: TYPEDEF {generateStorageClassSpecifier}
	| EXTERN {generateStorageClassSpecifier}
	| STATIC {generateStorageClassSpecifier}
	| REGISTER {generateStorageClassSpecifier}
	;

declarator {Declarator}
	: pointer direct_declarator {generateDeclarator}
	| direct_declarator {generateDeclarator}
	;

pointer {Pointer}
	: '*' {generatePointer}
	| '*' type_qualifier_list {generatePointer}
	| '*' pointer {generatePointer}
	| '*' type_qualifier_list pointer {generatePointer}
	;

type_specifier {TypeSpecifier}
	: VOID {generateTypeSpecifier}
	| CHAR {generateTypeSpecifier}
	| SHORT {generateTypeSpecifier}
	| INT {generateTypeSpecifier}
	| LONG {generateTypeSpecifier}
	| FLOAT {generateTypeSpecifier}
	| DOUBLE {generateTypeSpecifier}
	| SIGNED {generateTypeSpecifier}
	| UNSIGNED {generateTypeSpecifier}
	| struct_or_union_specifier {generateTypeSpecifier}
	| enum_specifier {generateTypeSpecifier}
	| TYPE_NAME {generateTypeSpecifier}
	;

type_qualifier_list {TypeQualifierList}
	: type_qualifier {generateTypeQualifierList}
	| type_qualifier_list type_qualifier {generateTypeQualifierList}
	;

type_qualifier {TypeQualifier}
	: CONST {generateTypeQualifier}
	| VOLATILE {generateTypeQualifier}
	;

direct_declarator {DirectDeclarator}
	: IDENTIFIER {generateDirectDeclarator}
	| '(' declarator ')' {generateDirectDeclarator}
	| direct_declarator '[' constant_expression ']' {generateDirectDeclarator}
	| direct_declarator '[' ']' {generateDirectDeclarator}
	| direct_declarator '(' parameter_type_list ')' {generateDirectDeclarator}
	| direct_declarator '(' ')' {generateDirectDeclarator}
	;


enum_specifier {EnumSpecifier}
	: ENUM '{' enumerator_list '}' {generateEnumSpecifier}
	| ENUM IDENTIFIER '{' enumerator_list '}' {generateEnumSpecifier}
	| ENUM IDENTIFIER {generateEnumSpecifier}
	;

enumerator_list {EnumeratorList}
	: enumerator {generateEnumeratorList}
	| enumerator_list ',' enumerator {generateEnumeratorList}
	;

enumerator {Enumerator}
	: IDENTIFIER {generateEnumerator}
	| IDENTIFIER '=' constant_expression {generateEnumerator}
	;



initializer {Initializer}
	: assignment_expression {generateInitializer}
	| '{' initializer_list '}' {generateInitializer}
	| '{' initializer_list ',' '}' {generateInitializer}
	;

initializer_list {InitializerList}
	: initializer {generateInitializerList}
	| initializer_list ',' initializer {generateInitializerList}
	;
	


struct_or_union_specifier {StructOrUnionSpecifier}
	: struct_or_union IDENTIFIER '{' struct_declaration_list '}' {generateStructOrUnionSpecifier}
	| struct_or_union '{' struct_declaration_list '}' {generateStructOrUnionSpecifier}
	| struct_or_union IDENTIFIER {generateStructOrUnionSpecifier}
	;

struct_or_union {StructOrUnion}
	: STRUCT {generateStructOrUnion}
	| UNION {generateStructOrUnion}
	;

struct_declaration_list {StructDeclarationList}
	: struct_declaration {generateStructDeclarationList}
	| struct_declaration_list struct_declaration {generateStructDeclarationList}
	;

struct_declaration {StructDeclaration}
	: specifier_qualifier_list struct_declarator_list ';' {generateStructDeclaration}
	;

struct_declarator_list {StructDeclaratorList}
	: struct_declarator {generateStructDeclaratorList}
	| struct_declarator_list ',' struct_declarator {generateStructDeclaratorList}
	;

struct_declarator {StructDeclarator}
	: declarator {generateStructDeclarator}
	| ':' constant_expression {generateStructDeclarator}
	| declarator ':' constant_expression {generateStructDeclarator}
	;


statement_list {StatementList}
	: statement {generateStatementList}
	| statement_list statement {generateStatementList}
	;

statement {Statement}
	: labeled_statement {generateStatement}
	| compound_statement {generateStatement}
	| expression_statement {generateStatement}
	| selection_statement {generateStatement}
	| iteration_statement {generateStatement}
	| jump_statement {generateStatement}
	;

iteration_statement {IterationStatement}
	: WHILE '(' expression ')' statement {generateIterationStatement}
	| DO statement WHILE '(' expression ')' ';' {generateIterationStatement}
	| FOR '(' expression_statement expression_statement ')' statement {generateIterationStatement}
	| FOR '(' expression_statement expression_statement expression ')' statement {generateIterationStatement}
	;

selection_statement {SelectionStatement}
	: IF '(' expression ')' statement {generateSelectionStatement}
	| IF '(' expression ')' statement ELSE statement {generateSelectionStatement}
	| SWITCH '(' expression ')' statement {generateSelectionStatement}
	;

expression_statement {Expression}
	: ';' {generateExpressionStatement}
	| expression ';' {generateExpressionStatement}
	;

labeled_statement {LabeledStatement}
	: CASE constant_expression ':' statement {generateLabeledStatement}
	| DEFAULT ':' statement {generateLabeledStatement}
	| IDENTIFIER ':' statement {generateLabeledStatement}
	;

compound_statement {CompoundStatement}
	: '{' '}' {generateCompoundStatement}
	| '{' statement_list '}' {generateCompoundStatement}
	| '{' declaration_list '}' {generateCompoundStatement}
	| '{' declaration_list statement_list '}' {generateCompoundStatement}
	;

jump_statement {JumpStatement}
	: GOTO IDENTIFIER ';' {generateJumpStatement}
	| CONTINUE ';' {generateJumpStatement}
	| BREAK ';' {generateJumpStatement}
	| RETURN ';' {generateJumpStatement}
	| RETURN expression ';' {generateJumpStatement}
	;


assignment_operator {TerminalUnit}
	: '=' {generateAssignmentOperator}
	| MUL_ASSIGN {generateAssignmentOperator}
	| DIV_ASSIGN {generateAssignmentOperator}
	| MOD_ASSIGN {generateAssignmentOperator}
	| ADD_ASSIGN {generateAssignmentOperator}
	| SUB_ASSIGN {generateAssignmentOperator}
	| LEFT_ASSIGN {generateAssignmentOperator}
	| RIGHT_ASSIGN {generateAssignmentOperator}
	| AND_ASSIGN {generateAssignmentOperator}
	| XOR_ASSIGN {generateAssignmentOperator}
	| OR_ASSIGN {generateAssignmentOperator}
	;

unary_operator {TerminalUnit}
	: '&' {generateUnaryOperator}
	| '*' {generateUnaryOperator}
	| '+' {generateUnaryOperator}
	| '-' {generateUnaryOperator}
	| '~' {generateUnaryOperator}
	| '!' {generateUnaryOperator} 
	;


expression {Expression}
	: assignment_expression {generateExpression}
	| expression ',' assignment_expression {generateExpression}
	;

assignment_expression {AssignmentExpression}
	: conditional_expression {generateAssignmentExpression}
	| unary_expression assignment_operator assignment_expression {generateAssignmentExpression}
	;

constant_expression {ConstantExpression}
	: conditional_expression {generateConstantExpression}
	;

conditional_expression {ConditionalExpression}
	: logical_or_expression {generateConditionalExpression}
	| logical_or_expression '?' expression ':' conditional_expression {generateConditionalExpression}
	;

logical_or_expression {Expression}
	: logical_and_expression {generateExpression}
	| logical_or_expression OR_OP logical_and_expression {generateExpression}
	;

logical_and_expression {Expression}
	: inclusive_or_expression {generateExpression}
	| logical_and_expression AND_OP inclusive_or_expression {generateExpression}
	;

inclusive_or_expression {Expression}
	: exclusive_or_expression {generateExpression}
	| inclusive_or_expression '|' exclusive_or_expression {generateExpression}
	;

exclusive_or_expression {Expression}
	: and_expression {generateExpression}
	| exclusive_or_expression '^' and_expression {generateExpression}
	;

and_expression {Expression}
	: equality_expression {generateExpression}
	| and_expression '&' equality_expression {generateExpression}
	;

equality_expression {Expression}
	: relational_expression {generateExpression}
	| equality_expression EQ_OP relational_expression {generateExpression}
	| equality_expression NE_OP relational_expression {generateExpression}
	;

relational_expression {Expression}
	: shift_expression {generateExpression}
	| relational_expression '<' shift_expression {generateExpression}
	| relational_expression '>' shift_expression {generateExpression}
	| relational_expression LE_OP shift_expression {generateExpression}
	| relational_expression GE_OP shift_expression {generateExpression}
	;

shift_expression {Expression}
	: additive_expression {generateExpression}
	| shift_expression LEFT_OP additive_expression {generateExpression}
	| shift_expression RIGHT_OP additive_expression {generateExpression}
	;

additive_expression {Expression}
	: multiplicative_expression {generateExpression}
	| additive_expression '+' multiplicative_expression {generateExpression}
	| additive_expression '-' multiplicative_expression {generateExpression}
	;

multiplicative_expression {Expression}
	: cast_expression {generateExpression}
	| multiplicative_expression '*' cast_expression {generateExpression}
	| multiplicative_expression '/' cast_expression {generateExpression}
	| multiplicative_expression '%' cast_expression {generateExpression}
	;

cast_expression {CastExpression}
	: unary_expression {generateCastExpression}
	| '(' type_name ')' cast_expression {generateCastExpression}
	;

unary_expression {UnaryExpression}
	: postfix_expression {generateUnaryExpression}
	| INC_OP unary_expression {generateUnaryExpression}
	| DEC_OP unary_expression {generateUnaryExpression}
	| unary_operator cast_expression {generateUnaryExpression}
	| SIZEOF unary_expression {generateUnaryExpression}
	| SIZEOF '(' type_name ')' {generateUnaryExpression}
	;

postfix_expression {PostfixExpression}
	: primary_expression {generatePostfixExpression}
	| postfix_expression '[' expression ']' {generatePostfixExpression}
	| postfix_expression '(' ')' {generatePostfixExpression}
	| postfix_expression '(' argument_expression_list ')' {generatePostfixExpression}
	| postfix_expression '.' IDENTIFIER {generatePostfixExpression}
	| postfix_expression PTR_OP IDENTIFIER {generatePostfixExpression}
	| postfix_expression INC_OP {generatePostfixExpression}
	| postfix_expression DEC_OP {generatePostfixExpression}
	;

primary_expression {PrimaryExpression}
	: IDENTIFIER {generatePrimaryExpression}
	| CONSTANT {generatePrimaryExpression}
	| STRING_LITERAL {generatePrimaryExpression}
	| '(' expression ')' {generatePrimaryExpression}
	;

argument_expression_list {ArgumentExpressionList}
	: assignment_expression {generateArgumentExpressionList}
	| argument_expression_list ',' assignment_expression {generateArgumentExpressionList}
	;






parameter_type_list {ParameterTypeList}
	: parameter_list {generateParameterTypeList}
	| parameter_list ',' ELLIPSIS {generateParameterTypeList}
	;

parameter_list {ParameterList}
	: parameter_declaration {generateParameterList}
	| parameter_list ',' parameter_declaration {generateParameterList}
	;

parameter_declaration {ParameterDeclaration}
	: declaration_specifiers declarator {generateParameterDeclaration}
	| declaration_specifiers abstract_declarator {generateParameterDeclaration}
	| declaration_specifiers {generateParameterDeclaration}
	;



type_name {TypeName}
	: specifier_qualifier_list {generateTypeName}
	| specifier_qualifier_list abstract_declarator {generateTypeName}
	;

specifier_qualifier_list {SpecifierQualifierList}
	: type_specifier specifier_qualifier_list {generateSpecifierQualifierList}
	| type_specifier {generateSpecifierQualifierList}
	| type_qualifier specifier_qualifier_list {generateSpecifierQualifierList}
	| type_qualifier {generateSpecifierQualifierList}
	;

abstract_declarator {AbstractDeclarator}
	: pointer {generateAbstractDeclarator}
	| direct_abstract_declarator {generateAbstractDeclarator}
	| pointer direct_abstract_declarator {generateAbstractDeclarator}
	;

direct_abstract_declarator {DirectAbstractDeclarator}
	: '(' abstract_declarator ')' {generateDirectAbstractDeclarator}
	| '[' ']' {generateDirectAbstractDeclarator}
	| '[' constant_expression ']' {generateDirectAbstractDeclarator}
	| direct_abstract_declarator '[' ']' {generateDirectAbstractDeclarator}
	| direct_abstract_declarator '[' constant_expression ']' {generateDirectAbstractDeclarator}
	| '(' ')' {generateDirectAbstractDeclarator}
	| '(' parameter_type_list ')' {generateDirectAbstractDeclarator}
	| direct_abstract_declarator '(' ')' {generateDirectAbstractDeclarator}
	| direct_abstract_declarator '(' parameter_type_list ')' {generateDirectAbstractDeclarator}
	;

%%


#include "struct.h"
#include "function.h"
