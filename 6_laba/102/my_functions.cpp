#include <string>
#include <algorithm>

#include "functions.h"
#include "my_structs.h"

void case_1 (List list){
    cout << "Добавить новый элемент: " << endl;
    cout << "Введите строку необходимую для вставки:" << endl;
    int index = getIndex();
    cout << "Введите строку данных для вставки, пример (Ф;И;О;возраст;семейное положение)" << endl;
    string line;
    getline(cin, line);
    
    list.add_element(index, line);

    cout << "Вставка произведена, обновленный список:" << endl;
    list.print();
}

void case_2(List* list){
    cout << "Печать всех элементов в отсортированном виде" << endl;
    unsigned indso{0};
    cout << "Сортировка по: " << endl;
    cout << "по фамилии \t 1" << endl;
    cout << "по имени \t 2" << endl;
    cout << "по отчеству \t 3" << endl;
    cout << "по возрасту \t 4" << endl;
    cout << "по семейному положению \t 5" << endl;

    indso = getValueOfRange(1, 5);
    return sort(list, [](string s1, string s2) -> bool {return s1 < s2 ? true : false; }, indso);
}

void case_3(List list){
    cout << "Сброс значений всех элементов" << endl;
    list.reset_list();
}

int getValueOfRange(int start, int finish){
    while (true){
        int n = getIndex();
        if (n >= start && n <= finish){
            return n;
        } else {
            cout << "Введен неверный индекс, повторите попытку" << endl;
        }
    }
}