#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string str = "hello world";

int main() {
    ifstream file_in("in.txt");

    file_in >> str;

    cout << str << endl;

    return 0;
}