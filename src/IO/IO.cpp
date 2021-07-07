#include "IO.h"

std::string ReadLine(std::ifstream  *file) {
	std::string line = "";
	std::getline(*file, line);
	return line;
}

void WriteLine(std::ofstream* file, std::string line) {
	*file << line ;
}