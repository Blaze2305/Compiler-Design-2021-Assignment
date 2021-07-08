#include "Parser.h"

Parser::Parser(){
	f=true;
	f2=true;
	p=true;
	count=0;
}

void Parser::accept(TokenType expected){
	if(currentToken.tokenType == expected){
		currentToken =  scanner.getToken();
	}else{
		throw  Exception("Syntax error on line " + currentToken.line);
	}
}

void Parser::acceptToken(){
	currentToken = scanner.getToken();
}

bool Parser::checkToken(TokenType expected){
	return currentToken.tokenType == expected;
}


void Parser::parse(std::string fileName){
	scanner = Scanner(fileName);
	currentToken = scanner.getToken();
}

void Parser::parseProgram(){
	
}