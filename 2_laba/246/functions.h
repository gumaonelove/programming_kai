#ifndef INC_246_FUNCTIONS_H
#define INC_246_FUNCTIONS_H

bool getNext();
bool isAscendingSequence(std::vector<int> now_vector);

int getIndex();
int getNumberFromFile(std::ifstream & file);
int Partition(std::vector<int>& values, int l, int r);

double getValueFromConsole();
int getValueFromFile(std::ifstream & file);

char get_0_1();

std::string my_func();

void init();
void file_init (std::ifstream & f);

#endif //INC_246_FUNCTIONS_H
