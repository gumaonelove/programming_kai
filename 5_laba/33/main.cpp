//
// Created by Булат Гумеров on 16.05.2022.
//

#include <iostream>
#include <string>
#include "myfuncs.h"

int main(int args, char **argv)
{
    using namespace std;
    if (args == 5)
    {
        unsigned long long nnum_1;
        unsigned long long nnum_2;
        string num_str_1;
        string num_str_2;
        string subsequence_1;
        string subsequence_2;

        try {
            nnum_1 = stoull(argv[3]);
            num_str_1 = to_binary_string(nnum_1);

            nnum_2 = stoull(argv[4]);
            num_str_2 = to_binary_string(nnum_2);
            
        } catch (const invalid_argument & ia){
            cerr << "Невозможно преобразовать аргументы(ы) в число типа: " << ia.what() << endl;
            return 0;
        }

        subsequence_1 = get_string_from_arr_char(argv[1]);
        subsequence_2 = get_string_from_arr_char(argv[2]);


         my_function(subsequence_1, subsequence_2, num_str_1, num_str_2);
     
    } else {
        cout << "Необходимо указать 4 аргумента командной строки" << endl;
        cout << "1: Последовательность битов первого числа" << endl;
        cout << "2: Последовательность битов второго числа" << endl;
        cout << "3: Первое число" << endl;
        cout << "4: Второе число" << endl;
    }

    return 0;
}