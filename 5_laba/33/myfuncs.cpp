//
// Created by Булат Гумеров on 16.05.2022.
//

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "myfuncs.h"


std::string to_binary_string(unsigned int n)
{
    if (n < 0)
        n *= -1
    std::string buffer; // символы ответа в обратном порядке
    // выделим память заранее по максимуму
    buffer.reserve(std::numeric_limits<unsigned int>::digits);
    do{
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

std::vector <int> get_indexes(std::string subsequence)
{
    using namespace std;

    string s_start = "";
    string s_end = "";
    vector <int> indexes;
    bool flag = false;

    for (int i = 0; i < subsequence.length(); i++)
    {
        if (subsequence[i] != '_' && !flag)
            s_start += subsequence[i];
        if (subsequence[i] == '_'){
            flag = true;
        } else if (flag){
            s_end += subsequence[i];
        }
    }

    indexes.push_back(stoi(s_start));
    indexes.push_back(stoi(s_end));

    return indexes;
}

void my_function(std::string subsequence_1, std::string subsequence_2, std::string num_str_1, std::string num_str_2)
{
    using namespace std;

    int i_start_1 = get_indexes(subsequence_1)[0];
    int i_end_1 = get_indexes(subsequence_1)[1];
    int i_start_2 = get_indexes(subsequence_2)[0];
    int i_end_2 = get_indexes(subsequence_2)[1];

    int len = i_end_1 - i_start_1;

    if (len != i_end_2 - i_start_2){
        cout << "Последовательности имеют разную длину" << endl;
        return;
    }

    for (int i = 0; i < len; i++)
    {
        if (num_str_1[i + i_start_1] != num_str_1[i + i_start_2]){
            cout << "Последовательности не совпадают" << endl;
            return;
        }
    }

    cout << "Последовательности совпадают" << endl;
}