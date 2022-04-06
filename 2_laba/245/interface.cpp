#include <iostream>
#include <limits>
#include <string>
#include <fstream>
#include <vector>

#include "functions.h"

const int size_a = 5;
const int size_b = 5;


int n = 0;
bool answer = false;

void init() {
    using namespace std;

    int* A_array = get_array_from_console(size_a);
    while (A_array[0] == -1){
        cout << "Должно быть хотябы одно отрицательное значение";
        int* A_array = get_array_from_console(size_a);
    }

    int* B_array = get_array_from_console(size_b);
    while (B_array[0] == -1){
        cout << "Должно быть хотябы одно отрицательное значение";
        int* B_array = get_array_from_console(size_b);
    }

    vector<int> C_array = get_vector_from_console();
    while (C_array.empty()){
        cout << "Должно быть хотябы одно отрицательное значение";
        vector<int> C_array = get_vector_from_console();
    }


    cout << "Введите натуральное значение n: ";
    while (n <= 0)
    {
        n = getIndex();
	    if (n > 0)
		    break;
        cout << "Введите натуральное значение n: ";
    }

    int a_ind_neg_oc = get_index_negative_occurrence_from_array(A_array, size_a);
    int b_ind_neg_oc = get_index_negative_occurrence_from_array(B_array, size_b);
    int c_ind_neg_oc = get_index_negative_occurrence_from_vector(C_array);

    if ((c_ind_neg_oc < a_ind_neg_oc) && (c_ind_neg_oc < b_ind_neg_oc))
        answer = true;

    n = 0;
}


void file_init (std::ifstream & file) {
    using namespace std;
    string line;
 
    while (n <= 0) {
        getline(file, line);
        n = stoi(line);
        if (n > 0)
            break;
        cout << "Введите натуральное значение n: ";
    }

    int* A_array = get_array_from_file(size_a, file);
    while (A_array[0] == -1){
        cout << "Должно быть хотябы одно отрицательное значение";
        int* A_array = get_array_from_file(size_a, file);
    }

    int* B_array = get_array_from_file(size_b, file);
    while (B_array[0] == -1){
        cout << "Должно быть хотябы одно отрицательное значение";
        int* B_array = get_array_from_file(size_a, file);
    }

    vector<int> C_array = get_vector_from_file(file);
    while (C_array.empty()){
        cout << "Должно быть хотябы одно отрицательное значение";
        vector<int> C_array = get_vector_from_file(file);
    }


    int a_ind_neg_oc = get_index_negative_occurrence_from_array(A_array, size_a);
    int b_ind_neg_oc = get_index_negative_occurrence_from_array(B_array, size_b);
    int c_ind_neg_oc = get_index_negative_occurrence_from_vector(C_array);

    if ((c_ind_neg_oc < a_ind_neg_oc) && (c_ind_neg_oc < b_ind_neg_oc))
        answer = true;
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
