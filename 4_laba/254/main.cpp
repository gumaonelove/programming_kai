#include <iostream>
#include <fstream>
#include <vector>

#include "functions.h"

using namespace std;

int n = 0;
extern vector<char> my_vector;

int main() 
{
    string file_url = get_file_url();
    ofstream file_out(file_url);

    if (!file_out.is_open())
        ofstream file_out("out.txt");

    ifstream file_in("in.txt");
    
    unsigned char from_file;
    unsigned char to_file;
    while (true) 
    {
        if (file_in.is_open() && file_out.is_open()) 
        {
            cout << "Ввод с консоли (0) или из файла (1): ";
            from_file = get_0_1();
            cout << "Вывод на консоль (0) или в файл (1): ";
            to_file = get_0_1();
            if (!from_file && !to_file) // из консоли в консоль
            {
                if (init())
                    cout << my_function() << endl;
                    my_vector.clear();
                
                if(getNext()) {
                    continue;
                } else {
                    cout << "До скорой встречи." << endl;
                    break;
                }
            } else if (!from_file && to_file) // из консоли в файл
            { 
                if (init())
                    file_out << my_function() << endl;
                    my_vector.clear();
                
                if(getNext()) {
                    continue;
                } else {
                    cout << "До скорой встречи." << endl;
                    break;
                }
            } else if (from_file && !to_file) // из файла в консоль
            { 
                if (file_init(file_in))
                    cout << my_function() << endl;
                    my_vector.clear();
                break;
            } else if (from_file && to_file) // из файла в файл
            { 
                if (file_init(file_in))
                    file_out << my_function() << endl;
                    my_vector.clear();
                break;
            }
        } else {
            cout << "Не удалось открыть файл(ы)!" << endl;
            break;
        }
    }
    file_in.close();
    file_out.close();
    return 0;
}