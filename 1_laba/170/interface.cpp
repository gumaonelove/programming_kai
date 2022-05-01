#include <iostream>
#include <limits>
#include <fstream>

#include <string>
#include<vector>
#include <map>

#include "functions.h"

using namespace std;

vector<double> my_vector;
map<double, double> my_dict;

int n;


bool init() 
{
    double now_value;
    cout << "Введите значение n: ";
    n = getIndex();

    my_vector.push_back(0); // По условиям задачи индексация начинается с единицы,
    // для удобства положим в первую ячейку вектора ноль

    if(checkIndexes()) 
    {
        for(int j = 1; j <= n; j++) {
            cout << "my_vector[" << j << "] = ";
            now_value = getValue();
            my_vector.push_back(now_value);
            if (my_dict.count(now_value) == 0)
                my_dict[now_value] = j;
        }
    } else {
        cout << "Неправильно указан индекс 'n' " << endl;
        return false;
    }
    return true;
}


bool file_init (ifstream & file) 
{
    double now_value;

    n = getNumberFromFile(file);
    cout << "n = " << n << endl;

    my_vector.push_back(0); // По условиям задачи индексация начинается с единицы,
    // для удобства положим в первую ячейку вектора ноль

    if(checkIndexes()) 
    {
        for(int j = 1; j <= n; j++) {
            now_value = getDoubleFromFile(file);
            cout << "my_vector[" << j << "] = " << now_value << endl;
            my_vector.push_back(now_value);
            if (my_dict.count(now_value) == 0)
                my_dict[now_value] = j;
        }
    } else {
        cout << "Неправильно указан индекс 'n' " << endl;
        return false;
    }
    return true;
}


int getIndex() 
{
    while (true) 
    {
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

double getValue()
{
    while (true)
    {
        double a;
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


int getNumberFromFile(ifstream & file)
{
    while (true) 
    {
        int a;
        file >> a;
        if (file.fail()) {
            file.clear();
            file.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка ввода." << endl;
        } else {
            file.ignore(numeric_limits<streamsize>::max(), '\n');
            return a;
        }
    }
}


double getDoubleFromFile(ifstream & file)
{
    while (true)
    {
        double a;
        file >> a;
        if (file.fail()) {
            file.clear();
            file.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка ввода." << endl;
        } else {
            file.ignore(numeric_limits<streamsize>::max(), '\n');
            return a;
        }
    }
}


bool checkIndexes() 
{
    return (n >= 4);
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