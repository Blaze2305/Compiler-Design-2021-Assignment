#include<iostream>


#include "src/Utils/Utils.h"
#include "src/Models/Structs.h"
#include "src/Scanner/Scanner.h"
#include "src/Parser/Parser.h"

int main(int argc, char *argv[]){
	// Check if the file is passed as an argument or not
	// if not then error out
 	if(argc != 2){
		std::cout<<"\nFile Missing , Invalid number of arguments\n";
		return 1;
	}
	std::cout<<"----------------------------------------------------------------------------\n";
	std::cout<<argv[1]<<std::endl;
	std::cout<<"----------------------------------------------------------------------------\n";
	
	Scanner scanner = Scanner(argv[1]);

	// TESTING SCANNER 
	// while(true){
	// 	TokenRecord val = scanner.getToken();
	// 	std::cout<<val;
	// 	if(val.tokenType==EOT){
	// 		break;
	// 	}
	// }

	Parser parser = Parser(argv[1]);
	try{
		parser.parse();
	}catch(std::runtime_error err){
		std::cout<<"INVALID \n";
		std::cout<<err.what();
		exit(1);
	}
	std::cout<<"VALID CODE\n";

	return 0;
}