#include <iostream>
#include <limits>
#include <string>
#include <fstream>

#include "variables.h"
#include "functions.h"

using namespace std;


bool init() 
{
    cout << "Введите значение n: ";
    n = getIndex();

    return true;
}


bool file_init (ifstream & file) 
{
    double now_value;
    string line;

    getline(file, line);
    n = stoi(line);
    
    getline(file, line);
    m = stoi(line);

    return true;
}


int getIndex() 
{
    while (true) {
        int a;
        cin >> a;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка ввода." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return a;
        }
    }
}


char get_0_1() 
{
    while (true) {
        char sm;
        cin >> sm;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (sm == '0' || sm == '1') {
            return sm;
        } else {
            cout << "Ошибка ввода." << endl;
        }
    }
}


bool getNext() 
{
    cout << "Продолжаем? (0 - нет, 1 - да): ";
    while (true) {
        char sm;
        cin >> sm;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (sm == '0' || sm == '1') {
            return sm == '1';
        } else {
            cout << "Ошибка ввода." << endl;
        }
    }
}