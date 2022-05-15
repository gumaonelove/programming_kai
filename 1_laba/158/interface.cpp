#include <iostream>
#include <string>
#include <fstream>
#include <limits>

#include "functions.h"

using namespace std;

extern int n;

void init()
{
    int now_number;

    cout << "Введите значение n: ";
    n = getIndex();

    for(int j = 0; j < 39; j++)
    {
        now_number = getIndex();
        my_arr[j] = now_number;
    }
}


void file_init(ifstream & file)
{
    string line;
    getline(file, line);
    n = stoi(line);

    for(int j = 0; j < 39; j++)
    {
        getline(file, line);
        my_arr[j] = stoi(line);
    }

}


int getIndex()
{
    while (true)
    {
        int a;
        cin >> a;
        if (cin.fail())
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


char get_0_1()
{
    while (true) 
    {
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
    while (true) 
    {
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