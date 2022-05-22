#include <iostream>
#include <limits>
#include <fstream>

#include <string>
#include <vector>

#include "functions.h"

int n = 0;


std::vector< std::vector <double> > get_matrix(bool from_file, std::ifstream & file)
{
    using namespace std;

    string now_str;
    vector  <double> now_vector;
    vector< vector <double> > my_matrix;

    cout << "Введите значение n: ";
    if (from_file){
        n = getIndexFromFile(file);
    } else {
        n = getIndexFromConsole();
    }
    
    int count_vectors = 0;

    while (count_vectors != n)
    {
        if (from_file){
            getline(file, now_str);
        } else {
            cout << "Введите строку матрицы (разделитель = ' ') " << count_vectors << ": " << endl;
            getline(cin, now_str);
        }
        
        now_vector = get_vector(now_str, count_vectors);
        if (now_vector.size() == n){
            my_matrix.push_back(now_vector);
            count_vectors += 1;
        } else {
            cout << "Количество символов в строке должно быть n, повторите ввод" << endl;
        }
    }

    return my_matrix;
}


int getIndexFromConsole() 
{
    using namespace std;

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


int getIndexFromFile(std::ifstream & file) 
{
    using namespace std;

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
    using namespace std;

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
    using namespace std;

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