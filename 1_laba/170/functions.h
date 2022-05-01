#ifndef INC_170_FUNCTIONS_H
#define INC_170_FUNCTIONS_H


bool init();
bool file_init (std::ifstream & f);
bool checkIndexes();
bool getNext();

int getIndex();
double getNumberFromFile(std::ifstream & file);
double Partition(std::vector<double>& values, double l, double r);

double getValue();
double getDoubleFromFile(std::ifstream & file)

char get_0_1();

std::string my_func();

void QuickSortImpl(std::vector<int>& values, int l, int r);
void QuickSort(std::vector<int>&values);


#endif //INC_170_FUNCTIONS_H
