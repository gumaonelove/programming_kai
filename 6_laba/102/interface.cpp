#include <iostream>
#include <limits>

void get_navigation(){
    std::cout << "Функционал:" << std::endl;
    std::cout << "1) Добавить новый элемент" << std::endl;
    std::cout << "2) Печать всех элементов в отсортированном виде" << std::endl;
    std::cout << "3) Сброс значений всех элементов" << std::endl;
}


int getIndex() {
    while (true){
        int a;
        std::cin >> a;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка ввода." << std::endl;
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return a;
        }
    }
}