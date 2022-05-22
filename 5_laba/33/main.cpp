//
// Created by Булат Гумеров on 16.05.2022.
//

#include <iostream>
#include <string>
#include "myfuncs.h"

int main(int args, char **argv)
{
    using namespace std;
    if (args == 6)
    {   
        unsigned char nbyte;
        string subsequence_1;
        string subsequence_2;
        unsigned long long nnum_1;
        unsigned long long nnum_2;

        try {
            nbyte = static_cast<unsigned char>(stoi(argv[1]));
            subsequence_1 = stoul(argv[2]);
            subsequence_2 = stoul(argv[3]);
            nnum_1 = stoi(argv[4]);
            nnum_2 = stoi(argv[5]);
        } catch (const invalid_argument & ia){
            cerr << "Невозможно преобразовать аргументы(ы) в число типа: " << ia.what() << endl;
            return 0;
        }

        if(nbyte >= 1 && nbyte <= 8) {
            // тут будет вся логика
        } else {
            cout << "Неверно задано значение nbyte." << endl;
            return 0;
        }

    } else {
        cout << "Необходимо указать 5 аргумента командной строки:" << endl;
        cout << "0: Колчество байт для указанных чисел" << endl;
        cout << "1: Последовательность битов в первом числе" << endl;
        cout << "2: Последовательность битов во втором числе" << endl;
        cout << "3: Первое число" << endl;
        cout << "4: Второе число" << endl;
    }

    return 0;
}