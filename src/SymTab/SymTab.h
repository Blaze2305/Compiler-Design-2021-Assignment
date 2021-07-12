#ifndef SYMTAB_H_

#define SYMTAB_H_

#include<map>
#include<stdexcept>
#include<sstream>
#include "../Models/Structs.h"

class SymbolTable{

	private:
		std::map<std::string,SymTabRow> SymbolTableMap;

	public:
		void addSymbolToTable(std::string symbolName,int lineNumber ,std::string type);
		void setSymbolValue(std::string symbolName,std::string value);
		// void setSymbolType(std::string symbolName,std::string type);

		friend class Parser;
};



#endif