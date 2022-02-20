#include <iostream>
#include <istream>
#include <fstream>
#include <limits>

bool init() {
    using namespace std;
    int n; // array size
    int a_i;

    cout << "Введите n: "; // user input n
    cin >> n; // from user to n

    int *my_array = new int[n]; // allocating memory for an array
    
    for (int i = 0; i < n; i++) { // array filling
        cout << "Введите a[" << i << "]: "; // user input a[i]
        cin >> a_i;
        my_array[i] = a_i;
    }
    return true;
}

bool finit (std::ifstream & f, ) {
    for (unsigned i = 0; i < n; i++) {
        f >> my_array[i]; // from file to out array
        if (f.fail()) {
            std::cout << "Ошибка ввода из файла элемента [" << i << "]." << std::endl;
            return false;
        }
    }
    return true;
}

void fsum(std::ostream & f) {
    f << "Исходный массив: " << std::endl;
    for (unsigned i = 0; i < n; i++) {
        for (unsigned j = 0; j < n; j++) {
            f << mass[i][j] << "\t";
        }
        f << std::endl << std::endl;
    }
    f << "Сума строк: " << i1 + 1 << " и " << i2 + 1 << ": " << std::endl;
    for (unsigned i = 0; i < n; i++) {
        f << mass[i1][i] + mass[i2][i] << "\t";
    }
    f << std::endl << std::endl;
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

