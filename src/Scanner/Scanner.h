#ifndef SCANNER_H_

#define SCANNER_H_

#include<string>
#include<fstream>
#include<algorithm>
#include<iostream>
#include<array>
#include<stdexcept>
#include<map>

#include "../Models/Structs.h"
#include "../Utils/Utils.h"

static const std::array<char,4> TO_SKIP = {' ','\n','\r','\t'};

static const std::map<std::string,TokenType> TOKEN_MAP = {
	{
		"global",Global
	},
	{
		"end",End,
	},
	{
		"def",Def
	},
	{
		"=",Assignment
	},
	{
		":",Colon
	},
	{
		";",SemiColon
	},
	{
		"if",If
	},
	{
		"else",Else
	},
	{
		"read",Read
	},
	{
		"print",Print
	},
	{
		"while",While
	},
	{
		",",Comma
	},
	{
		"==",Conditional
	},
	{
		"<",Conditional
	},
	{
		">",Conditional
	}
};

class Scanner {

	private:
		char currentChar;
		TokenType currentKind;
		std::string currentString;
		std::fstream inFile;
		static int line;
		// methods
		void acceptChar();
		void discardChar();
		TokenType scanToken();
		void scanSeparator();


	public:
		Scanner(std::string filename);

		// methods
		TokenRecord getToken();

		// getters
		char getCurrentChar();

};

#endif