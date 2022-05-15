#ifndef INC_385_FUNCTIONS_H
#define INC_385_FUNCTIONS_H

#include <vector>
#include <string>

void init();
void file_init (std::ifstream & file);

int getIndexFromConsole();
int getIndexFromFile(std::ifstream & file);
int getSum();

std::string my_function();
std::string getStringFromConsole();

bool getNext();
bool get_0_1();

std::vector <double> get_vector(std::string now_line, int string_number);

#endif //INC_385_FUNCTclIONS_H