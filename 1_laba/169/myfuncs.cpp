#include <iostream>
#include <limits>
#include <string>
#include <fstream>

#include "variables.h"
#include "functions.h"

using namespace std;


bool init() {
    double last_value = -100000000;
    double now_value = 0;
    cout << "Введите значение x: ";
    x = getValue();

    if(checkIndexes()) {
        for(int j = 1; j <= 100; j++) {
            cout << "mass[" << j << "] = ";
            now_value = getValue();
            if (j == 1 && now_value >= x){
                cout << "Неправильно указан(ы) y, по уловию y[1] < x" << endl;
                return false;
            }
            if (j == 100 && x > now_value){
                cout << "Неправильно указан(ы) y, по уловию x <= y[100]" << endl;
                return false;
            }


            if (last_value >= now_value) {
                cout << "Неправильно указан(ы) y, по уловию y[i] < y[i+1]" << endl;
                return false;
            }
            mass.push_back(now_value);
            last_value = now_value;
        }
    } else {
        cout << "Неправильно указан(ы) индекс(ы)" << endl;
        return false;
    }
    return true;
}


bool file_init (ifstream & file) {
    double now_value = 0;
    double last_value = -100000000;
    string line;

    getline(file, line);
    x = stoi(line);
    cout << "x = " << x << endl;

    if(checkIndexes()) {
        for(int j = 1; j <= 100; j++) {
            getline(file, line);
            now_value = stoi(line);
            
            if (j == 1 && now_value >= x){
                cout << "Неправильно указан(ы) y, по уловию y[1] < x" << endl;
                return false;
            }

            if (j == 100 && x > now_value){
                cout << "Неправильно указан(ы) y, по уловию x <= y[100]" << endl;
                return false;
            }

            if (last_value >= now_value) {
                cout << "Неправильно указан(ы) y, по уловию y[i] < y[i+1]" << endl;
                return false;
            }
            
            mass.push_back(now_value);
            last_value = now_value;
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
    return (x <= 100);
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
    int k;
    string answer;
    for(int j = 1; j <= 100; j++) {

        if (mass[j-1] < x && x <= mass[j]) {
            cout << mass[j-1] << '<' << x << '<' << mass[j]  << endl;
            k = j;
            break;
        }
    }
    answer = "Ответ: "  ;
    answer += to_string(k+1);

    return answer;
}