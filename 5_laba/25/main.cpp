//
// Created by Булат Гумеров on 16.05.2022.
//

#include <iostream>
#include <string>
#include "myfuncs.h"

int main(int args, char **argv)
{
    if (args == 3)
    {
        unsigned long long nnum;
        std::string num_str;
        std::string subsequence;

        try {
            nnum = std::stoull(argv[1]);
            num_str = to_binary_string(nnum);
            
        } catch (const std::invalid_argument & ia){
            std::cerr << "Невозможно преобразовать аргументы(ы) в число типа: " << ia.what() << std::endl;
            return 0;
        }

        subsequence = get_string_from_arr_char(argv[2]);
        std::cout << "number " << nnum << " = " << num_str << std::endl;
        std::cout << "subsequence = " << subsequence << std::endl;
        int index = r_find(num_str, subsequence);
        if (index == -100){
            std::cout << "Данная последовательность не встречается" << std::endl;
        } else {
            std::cout << "index = " << index << std::endl;
        }
            
    } else {
        std::cout << "Необходимо указать три аргумента командной строки" << std::endl;
        std::cout << "1: Число" << std::endl;
        std::cout << "2: Последовательность" << std::endl;
    }

    return 0;
}