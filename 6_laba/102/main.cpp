#include <iostream>

#include "functions.h"

int main()
{
    using namespace std;
    get_navigation();

    while (true){
        switch (getIndex()){
            case 1:
                cout << "Добавить новый элемент:" << endl;
                cout << "Введите строку необходимую для вставки:" << endl;
                continue;
            case 2:
                cout << "Печать всех элементов в отсортированном виде" << endl;
                continue;
            case 3:
                cout << "Сброс значений всех элементов" << endl;
                continue;
            default:
                cout << "Указан неверный номер, повтороите попытку" << endl;
                continue;
        }
    }
    return 0;
}