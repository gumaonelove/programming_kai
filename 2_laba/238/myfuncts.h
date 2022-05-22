#ifndef LAB_2_MYFUNCTS_H
#define LAB_2_MYFUNCTS_H

#include <vector>
#include <fstream>

using namespace std;

bool insert();
int insN();
bool isNum(char K[256]);
vector<double>multisMas(int n);
double makeAns(vector<double>multismas, int n);
int insFile(ifstream & file);

#endif //LAB_2_MYFUNCTS_H
