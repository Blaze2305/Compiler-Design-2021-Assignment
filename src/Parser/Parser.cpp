#include "Parser.h"


Parser::Parser(std::string fileName){
	scanner = new Scanner(fileName);
	f=true;
	f1=true;
	p=true;
	count=0;
}


void Parser::accept(TokenType expected){
	if(currentToken.tokenType == expected){
		currentToken =  scanner->getToken();
	}else{
		throw  std::runtime_error("Syntax error on line " + currentToken.lineNumber);
	}
}

void Parser::acceptToken(){
	currentToken = scanner->getToken();
}

bool Parser::checkToken(TokenType expected){
	return currentToken.tokenType == expected;
}


void Parser::parse(){
	currentToken = scanner->getToken();
}

void Parser::parseProgram(){
	
}