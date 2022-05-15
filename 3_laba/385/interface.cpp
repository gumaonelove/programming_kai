#include <iostream>
#include <limits>
#include <fstream>

#include <string>
#include <vector>

#include "functions.h"

using namespace std;

int n = 0;
vector< vector <double> > my_matrix;


void init()
{
    string now_str;
    vector  <double> now_vector;

    cout << "Введите значение n: ";
    n = getIndexFromConsole();
    int count_vectors = 0;

    while (count_vectors != n)
    {
        cout << "Введите строку матрицы (разделитель = ' ') " << count_vectors << ": " << endl;
        now_str = getStringFromConsole();
        now_vector = get_vector(now_str, count_vectors);
        if (now_vector.size() == n){
            my_matrix.push_back(now_vector);
            count_vectors += 1;
        } else {
            cout << "Количество символов в строке должно быть n, повторите ввод" << endl;
        }

    }
}


void file_init (ifstream & file)
{   
    string now_str;
    vector  <double> now_vector;
    n = getIndexFromFile(file);
    cout << "Введено значение n = " << n << endl;

    int count_vectors = 0;

    while (count_vectors != n)
    {
        getline(file, now_str);
        now_vector = get_vector(now_str, count_vectors);
        if (now_vector.size() == n) {
            my_matrix.push_back(now_vector);
            count_vectors += 1;
        } else {
            cout << "Количество символов в строке должно быть n, измените файл in.txt" << endl;
            break;
        }
    }

    cout << "Ответ в файле out.txt" << endl;
}


int getIndexFromConsole() 
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


string getStringFromConsole()
{
    while (true)
    {
        string line = "";
        getline(cin, line);
        if (cin.fail()) {
            cin.clear();
            cout << "Ошибка ввода." << endl;
        } else {
            return line;
        }
    }
}


int getIndexFromFile(ifstream & file) 
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


bool get_0_1() 
{
    while (true)
    {
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
    while (true)
    {
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