
direct_declarator {DirectDeclarator}
	: '(' parameter_type_list ')' {generateDirectDeclarator}
	;

parameter_type_list {ParameterTypeList}
	: parameter_list {generateParameterTypeList}
	;

parameter_list {ParameterList}
	: parameter_declaration {generateParameterList}
	;

%%


#include "struct.h"
#include "function.h"
