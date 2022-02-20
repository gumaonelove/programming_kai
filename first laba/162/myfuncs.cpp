#include <iostream>
#include <istream>
#include <fstream>
#include <limits>

extern const unsigned NM{3};
extern double mass[NM][NM];
extern unsigned i1;
extern unsigned i2;

unsigned getIndex();
double getValue();
bool checkIndexes();

bool init() {
    std::cout << "Введите 1-й индекс: ";
    i1 = getIndex();
    std::cout << "Введите 2-й индекс: ";
    i2 = getIndex();
    
    if(checkIndexes()) {
        for(unsigned i = 0; i < NM; i++) {
            for(unsigned j = 0; j<NM; j++) {
                std::cout << "[" << i << "][" << j << "] = ";
                mass[i][j] getValue();
            }
        }
    } else {
        std::cout << "Ошибочно указан(ы) индкес(ы) складываемых строк." << std:: endl;
        return false;
    } 
    return true;
    
}

bool finit (std::ifstream & f) {
    f >> i1;
    if (f.fail()) {
        std::cout << "Ошибка ввода из файла 1-го индекса." << std::endl;
        return false;
    }

    f >> i2;
    if (f.fail()) {
        std::cout << "Ошибка ввода из файла 2-го индекса." << std::endl;
        return false;
    }

    if (checkIndexes()) {
        for (unsigned i = 0; i < NM; i++) {
            for (unsigned j = 0; j < NM; j++) {
                f >> mass[i][j];
                if (f.fail()) {
                    std::cout << "Ошибка ввода из файла элемента [" << i << "][" << j << "]." << std::endl;
                    return false;
                }
            }
        }
    } else {
        std::cout << "Ошибочно указан(ы) индексы складываемых строк." << std::endl;
        return false;
    }
    return true;
}

void fsum(std::ostream & f) {
    f << "Исходный массив: " << std::endl;
    for (unsigned i = 0; i < NM; i++) {
        for (unsigned j = 0; j < NM; j++) {
            f << mass[i][j] << "\t";
        }
        f << std::endl << std::endl;
    }
    f << "Сума строк: " << i1 + 1 << " и " << i2 + 1 << ": " << std::endl;
    for (unsigned i = 0; i < NM; i++) {
        f << mass[i1][i] + mass[i2][i] << "\t";
    }
    f << std::endl << std::endl;
}

unsigned getIndex() {
    while (true) {
        unsigned a;
        std::cin >> a;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка ввода. \n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return a;
        }
    }
}

double getValue() {
    while (true) {
        double a;
        std::cin >> a;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка ввода. \n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return a;
        }
    }
}

bool getNext() {
    std:: cout << "Продолжить? (0 - нет, 1 - да): ";
    while (true) {
        char sm;
        std::cin >> sm;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (sm == '0' || sm == '1') {
            return sm == '1' ? true : false;
        } else {
            std::cout << "Ошибка ввода. \n";
        }
    }
}

unsigned char get_0_1() {
    while (true) {
        char sm;
        std::cin >> sm;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (sm == '0' || sm == '1') {
            return sm;
        } else {
            std::cout << "Ошибка ввода. \n";
        }
    }
}

bool checkIndexes() {
    return (i1 >= 0 && i1 < NM && i2 >= 0 && i2 < NM) ? true : false;
}