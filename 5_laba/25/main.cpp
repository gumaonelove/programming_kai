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
        unsigned long long nnum;
        string subsequence;

        try {
            nnum = stoul(argv[1]);
        } catch (const invalid_argument & ia){
            cerr << "Невозможно преобразовать аргументы(ы) в число типа: " << ia.what() << endl;
            return 0;
        }

        getline(cin, subsequence);
        my_function(nnum, subsequence);
        
    } else {
        cout << "Необходимо указать три аргумента командной строки" << endl;
        cout << "1: Число" << endl;
        cout << "2: Последовательность" << endl;
    }

    return 0;
}