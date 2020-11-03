D			"[0-9]"
L			"[a-zA-Z_]"

%%

{L}({L}|{D})*			{ return(IDENTIFIER); }
"'"						{ return(QUOTATION); }
":"						{ return(COLON); }
";"						{ return(SEMICOLON); }
"\|"					{ return(VERTICAL_LINE); }
"'\\?.'"				{ return(CONSTANT); }
"[ \t\v\n\f\r]"			{ break; }
"{"						{ return('{'); }
"}"						{ return('}'); }
"%%"					{ return(SEGMENT); }

%%

enum TOKEN_TYPE {
	IDENTIFIER=128, QUOTATION, COLON, SEMICOLON, VERTICAL_LINE, CONSTANT, SEGMENT
};