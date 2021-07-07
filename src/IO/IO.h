// Header guards
#ifndef IO_H_

#define IO_H_

// File handler
#include<fstream>
#include<string>

std::string ReadLine(std::ifstream *file);
void WriteLine(std::ofstream* file, std::string line);

#endif