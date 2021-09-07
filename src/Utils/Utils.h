#ifndef UTILS_H_

#define UTILS_H_

#define DEBUG_PARSE_ENTER_EXIT false
#define DEBUG_TOKEN_ACCEPT true

#include <string>
#include <algorithm>
#include <cctype>
#include <locale>
#include <vector>
#include <iostream>
#include <set>
#include <array>
#include <cctype>
#include "../Models/Structs.h"

static const std::array<std::string,16> OPERATORS = {";",":","+","-","*","%","/","!=","=","==","<",">","!",",","<=",">="};

static const std::array<TokenType,2> IGNORE_OPERATORS = {SemiColon,Colon};

static const std::array<std::string,3> TYPES = {"int","char","bool"};

static const std::array<std::string,3> CONDITIONALS = {"or","and","not"};

static const std::array<std::string,5> STATEMENTS = {"if","while","else","print","read"};

static const std::array<std::string,5> KEYWORDS = {"global","end","def","false","true"};

std::string ToUpperCase(std::string);

std::vector<std::string> Splitpath(const char * str);

std::vector<std::string> splitString(std::string exp,char delim);

void trim(std::string &s);
bool isOperator(std::string item);
bool isNumber(const std::string& s);
bool isDigit(char c);
bool isLetter(char c);
bool isType(std::string type);
bool isStatement(std::string c);
bool isConditional(std::string c);
// bool isGlyph(char c);
bool isKeyword(std::string item);
bool isIgnoredOperatorToken(TokenType token);

void printParseEnters(int num,char sep,std::string func);
void printParseExits(int num,char sep,std::string func);
void printAcceptedToken(TokenType token,int lineNumber,std::string value);

#endif