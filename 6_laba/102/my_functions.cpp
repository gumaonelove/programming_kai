//
// Created by Булат Гумеров on 31.05.2022.
//
#include <iostream>
#include "List.h"

using namespace std;

void _get_navigation_text() {
    cout << "Что требуется сделать?" << endl;
    cout << "1 - Добавить новый элемент" << endl;
    cout << "2 - Печать всех элементов в отсортированном виде" << endl;
    cout << "3 - Сброс значений всех элементов" << endl;
    cout << "4 - Печать данных из файла" << endl;
    cout << "5 - Выйти из программы" << endl;
}


int get_num() { // функция получения от пользователя указаний к работе программы
    short unsigned int num;

    _get_navigation_text();

    cout << "Ожидание пользовательского ввода: ";
    while (!(cin >> num) || cin.peek() != '\n' || num != 1 and num != 2 and num != 3 and num != 4) {
        cin.clear(); // очищение флагов ошибки ввода
        while (cin.get() != '\n'); // очищение буфера cin
        cout << "\nОшибка ввода. Введите корректное значение: ";
    }
    return num;
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