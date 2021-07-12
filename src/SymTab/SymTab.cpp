#include "SymTab.h"

void SymbolTable::addSymbolToTable(std::string symbolName,int lineNumber ,std::string type){
	try{
		SymTabRow tableRow = SymbolTableMap.at(symbolName); 
		std::ostringstream out;
		out << "Symbol " << symbolName << " already declared before.\n";
		out << "Previous declaration at " << tableRow.lineNumber + "\n";
		throw std::runtime_error(out.str());
	}catch(std::out_of_range err){
		this->SymbolTableMap[symbolName] = SymTabRow{symbolName,type,"",lineNumber};
	}
}
void SymbolTable::setSymbolValue(std::string symbolName,std::string value){
	try{
		SymTabRow tableRow = SymbolTableMap.at(symbolName); 
		SymbolTableMap[symbolName].attribute = value;
	}catch(std::out_of_range err){
		std::ostringstream out;
		out << "Symbol " << symbolName << " does not exist.\n";
		throw std::runtime_error(out.str());
	}
}

// void SymbolTable::setSymbolType(std::string symbolName,std::string type){
// 	try{
// 		SymTabRow tableRow = SymbolTableMap.at(symbolName); 
// 		SymbolTableMap[symbolName].type = type;
// 	}catch(std::out_of_range err){
// 		std::ostringstream out;
// 		out << "Symbol " << symbolName << " does not exist.\n";
// 		throw std::runtime_error(out.str());
// 	}
// }