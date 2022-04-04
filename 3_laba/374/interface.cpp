#include <iostream>
#include <string>
#include <limits>
#include <fstream>

#include "functions.h"

using namespace std;

extern int n;


void init()
{
    cout << "Введите значение n: ";
    n = getIndex();
}


bool file_init (ifstream & file)
{   
    string line;
    getline(file, line);

    n = stoi(line);

    if (n <= 0)
    {
        cout << "Ошибка ввода." << endl;
        return false;
    } else {
        cout << "Успешный ввод из файла." << endl;
        return true;
    }
    
}


int getIndex() 
{
    while (true) {
        int a = 0;
        cin >> a;
        if (cin.fail() || a <= 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка ввода." << endl;
        } else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return a;
        }
    }
}


bool get_0_1() 
{
    while (true) {
        char sm;
        cin >> sm;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (sm == '0') {
            return false;
        } else if (sm == '1') {
            return true;
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
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (sm == '0') {
            return false;
        } else if (sm == '1') {
            return true;
        } else {
            cout << "Ошибка ввода." << endl;
        }
    }
}