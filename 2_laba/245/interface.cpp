#include <iostream>
#include <limits>
#include <string>
#include <fstream>
#include <vector>

#include "functions.h"

int n = 0;
int g_A_array[30] = {};
int g_B_array[40] = {};
std::vector<int> g_C_array;


void init() {
    using namespace std;
    bool is_negative_in_a = false;
    bool is_negative_in_b = false;
    bool is_negative_in_c = false;
    int now_value = 0;

    cout << "Введите натуральное значение n: ";
    while (n <= 0)
    {
        n = getIndex();
	    if (n > 0)
		    break;
        cout << "Введите натуральное значение n: ";
    }

    for (int i = 0; i < 30; i++)
    {
        cout << "a[" << i + 1 << "] = ";
        now_value = getIndex();
        g_A_array[i] = now_value;
        if (now_value < 0)
            is_negative_in_a = true;
    }

    for (int i = 0; i < 40; i++)
    {
        cout << "b[" << i + 1 << "] = ";
        now_value = getIndex();
        g_B_array[i] = now_value;
        if (now_value < 0)
            is_negative_in_b = true;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "c[" << i + 1 << "] = ";
        now_value = getIndex();
        g_C_array.push_back(now_value);
        if (now_value < 0)
            is_negative_in_c = true;
    }

    n= 0;
}


void file_init (std::ifstream & file) {
    using namespace std;
    double now_value;
    string line;
    while (n <= 0) {
        getline(file, line);
        n = stoi(line);
        if (n > 0)
            break;
        cout << "Введите натуральное значение n: ";
    }

    for (int i = 0; i < 30; i++)
    {
        getline(file, line);
        g_A_array[i] = stoi(line);
    }

    for (int i = 0; i < 40; i++)
    {
        getline(file, line);
        g_B_array[i] = stoi(line);
    }

    for (int i = 0; i < n; i++)
    {
        getline(file, line);
        g_C_array.push_back(stoi(line));
    }

    n = 0;
}


int getIndex() {
    using namespace std;

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


char get_0_1() {
    using namespace std;

    while (true) {
        char sm;
        cin >> sm;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (sm == '0' || sm == '1') {
            return sm;
        } else {
            cout << "Ошибка ввода." << endl;
        }
    }
}


bool getNext() {
    using namespace std;

    cout << "Продолжаем? (0 - нет, 1 - да): ";
    while (true) {
        char sm;
        cin >> sm;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (sm == '0' || sm == '1') {
            return sm == '1';
        } else {
            cout << "Ошибка ввода." << endl;
        }
    }
}
