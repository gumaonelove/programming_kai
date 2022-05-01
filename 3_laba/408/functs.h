#ifndef LAB3_FUNCTS_H
#define LAB3_FUNCTS_H

#include <vector>

using namespace std;

void rescript(vector<double>U, vector<double>senior, vector<double>middle, vector<double>junior, int n);
vector<double>push_str(string line);
bool checkline(string line);
string getlin();
void mainfunct(vector<double>senior, vector<double>middle, vector<double>junior, double answer);
bool insert();

#endif //LAB3_FUNCTS_H