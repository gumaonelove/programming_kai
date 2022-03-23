#include <iostream>
#include <limits>
#include <string>
#include <fstream>
#include <tuple>

#include "variables.h"
#include "functions.h"

using namespace std;


bool init() {
    string line;
    cout << "Введите значение n: ";
    n = getIndex();

    if(checkIndexes()) {
        for(int j = 1; j <= n; j++) {
            line = getValue();
            my_vector.push_back(0, 0);
        }
    } else {
        cout << "Неправильно указан(ы) индекс(ы)" << endl;
        return false;
    }
    return true;
}


bool file_init (ifstream & file) {
    string now_line;
    string line;

    getline(file, line);
    n = stoi(line);

    if(checkIndexes()) {
        for(int j = 1; j <= n; j++) {
            getline(file, line);
            now_line = line;
            my_vector.push_back(0);
        }
    } else {
        cout << "Неправильно указан(ы) индекс(ы)" << endl;
        return false;
    }
    return true;
}


string getValue() {
    while (true) {
        string line;
        cin >> line;
        if (cin.fail()) {
            cin.clear();
            cout << "Ошибка ввода." << endl;
        } else { 
            return line;
        }
    }
}


int getIndex() {
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


bool checkIndexes() {
    return (i <= n);
}


char get_0_1() {
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


bool getNext() {
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


string average() {
}