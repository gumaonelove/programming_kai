#include <iostream>
#include <limits>
#include <string>
#include <fstream>

#include "variables.h"
#include "functions.h"

using namespace std;


bool init() {
    cout << "Введите значение i: ";
    i = getIndex();
    cout << "Введите значение n: ";
    n = getIndex();

    mass.push_back(0); // По условиям задачи индексация начинается с единицы,
    // для удобства положим в первую ячейку вектора ноль

    if(checkIndexes()) {
        for(int j = 1; j <= n; j++) {
            cout << "mass[" << j << "] = ";
            mass.push_back(getValue());
        }
    } else {
        cout << "Неправильно указан(ы) индекс(ы)" << endl;
        return false;
    }
    return true;
}


bool file_init (ifstream & file) {
    double now_value;
    string line;

    getline(file, line);
    i = stoi(line);
    cout << "i = " << i << endl;
    getline(file, line);
    n = stoi(line);
    cout << "n = " << n << endl;

    mass.push_back(0);

    if(checkIndexes()) {
        for(int j = 1; j <= n; j++) {
            getline(file, line);
            cout << "mass[" << j << "] = " << line << endl;
            now_value = stoi(line);
            mass.push_back(now_value);
        }
    } else {
        cout << "Неправильно указан(ы) индекс(ы)" << endl;
        return false;
    }
    return true;
}


double getValue() {
    while (true) {
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
    double sum = 0;
    string answer;
    for(int j = 1; j <= n; j++) {
        if ( j != i) {
            sum += mass[j];
        }
    }
    answer = "Ответ: "  ;
    answer += to_string(sum / (n - 1));

    return answer;
}