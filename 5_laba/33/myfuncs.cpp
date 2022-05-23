//
// Created by Булат Гумеров on 16.05.2022.
//

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <fstream>
#include "myfuncs.h"


std::string to_binary_string(unsigned long long n)
{
    if (n < 0)
        n *= -1;
    std::string buffer; // символы ответа в обратном порядке
    // выделим память заранее по максимуму
    buffer.reserve(std::numeric_limits<unsigned long long>::digits);
    do{
        buffer += char('0' + n % 2); // добавляем в конец
        n = n / 2;
    } while (n > 0);

    std::cout << "n = " << n << std::string(buffer.crbegin(), buffer.crend()) << std::endl;
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

    ofstream file_out("debug.txt");

    int i_start_1 = get_indexes(subsequence_1)[0];
    int i_end_1 = get_indexes(subsequence_1)[1];
    int i_start_2 = get_indexes(subsequence_2)[0];
    int i_end_2 = get_indexes(subsequence_2)[1];

    int len = i_end_1 - i_start_1 + 1;

    if (len != i_end_2 - i_start_2 + 1){
        cout << "Последовательности имеют разную длину" << endl;
        return;
    }

    file_out << "len = " << len << endl;

    for (int i = 0; i < len; i++)
    {
        file_out << "num_str_1[" << i + i_start_1 << "] = " << num_str_1[i + i_start_1] << endl;
        file_out << "num_str_2[" << i + i_start_2 << "] = " << num_str_2[i + i_start_2] << endl;
        if (num_str_1[i + i_start_1] != num_str_2[i + i_start_2]){
            cout << "Последовательности не совпадают" << endl;
            return;
        }
    }

    cout << "Последовательности совпадают" << endl;
}