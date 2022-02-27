#include <iostream>
#include <istream>
#include <fstream>
#include <limits>

double getValue();
int n = 0;

int get_n() {
    using namespace std;
    if (n == 0) {
        cout << "Введите n: "; // user input n
        int n = getValue(); // array size
    }
    return n;
}

int *my_array = new int[get_n()]; // allocating memory for an array

bool init () {
    using namespace std;
    int a_i;

    for (int i = 0; i < n; i++) { // array filling
        cout << "Введите a[" << i << "]: "; // user input a[i]
        my_array[i] =  getValue();
    }
    return true;
}

bool finit (std::ifstream & f) {
    using namespace std;
    for (unsigned i = 0; i < n; i++) {
        f >> my_array[i]; // from file to out array
        if (f.fail()) { // error handler
            cout << "Ошибка ввода из файла элемента [" << i << "]." << endl;
            return false;
        } else {
            if (i % 3 == 0) {
                cout << "Круг (" << my_array[i] << ", " << my_array[i+1] << "), с радиусом r = " << my_array[i+2] << endl;
                cout << "Построен и закрашен!";
            }
        }
    }
    return true;
}

void main_func(std::ostream & f) {
    using namespace std;
    f << "Исходный массив: " << endl;
    for (unsigned i = 0; i < n; i++) {
        f << my_array[i] << '\t';
    }
    f << endl << endl;
}

double getValue() {
    using namespace std;
    while (true) {
        double a;
        cin >> a;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка ввода. \n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return a;
        }
    }
}

bool getNext() {
    using namespace std;
    cout << "Продолжить? (0 - нет, 1 - да): ";
    while (true) {
        char sm;
        cin >> sm;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (sm == '0' || sm == '1') {
            return sm == '1' ? true : false;
        } else {
            cout << "Ошибка ввода. \n";
        }
    }
}

unsigned char get_0_1() {
    using namespace std;
    while (true) {
        char sm;
        cin >> sm;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (sm == '0' || sm == '1') {
            return sm;
        } else {
            cout << "Ошибка ввода. \n";
        }
    }
}

