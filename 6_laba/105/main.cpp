#include <iostream>
#include <string>

#include "List.h"
#include "my_functions.h"

using namespace std;

int main(){
    List list; // инициализация списка
    bool exit = false; // сигнал к окончанию работы программы
    list.List_input(); // заполнение списка данными из файла
    while (!exit) // основной цикл программы
    {
        switch (get_num()) // работа пользователя с функционалом программы
        {
            case 1: // поиск элемента
                list.Search();
                break;
            case 2: // если печать данных в отсортированном виде
                list.Sort_data();
                break;
            case 3: // если сброс значений по умолчанию
                list.Set_default();
                break;
            case 4: // печать всех элементов
                list.Show();
                break;
            case 5: // если прекращение работы программы
                exit = true;
                break;
        }
    }
    return 0;
}