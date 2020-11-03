#include <iostream>
#include <fstream>

#include "YaccParse/yacc_parse.h"
#include "generate.h"
#include "produce.h"

int main() {
	string inputFilePath;
	std::cout << "input file path:";
	std::cin >> inputFilePath;

	std::ifstream ifs(inputFilePath);
	string content((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));

	YaccParse::Parse parse(content);
	parse.parse();

	LALR lalr = YaccGenerate::getInstance().calculate();
	
	Produce produce;
	produce.setOutputPath(parse.getOutput());
	produce.setParseName(parse.getParseName());
	produce.setWordName(parse.getWordName());
	produce.setWordHeader(parse.getWordHeader());
	produce.setVersion(parse.getVersion());
	produce.setNamespace(parse.getNamespace());
	
	produce.produceHead(parse.getCodeHOutSide(), parse.getCodeHPublic(), parse.getCodeHPrivate());
	produce.produceCpp(lalr, parse.getCodeCpp());
	produce.produceLalr(lalr);
	
	if(!parse.getFunction().empty()) {
		produce.produceFunction();
	}

	std::cout << "DONE!";

	int i;
	std::cin >> i;

	return 0;
}
