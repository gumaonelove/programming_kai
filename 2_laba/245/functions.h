#ifndef INC_245_FUNCTIONS_H
#define INC_245_FUNCTIONS_H

#include <vector>

void init();
void file_init (std::ifstream & file);

int getIndex();
int get_index_negative_occurrence_from_array(int now_array[], int lenght);
int get_index_negative_occurrence_from_vector(std::vector<int> now_vector);
int *get_array_from_console (int size_array);
int *get_array_from_file (int size_array, std::ifstream & file);

char get_0_1();
std::string my_function();

bool getNext();

std::vector<int> get_vector_from_console();

std::vector<int> get_vector_from_file(std::ifstream & file);

#endif //INC_245_FUNCTIONS_H


