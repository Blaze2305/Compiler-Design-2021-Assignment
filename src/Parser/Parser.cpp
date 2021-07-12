#include "Parser.h"

static int tabNum = -1;
std::string tab;
std::string exitTab;
char tabChar = '\t';

Parser::Parser(std::string fileName){
	scanner = new Scanner(fileName);
	count=0;
}

Parser::~Parser(){
	delete scanner;
}

void Parser::showSymbolTable(){
	std::string line = std::string(70,'-');
	std::ostringstream out ;
	out<<line<<"\n";
	out<<std::setw(40)<<"SYMBOL TABLE\n\n";
	// out<<std::setw(15)<<"Symbol Name"<<std::setw(15)<<"Type"<<std::setw(15)<<"Value"<<std::setw(20)<<"Line Number\n";
	out<<std::setw(15)<<"Symbol Name"<<std::setw(15)<<"Type"<<std::setw(20)<<"Line Number\n";
	out<<line<<"\n";
	for(auto const& [key,value] : this->symtab.SymbolTableMap){
		// out<<std::setw(15)<<value.symbolName<<std::setw(15)<<value.type<<std::setw(15)<<value.attribute<<std::setw(20)<<value.lineNumber<<"\n";
		out<<std::setw(15)<<value.symbolName<<std::setw(15)<<value.type<<std::setw(20)<<value.lineNumber<<"\n";
	}
	out<<line<<"\n";
	std::cout<<out.str()<<std::endl;
}

void Parser::accept(TokenType expected){
	if(currentToken.tokenType == expected){
		printAcceptedToken(currentToken.tokenType,currentToken.lineNumber,currentToken.Value);
		currentToken =  scanner->getToken();
	}else{
		std::ostringstream out;
		out << "Syntax error on line ";
		out << currentToken.lineNumber;
		out << "  CURRENT TOKEN IS ";
		out << TOKEN_ENUM_TYPE_NAMES[currentToken.tokenType];
		out << "  CURRENT TOKEN NAME IS ";
		out << currentToken.Value;
		out << " BUT EXPECTED TOKEN IS ";
		out << TOKEN_ENUM_TYPE_NAMES[expected];
		throw  std::runtime_error(out.str());
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
	parseProgram();
	if(currentToken.tokenType != EOT){
		std::ostringstream out ;
		out << "Syntax error on line ";
		out << currentToken.lineNumber;
		out << " Redundant chars at the end";
		throw  std::runtime_error(out.str());
	}
}

void Parser::parseProgram(){
	tabNum+=1;
	printParseEnters(tabNum,tabChar,"parseProgram");
	accept(Global);
	if(checkToken(Def)){
		parseDeclList();
	}
	parseStmtList();
	accept(End);
	tabNum-=1;
	printParseExits(tabNum,tabChar,"parseProgram");
}
void Parser::parseDeclList(){
	tabNum+=1;
	printParseEnters(tabNum,tabChar,"parseDeclList");
	parseDecl();
	while(checkToken(Def)){
		parseDeclList();
	}
	tabNum-=1;
	printParseExits(tabNum,tabChar,"parseDeclList");
}

void Parser::parseDecl(){
	tabNum+=1;
	printParseEnters(tabNum,tabChar,"parseDecl");
	accept(Def);
	parseTypeList();
	accept(End);
	tabNum-=1;
	printParseExits(tabNum,tabChar,"parseDecl");
}

void Parser::parseTypeList(){
	tabNum+=1;
	printParseEnters(tabNum,tabChar,"parseTypeList");
	parseVarList();
	accept(Colon);
	parseType();
	accept(SemiColon);
	parseTypeListA();
	tabNum-=1;
	printParseExits(tabNum,tabChar,"parseTypeList");
}

void Parser::parseTypeListA(){
	tabNum+=1;
	printParseEnters(tabNum,tabChar,"parseTypeListA");
	if(checkToken(Identifier)){
		parseVarList();
		accept(Colon);
		parseType();
		accept(SemiColon);
		parseTypeListA();
	}
	tabNum-=1;
	printParseExits(tabNum,tabChar,"parseTypeListA");
}

void Parser::parseType(){
	tabNum+=1;
	printParseEnters(tabNum,tabChar,"parseType");
	std::string tempType = this->currentToken.Value;
	int tempLineNum = this->currentToken.lineNumber;
	accept(Type);
	for(std::string symbol : this->symbolNamesList){
		this->symtab.addSymbolToTable(symbol,tempLineNum,tempType);
	}
	this->symbolNamesList.clear();
	tabNum-=1;
	printParseExits(tabNum,tabChar,"parseType");
}

void Parser::parseVarList(){
	tabNum+=1;
	printParseEnters(tabNum,tabChar,"parseVarList");
	if(checkToken(Identifier)){
		parseVar();
		if(checkToken(Comma)){
			accept(Comma);
			parseVarList();
		}
	}
	tabNum-=1;
	printParseExits(tabNum,tabChar,"parseVarList");
}

void Parser::parseVar(){
	tabNum+=1;
	printParseEnters(tabNum,tabChar,"parseVar");
	this->symbolNamesList.push_back(this->currentToken.Value);
	accept(Identifier);
	tabNum-=1;
	printParseExits(tabNum,tabChar,"parseVar");
}

void Parser::parseStmtList(){
	tabNum+=1;
	printParseEnters(tabNum,tabChar,"parseStmtList");
	parseStmt();
	accept(SemiColon);
	parseStmtListA();
	tabNum-=1;
	printParseExits(tabNum,tabChar,"parseStmtList");
}

void Parser::parseStmtListA(){
	tabNum+=1;
	printParseEnters(tabNum,tabChar,"parseStmtListA");
	if(checkToken(Identifier) || checkToken(Read) || checkToken(Print) || checkToken(If) || checkToken(While)){
		parseStmt();
		accept(SemiColon);
		parseStmtListA();
	}
	tabNum-=1;
	printParseExits(tabNum,tabChar,"parseStmtListA");
}

void Parser::parseStmt(){
	tabNum+=1;
	printParseEnters(tabNum,tabChar,"parseStmt");
	if(checkToken(Identifier)){
		parseAssignementStmt();
	}else if(checkToken(Read)){
		parseReadStmt();
	}else if(checkToken(Print)){
		parsePrintStmt();
	}else if(checkToken(If)){
		parseIfStmt();
	}else if(checkToken(While)){
		parseWhileStmt();
	}else{
		std::ostringstream out;
		out << "Syntax error on line ";
		out << currentToken.lineNumber;
		throw  std::runtime_error(out.str());
	}
	tabNum-=1;
	printParseExits(tabNum,tabChar,"parseStmt");
}

void Parser::parseAssignementStmt(){
	tabNum+=1;
	printParseEnters(tabNum,tabChar,"parseAssignementStmt");
	accept(Identifier);
	accept(Assignment);
	parseExp();
	tabNum-=1;
	printParseExits(tabNum,tabChar,"parseAssignementStmt");
}

void Parser::parseReadStmt(){
	tabNum+=1;
	printParseEnters(tabNum,tabChar,"parseReadStmt");
	accept(Read);
	accept(Identifier);
	tabNum-=1;
	printParseExits(tabNum,tabChar,"parseReadStmt");
}

void Parser::parsePrintStmt(){
	tabNum+=1;
	printParseEnters(tabNum,tabChar,"parsePrintStmt");
	accept(Print);
	parseExp();
	tabNum-=1;
	printParseExits(tabNum,tabChar,"parsePrintStmt");
}

void Parser::parseIfStmt(){
	tabNum+=1;
	printParseEnters(tabNum,tabChar,"parseIfStmt");
	accept(If);
	parseBexp();
	accept(Colon);
	parseStmtList();
	parseElsePart();
	accept(End);
	tabNum-=1;
	printParseExits(tabNum,tabChar,"parseIfStmt");
}

void Parser::parseElsePart(){
	tabNum+=1;
	printParseEnters(tabNum,tabChar,"parseElsePart");
	if(checkToken(Else)){
		accept(Else);
		parseStmtList();
	}
	tabNum-=1;
	printParseExits(tabNum,tabChar,"parseElsePart");
}

void Parser::parseWhileStmt(){
	tabNum+=1;
	printParseEnters(tabNum,tabChar,"parseWhileStmt");
	accept(While);
	parseBexp();
	accept(Colon);
	parseStmtList();
	accept(End);
	tabNum-=1;
	printParseExits(tabNum,tabChar,"parseWhileStmt");
}

void Parser::parseBexp(){
	tabNum+=1;
	printParseEnters(tabNum,tabChar,"parseBexp");
	if(checkToken(LParen)){
		accept(LParen);
		parseBexp();
		accept(RParen);
	}else if(checkToken(Conditional)){
		accept(Conditional);
		parseBexp();
		parseBexpA();
	}else {
		parseExp();
		accept(Conditional);
		parseExp();
		parseBexpA();
	}
	tabNum-=1;
	printParseExits(tabNum,tabChar,"parseBexp");
}

void Parser::parseBexpA(){
	tabNum+=1;
	printParseEnters(tabNum,tabChar,"parseBexpA");
	if(checkToken(Conditional)){
		accept(Conditional);
		parseBexp();
		parseBexpA();
	}
	tabNum-=1;
	printParseExits(tabNum,tabChar,"parseBexpA");
}

void Parser::parseExp(){
	tabNum+=1;
	printParseEnters(tabNum,tabChar,"parseExp");
	if(checkToken(LParen)){
		accept(LParen);
		parseExp();
		accept(RParen);
	}else if(checkToken(Identifier)){
		accept(Identifier);
		parseExpA();
	}else if(checkToken(Number)){
		accept(Number);
		parseExpA();
	}
	tabNum-=1;
	printParseExits(tabNum,tabChar,"parseExp");
}

void Parser::parseExpA(){
	tabNum+=1;
	printParseEnters(tabNum,tabChar,"parseExpA");
	if(checkToken(Operator)){
		accept(Operator);
		parseExp();
		parseExpA();
	}
	tabNum-=1;
	printParseExits(tabNum,tabChar,"parseExpA");
}

void Parser::parseNumber(){
	tabNum+=1;
	printParseEnters(tabNum,tabChar,"parseNumber");
	accept(Number);
	tabNum-=1;
	printParseExits(tabNum,tabChar,"parseNumber");
}
