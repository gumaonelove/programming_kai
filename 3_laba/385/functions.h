#ifndef INC_385_FUNCTIONS_H
#define INC_385_FUNCTIONS_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

void init();
void file_init (std::ifstream & file);

int getIndexFromConsole();
int getIndexFromFile(std::ifstream & file);
int getSum(std::vector< std::vector <double> > my_matrix);

std::string my_function(std::vector< std::vector <double> > my_matrix) ;
std::string getStringFromConsole();

bool getNext();
bool get_0_1();
bool find(std::vector< std::vector <double> > my_matrix);

std::vector < std::vector <double> > get_matrix(bool from_file, std::ifstream & file);
std::vector <double> get_vector(std::string now_line, int string_number);

#endif //INC_385_FUNCTclIONS_H