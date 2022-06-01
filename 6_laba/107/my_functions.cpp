//
// Created by Булат Гумеров on 31.05.2022.
//
#include <iostream>
#include "List.h"

using namespace std;

void _get_navigation_text() {
    cout << "Что требуется сделать?" << endl;
    cout << "1 - Проверить входит ли элемент в список" << endl;
    cout << "2 - Печать всех элементов в отсортированном виде" << endl;
    cout << "3 - Сброс значений всех элементов" << endl;
    cout << "4 - Печать данных из файла" << endl;
    cout << "5 - Выйти из программы" << endl;
}


int get_num() { // функция получения от пользователя указаний к работе программы
    short unsigned int num;

    _get_navigation_text();

    cout << "Ожидание пользовательского ввода: ";
    while (!(cin >> num) || cin.peek() != '\n' || num != 1 and num != 2 and num != 3 and num != 4 and num != 5) {
        cin.clear(); // очищение флагов ошибки ввода
        while (cin.get() != '\n'); // очищение буфера cin
        cout << "\nОшибка ввода. Введите корректное значение: ";
    }
    return num;
}

bool string_comparison(string str_1, string str_2){
    if (str_1.size() == str_2.size() - 1){
        for (int i = 0; i < str_1.size(); i++){
            if (str_1[i] != str_2[i])
                return false;
        }
        return true;
    } else {
        return false;
    }
}