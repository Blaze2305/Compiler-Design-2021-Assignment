#include "Structs.h"


std::ostream& operator<< (std::ostream& out, const SymTabRow& obj){
	out<<"\n------------------------------------------------------------------------------\n";
	out<<"Symbol Name --> "<<obj.symbolName<<std::endl;
	out<<"Type --> "<<obj.type<<std::endl;
	out<<"Value --> "<<obj.attribute<<std::endl;
	out<<"Line Number --> "<<obj.lineNumber<<std::endl;
	out<<"\n------------------------------------------------------------------------------\n";
	return out;
}



std::ostream& operator<< (std::ostream& out, const TokenRecord& obj){
	out<<"\n------------------------------------------------------------------------------\n";
	out<<"Token Type --> "<<TOKEN_ENUM_TYPE_NAMES[obj.tokenType]<<std::endl;
	out<<"String Value --> "<<obj.Value<<std::endl;
	out<<"Line Number --> "<<obj.lineNumber<<std::endl;
	out<<"\n------------------------------------------------------------------------------\n";
	return out;
}
