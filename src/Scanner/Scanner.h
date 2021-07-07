#ifndef SCANNER_H_

#define SCANNER_H_

#include<string>
#include<fstream>
#include<algorithm>
#include<iostream>
#include<array>

#include "../Models/Structs.h"
#include "../Utils/Utils.h"

static const std::array<char,4> TO_SKIP = {' ','\n','\r','\t'};


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

//   public Token scan(){
//     currentSpelling = new StringBuffer("");
//     while(currentChar == ' ' || currentChar == '\n' || currentChar == '\r')
//       scanSeparator();
//     currentKind = scanToken();
//     finalkind = currentKind;
//     return new Token(currentKind, currentSpelling.toString(), line);
//   }
  

#endif