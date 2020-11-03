
output:"F:/Programme/Yacc/Yacc/YaccParse/yacc_word"
classname:"YaccWord"
version:"1.1.1"

{Constant
D													"[0-9]"
L													"[a-zA-Z_]"
Constant}

{Target
{L}({L}|{D})*										{ return(Identifier); }
"\"([^\"\\]|\\.)*\""								{ return(String); }
"'"													{ return('\''); }
":"													{ return(':'); }
";"													{ return(';'); }
"\|"												{ return('|'); }
"'\\?.'"											{ return(Char); }
"[ \t\v\f\n\r]+"									{ /*return(Blank);*/ }
"//[^\n]*\n"										{ /*return(Comment);*/ }
"/\*/?([^/]|[^\*]/)*\*+/"							{ /*return(Comment);*/ }
"{"													{ return('{'); }
"}"													{ return('}'); }

"output:"											{ return(Output); }
"parsename:"										{ return(ParseName); }
"wordname:"											{ return(WordName); }
"wordheader:"										{ return(WordHeader); }
"version:"											{ return(Version); }
"namespace:"										{ return(Namespace); }
"start:"											{ return(Start); }
"function:"											{ return(Function); }

"\{Grammar"											{ return(Segment_Grammar_Left); }
"Grammar\}"											{ return(Segment_Grammar_Right); }

// Manual catch {...}
"\{"												{ catch_code(); return(Regex_Code); }

// No support No Greedy for convenience, meaning you should not insert two same kind segment
"\{Code\-H\-Outside.*Code\-H\-Outside\}"			{ return(Segment_Code_H_Outside); }
"\{Code\-H\-Public.*Code\-H\-Public\}"				{ return(Segment_Code_H_Public); }
"\{Code\-H\-Private.*Code\-H\-Private\}"			{ return(Segment_Code_H_Private); }
"\{Code\-CPP.*Code\-CPP\}"							{ return(Segment_Code_Cpp); }
Target}

{Code-H-Public
	enum TOKEN_TYPE {
		Identifier = 128,
		String,
		Char,
		Blank,
		Comment,
		Output,
		ParseName,
		WordName,
		WordHeader,
		Version,
		Namespace,
		Start,
		Function,
		Segment_Grammar_Left,
		Segment_Grammar_Right,
		Regex_Code,
		Segment_Code_H_Outside,
		Segment_Code_H_Public,
		Segment_Code_H_Private,
		Segment_Code_Cpp,
	};
Code-H-Public}

{Code-H-Private
	void catch_code();
Code-H-Private}

{Code-CPP
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
Code-CPP}
