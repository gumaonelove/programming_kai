#include <iostream>
#include <fstream>
#include <vector>

#include "functions.h"

using namespace std;

int n = 0;
extern vector<char> my_vector;

int main()
{
    bool from_file;
    bool to_file;

    while (true)
    {
        cout << "Ввод с консоли (0) или из файла (1): ";
        from_file = get_0_1();

        cout << "Вывод в консоль (0) или в файл (1): ";
        to_file = get_0_1();

        if (!from_file && !to_file) // из консоли в консоль
        {
            if (init())
            {
                cout << my_function() << endl;
                my_vector.clear();
            }

            if(getNext()) {
                continue;
            } else {
                cout << "До скорой встречи." << endl;
                break;
            }
        } else if (!from_file && to_file) // from console to file
        {
            cout << "Укажите адрес вывода результатов работы программы, " << endl;
            cout << "Пример: '~/rez/out.txt' => ";
            string file_out_url = get_file_url();
            if (file_out_url.empty())
                file_out_url = "out.txt";

            ofstream file_out(file_out_url);

            if (init())
            {
                file_out << my_function() << endl;
                my_vector.clear();
            }
            file_out.close();

            if(getNext()) {
                continue;
            } else {
                cout << "До скорой встречи." << endl;
                break;
            }

        } else if (from_file && to_file) // from file to file
        {
            cout << "Укажите адрес файла для ввода данных, " << endl;
            cout << "Пример: '~/rez/in.txt' => ";
            string file_in_url = get_file_url();
            if (file_in_url.empty())
                file_in_url = "in.txt";
            ifstream file_in(file_in_url);

            cout << "Укажите адрес вывода результатов работы программы, " << endl;
            cout << "Пример: '~/rez/out.txt' => ";
            string file_out_url = get_file_url();
            if (file_out_url.empty())
                file_out_url = "out.txt";
            ofstream file_out(file_out_url);

            if (file_init(file_in))
            {
                file_out << my_function() << endl;
                my_vector.clear();
            }
            file_in.close();
            file_out.close();

            break;
        } else if (from_file && !to_file) // from file to console
        {
            cout << "Укажите адрес файла для ввода данных, " << endl;
            cout << "Пример: '~/rez/in.txt' => ";

            string file_in_url = get_file_url();
            if (file_in_url.empty())
                file_in_url = "in.txt";
            ifstream file_in(file_in_url);

            if (file_init(file_in))
            {
                cout << my_function() << endl;
                my_vector.clear();
            }
            file_in.close();
            break;
        }
    }
    return 0;
}