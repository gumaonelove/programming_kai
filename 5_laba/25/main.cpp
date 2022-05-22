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
        string num_str;
        string subsequence;

        try {
            nnum = stoul(argv[1]);
            num_str = to_binary_string(nnum);
            
        } catch (const invalid_argument & ia){
            cerr << "Невозможно преобразовать аргументы(ы) в число типа: " << ia.what() << endl;
            return 0;
        }

        subsequence = get_string_from_arr_char(argv[2]);
        cout << "number " << nnum << " = " << num_str << endl;
        cout << "subsequence = " << subsequence << endl;
        int index = r_find(num_str, subsequence);
        if (index == -100){
            cout << "Данная последовательность не встречается";      
        } else {
            cout << "index = " << index << endl;
        }
            
    } else {
        cout << "Необходимо указать три аргумента командной строки" << endl;
        cout << "1: Число" << endl;
        cout << "2: Последовательность" << endl;
    }

    return 0;
}