#include "yacc_word.h"

// <user definition
void YaccWord::catch_code() {
	char c = getNextChar();
	std::string& mStr = getCurWord();
	// simply handle here without considering '}' in another {}, char, string and comment
	while (c != '}' && c != '\0') {
		mStr.push_back(c);
		c = getNextChar();
	}
	if (c == '}') {
		mStr.push_back(c);
	}
}
// user definition>

int YaccWord::runRelativeCode(int type) {
	switch( type ) {
		case 0:
			{ return(Identifier); }
			break;
		case 1:
			{ return(String); }
			break;
		case 2:
			{ return('\''); }
			break;
		case 3:
			{ return(':'); }
			break;
		case 4:
			{ return(';'); }
			break;
		case 5:
			{ return('|'); }
			break;
		case 6:
			{ return(Char); }
			break;
		case 7:
			{ /*return(Blank);*/ }
			break;
		case 8:
			{ /*return(Comment);*/ }
			break;
		case 9:
			{ /*return(Comment);*/ }
			break;
		case 10:
			{ return('{'); }
			break;
		case 11:
			{ return('}'); }
			break;
		case 12:
			{ return(Output); }
			break;
		case 13:
			{ return(ParseName); }
			break;
		case 14:
			{ return(WordName); }
			break;
		case 15:
			{ return(WordHeader); }
			break;
		case 16:
			{ return(Version); }
			break;
		case 17:
			{ return(Namespace); }
			break;
		case 18:
			{ return(Start); }
			break;
		case 19:
			{ return(Function); }
			break;
		case 20:
			{ return(Segment_Grammar_Left); }
			break;
		case 21:
			{ return(Segment_Grammar_Right); }
			break;
		case 22:
			{ catch_code(); return(Regex_Code); }
			break;
		case 23:
			{ return(Segment_Code_H_Outside); }
			break;
		case 24:
			{ return(Segment_Code_H_Public); }
			break;
		case 25:
			{ return(Segment_Code_H_Private); }
			break;
		case 26:
			{ return(Segment_Code_Cpp); }
			break;
	}
	return -1;
}
