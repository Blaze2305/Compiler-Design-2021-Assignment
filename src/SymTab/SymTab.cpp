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

bool SymbolTable::checkIfSymbolExists(std::string symbolName){
	return SymbolTableMap.find(symbolName) != SymbolTableMap.end();
}

void SymbolTable::showSymbolTable(){
	std::string line = std::string(70,'-');
	std::ostringstream out ;
	out<<line<<"\n";
	out<<std::setw(40)<<"SYMBOL TABLE\n\n";
	// out<<std::setw(15)<<"Symbol Name"<<std::setw(15)<<"Type"<<std::setw(15)<<"Value"<<std::setw(20)<<"Line Number\n";
	out<<std::setw(15)<<"Symbol Name"<<std::setw(15)<<"Type"<<std::setw(20)<<"Line Number\n";
	out<<line<<"\n";
	for(auto const& [key,value] : SymbolTableMap){
		// out<<std::setw(15)<<value.symbolName<<std::setw(15)<<value.type<<std::setw(15)<<value.attribute<<std::setw(20)<<value.lineNumber<<"\n";
		out<<std::setw(15)<<value.symbolName<<std::setw(15)<<value.type<<std::setw(20)<<value.lineNumber<<"\n";
	}
	out<<line<<"\n";
	std::cout<<out.str()<<std::endl;
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