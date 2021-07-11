#include "Utils.h"
	
// Convert the string to uppercase
std::string ToUpperCase(std::string input){
	// convert the passed instruction mnemonic to uppercase
	std::transform(input.begin(), input.end(),input.begin(), ::toupper);
	return input;
}

// trim from start (in place)
static inline void ltrim(std::string &s) {
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
		return !std::isspace(ch);
	}));
}

// trim from end (in place)
static inline void rtrim(std::string &s) {
	s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
		return !std::isspace(ch);
	}).base(), s.end());
}

// trim from both ends (in place)
void trim(std::string &s) {
	ltrim(s);
	rtrim(s);
}

std::vector<std::string> Splitpath(const char * str){
	
	std::set<char> delims{'/'};

	std::vector<std::string> result;
	std::string temp = str;
	char const* pch = temp.c_str();
	char const* start = pch;
	for(; *pch; ++pch){
		if (delims.find(*pch) != delims.end()){
			if (start != pch){
				std::string str(start, pch);
				result.push_back(str);
			}
			else{
				result.push_back("");
			}
			start = pch + 1;
		}
	}
	result.push_back(start);

	return result;
}


std::vector<std::string> splitString(std::string exp,char delim){
	std::vector<std::string> split;
	std::string temp = "";
	for(auto item : exp){
		if(item == delim){
			split.push_back(temp);
			temp = "";
		}
		temp += item;
	}

	return split;
}


bool isNumber(const std::string& s){
	return !s.empty() && std::find_if(s.begin(), 
		s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

  
bool isDigit(char c){
	return '0' <= c && c <= '9';
}

bool isLetter(char c){
	return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}

bool isOperator(std::string item){
	return (std::find(OPERATORS.begin(),OPERATORS.end(),item)!=OPERATORS.end());
}

bool isType(std::string type){
	return (std::find(TYPES.begin(),TYPES.end(),type)!=TYPES.end());
}

bool isStatement(std::string c){
	return (std::find(STATEMENTS.begin(),STATEMENTS.end(),c)!=STATEMENTS.end());
}

bool isConditional(std::string c){
	return (std::find(CONDITIONALS.begin(),CONDITIONALS.end(),c)!=CONDITIONALS.end());
}

bool isGlyph(char c){
	return (' ' < c && c <= '~');
}

bool isKeyword(std::string item){
	return (std::find(KEYWORDS.begin(),KEYWORDS.end(),item) != KEYWORDS.end());
}

bool isIgnoredOperatorToken(TokenType token){
	return (std::find(IGNORE_OPERATORS.begin(),IGNORE_OPERATORS.end(),token)!=IGNORE_OPERATORS.end());
}


#if DEBUG_PARSE_ENTER_EXIT
	void printParseEnters(int num,char sep,std::string func){
		std::string tab = std::string(num,sep);
		std::cout<<tab<<"Entered "+ func + "\n";
	}

	void printParseExits(int num,char sep,std::string func){
		std::string tab = std::string(num,sep);
		std::cout<<tab<<"Exited "+ func + "\n";
	}
	

#else
	void printParseEnters(int num,char sep,std::string func){
		
	}

	void printParseExits(int num,char sep,std::string func){
		
	}

#endif


#if DEBUG_TOKEN_ACCEPT
	void printAcceptedToken(TokenType token,int lineNumber,std::string value){
		std::cout<<"Accepted token "<< TOKEN_ENUM_TYPE_NAMES[token]<<" in line "<< lineNumber << " as " << value << std::endl;
	}
#else
	void printAcceptedToken(TokenType token,int lineNumber,std::string value){

	}
#endif