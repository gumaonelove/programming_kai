//
// Created by Булат Гумеров on 16.05.2022.
//

#include <iostream>
#include <string>
#include<limits>
#include "myfuncs.h"


std::string to_binary_string(unsigned int n)
{
    std::string buffer; // символы ответа в обратном порядке
    // выделим память заранее по максимуму
    buffer.reserve(std::numeric_limits<unsigned int>::digits);
    do
    {
        buffer += char('0' + n % 2); // добавляем в конец
        n = n / 2;
    } while (n > 0);
    return std::string(buffer.crbegin(), buffer.crend()); // разворачиваем результат
}


std::string get_string_from_arr_char(char *args)
{
    std::string str = "";
    for(int i = 0; i < args[i] != '\0'; i++){
       str += args[i];
    }
    return str;
}


int r_find(std::string my_string, std::string my_substring)
{

    int last_index = -100;
    for (int i = 0; i < my_string.length(); i++) 
    {
        bool flag = true;
        for (int j = 0; j < my_substring.length(); j++){
            // std::cout << "my_string = " << my_string[i + j] << "|   my_substring = " << my_substring[j] << std::endl;
            flag *= bool(my_string[i + j] == my_substring[j]);
        };
        if (flag){
            // std::cout << "i = "<< i << std::endl;
            last_index = i;
        }       
    }

    return last_index;
}