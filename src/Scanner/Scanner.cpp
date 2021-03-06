#include "Scanner.h"

int Scanner::line = 1;

Scanner::Scanner(std::string filename){
	this->inFile = std::fstream(filename);
	this->inFile >> std::noskipws >> this->currentChar;
	this->currentString = "";
}

Scanner::~Scanner(){
	this->inFile.close();
}

void Scanner::acceptChar(){
	this->currentString += currentChar;
	char ch;
	if(inFile >> std::noskipws >> ch){
		this->currentChar = ch;
		// std::cout<<"CURRENT CHAR:  "<< this->currentChar << std::endl;
	}else{
		this->currentChar = '\u0000';
	}
}

void Scanner::discardChar(){
	char ch;
	if(inFile >> std::noskipws >> ch){
		this->currentChar = ch;
		// std::cout<<"CURRENT CHAR:  "<< this->currentChar << std::endl;
	}else{
		this->currentChar = '\u0000';
	}
}

TokenType Scanner::scanToken(){
	TokenType result;
	switch(this->currentChar){
		case ')':
			result = RParen;
			acceptChar();
			break;
		case '(':
			result = LParen;
			acceptChar();
			break;
		case '\u0000':
			result = EOT;
			break;
		default:
			if(isLetter(this->currentChar)){
				while(isLetter(this->currentChar)){
					acceptChar();
					if(isKeyword(this->currentString)){
						try{
							result = TOKEN_MAP.at(this->currentString);
						}catch(std::out_of_range err){
							result = Identifier;
						}
					}else if(isType(this->currentString)){
						result = Type;
					}else if(isStatement(this->currentString)){
						try{
							result = TOKEN_MAP.at(this->currentString);
						}catch(std::out_of_range err){
							result = Statement;
						}
					}else if(isConditional(this->currentString)){
						result = Conditional;
					}else{
						result = Identifier;
					}
				}
			}else if(isDigit(this->currentChar)){
				while(isDigit(this->currentChar)){
					acceptChar();
					result = Number;
				}
			}else if(isOperator(std::string(1,this->currentChar))){
				while(isOperator(std::string(1,this->currentChar))){
					acceptChar();
				}
				
				// get semicolon ,assignment and colon
				try{
					result = TOKEN_MAP.at(this->currentString);
				}catch(std::out_of_range err){
					if(isOperator(this->currentString)){
						result = Operator;
					}else{
						result = None;
					}
				}
			}
			else{
				result = None;
			}
			break;
	}
	return result;
}

void Scanner::scanSeparator(){
	// skip whitespace \n \r \t
	if(this->currentChar == '\n'){
		this->line++;
	}
	discardChar();
}


TokenRecord Scanner::getToken(){
	this->currentString = "";
	while(std::find(TO_SKIP.begin(), TO_SKIP.end(),this->currentChar)!=TO_SKIP.end()){
		scanSeparator();
	}
	this->currentKind = scanToken();
	return TokenRecord{
		this->currentKind,
		this->currentString,
		this->line
	};
}

char Scanner::getCurrentChar(){
	return this->currentChar;
}