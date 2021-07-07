#include<iostream>

#include "src/IO/IO.h"
#include "src/Utils/Utils.h"
#include "src/Models/Structs.h"
#include "src/Scanner/Scanner.h"

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

	while(scanner.getCurrentChar() != '\u0000'){
		std::cout<<scanner.getToken();
	}

	return 0;
}