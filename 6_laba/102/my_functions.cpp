#include <string>
#include <algorithm>
#include <iostream>

#include "my_functions.h"
#include "my_structs.h"

void case_1 (List list){
    std::cout << "Добавить новый элемент: " << std::endl;
    std::cout << "Введите строку необходимую для вставки:" << std::endl;
    int index = getIndex();
    std::cout << "Введите строку данных для вставки, пример (Ф;И;О;возраст;семейное положение)" << std::endl;
    std::string line;
    getline(std::cin, line);
    
    list.add_element(index, line);

    std::cout << "Вставка произведена, обновленный список:" << std::endl;
    list.print();
}

void case_2(List* list){
    unsigned indso = 0;

    std::cout << "Печать всех элементов в отсортированном виде" << std::endl;
    std::cout << "Сортировка по: " << std::endl;
    std::cout << "по фамилии \t 1" << std::endl;
    std::cout << "по имени \t 2" << std::endl;
    std::cout << "по отчеству \t 3" << std::endl;
    std::cout << "по возрасту \t 4" << std::endl;
    std::cout << "по семейному положению \t 5" << std::endl;

    indso = getValueOfRange(1, 5);
    return std::sort(list, [](std::string s1, std::string s2) -> bool { return s1 < s2 ? true : false; }, indso);
}

void case_3(List list){
    std::cout << "Сброс значений всех элементов" << std::endl;
    list.reset_list();
}

int getValueOfRange(int start, int finish){
    while (true){
        int n = getIndex();
        if (n >= start && n <= finish){
            return n;
        } else {
            std::cout << "Введен неверный индекс, повторите попытку" << std::endl;
        }
    }
}