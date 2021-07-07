#ifndef STRUCT_H_
#define STRUCT_H_

#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <bitset>
#include <stack>
#include <array>

enum TokenType {
	Identifier,
	Number,
	Type,
	Operator,
	Keyword,
	Statement,
	LParen,
	RParen,
	EOT,
	Conditional,
	None
};

static const std::array<std::string,11> TOKEN_ENUM_TYPE_NAMES = {
	"Identifier",
	"Number",
	"Type",
	"Operator",
	"Keyword",
	"Statement",
	"LParen",
	"RParen",
	"EOT",
	"Conditional",
	"None"
};


struct TokenRecord{
	TokenType tokenType;
	std::string Value;
	int lineNumber;
	friend std::ostream& operator << (std::ostream& out,const TokenRecord& obj);
};


struct SymTabRow {
	std::string symbolName;
	std::string type;
	std::string attribute;

	friend std::ostream& operator << (std::ostream& out,const SymTabRow& obj);
};


#endif