#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <vector>

#include "functions.h"

using namespace std;

vector<char> my_vector;
extern int n;


string get_file_url()
{
    string _file_url;
    getline(cin, _file_url);
    return _file_url;
}


bool init()
{
    cout << "Введите значение n: ";
    n = getIndex();

    if (n > 0)
    {
        char now_character;
        my_vector.push_back('0');

        for (int i = 1; i <= n; i ++) 
        {
            cout << "S[" << i << "] = ";
            my_vector.push_back(cin.get());
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        return true;
    } else 
    {
        cout << "Ошибка ввода." << endl;
        cout << "По условию задачи n - натуральное число." << endl;
        return false;
    }
    
}


bool file_init (ifstream & file)
{   
    string line;
    getline(file, line);

    n = stoi(line);

    if (n <= 0)
    {
        cout << "Ошибка ввода." << endl;
        cout << "По условию задачи n - натуральное число." << endl;
        return false;
    } else {
        cout << "Успешный ввод из файла." << endl;

        char now_character;

        my_vector.push_back('0');

        for (int i = 1; i <= n; i ++) 
        {
            file >> now_character;
            my_vector.push_back(now_character);
        }

        return true;
    }
    
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
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (sm == '0' || sm == '1') {
            return sm == '1';
        } else {
            cout << "Ошибка ввода." << endl;
        }
    }
}