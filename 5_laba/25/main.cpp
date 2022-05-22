//
// Created by Булат Гумеров on 16.05.2022.
//

#include <iostream>
#include <string>
#include "myfuncs.h"

int main(int args, char **argv)
{
    using namespace std;
    if (args == 3)
    {
        unsigned char nbyte;
        unsigned long long nnum;
        unsigned long long copynnum = nnum;

        try {
            nbyte = static_cast<unsigned char>(stoi(argv[1]));
            nnum = stoul(argv[2]);
        } catch (const invalid_argument & ia){
            cerr << "Невозможно преобразовать аргументы(ы) в число типа: " << ia.what() << endl;
            return 0;
        }

        if(nbyte >= 1 && nbyte <= 8) {
            nnum = shiftr(nbyte, nnum);
        } else {
            cout << "Неверно задано значение nbyte." << endl;
            return 0;
        }

        cout << "Исходное значение nnum: \t\t\t" << copynnum << endl;
        cout << "Значение после циклического сдвига вправо: " << nnum << endl;
    } else {
        cout << "Необходимо указать два аргумента командной строки" << endl;
    }

    return 0;
}