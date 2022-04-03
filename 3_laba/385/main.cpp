#include <iostream>
#include <fstream>

#include "functions.h"

int main() 
{
    using namespace std;
    ifstream file_in("in.txt");
    ofstream file_out("out.txt");
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
                init();
                cout << my_function() << endl;
                if(getNext()) {
                    continue;
                } else {
                    cout << "До скорой встречи." << endl;
                    break;
                }
            } else if (!from_file && to_file) // из консоли в файл
            { 
                init();
                file_out << my_function() << endl;
                if(getNext()) {
                    continue;
                } else {
                    cout << "До скорой встречи." << endl;
                    break;
                }
            } else if (from_file && !to_file) // из файла в консоль
            { 
                file_init(file_in);
                cout << my_function() << endl;
                break;
            } else if (from_file && to_file) // из файла в файл
            { 
                file_init(file_in);
                file_out << my_function() << endl;
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