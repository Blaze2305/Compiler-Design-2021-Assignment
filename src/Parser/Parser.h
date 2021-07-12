#ifndef PARSER_H_

#define PARSER_H_


#include "../Models/Structs.h"
#include "../Scanner/Scanner.h"
#include "../Utils/Utils.h"
#include "../SymTab/SymTab.h"
#include<stdexcept>
#include<sstream>
class Parser{
	private:
		TokenRecord currentToken;
		Scanner *scanner;
		SymbolTable symtab;
		int count;

	public:
		Parser(std::string fileName);	
		void accept(TokenType expected);
		void acceptToken();
		bool checkToken(TokenType expected);
		void parse();
		void parseProgram();
		void parseDeclList();
		void parseDecl();
		void parseTypeList();
		void parseTypeListA();
		void parseType();
		void parseVarList();
		void parseVar();
		void parseStmtList();
		void parseStmtListA();
		void parseStmt();
		void parseAssignementStmt();
		void parseReadStmt();
		void parsePrintStmt();
		void parseIfStmt();
		void parseElsePart();
		void parseWhileStmt();
		void parseBexp();
		void parseBexpA();
		void parseExp();
		void parseExpA();
		void parseNumber();
		~Parser();

};
#endif