#include <iostream>
#include <fstream>

#include "functions.h"

int main() {
    using namespace std;
    ifstream file_in("in.txt");
    ofstream file_out("out.txt");
    unsigned char in_lab;
    unsigned char out_lab;
    while (true) {
        if (file_in.is_open() && file_out.is_open()) {
            cout << "Ввод с консоли (0) или из файла (1): ";
            in_lab = get_0_1();
            cout << "Вывод на консоль (0) или в файл (1): ";
            out_lab = get_0_1();
            if (in_lab == '0' && out_lab == '0') {
                if(init()) {
                    cout << average() << endl;
                }
                if(getNext()) {
                    continue;
                } else {
                    cout << "До скорой встречи." << endl;
                    break;
                }
            } else if (in_lab == '0' && out_lab == '1') {
                if(init()) {
                    file_out << average() << endl;
                }
                if(getNext()) {
                    continue;
                } else {
                    cout << "До скорой встречи." << endl;
                    break;
                }
            } else if (in_lab == '1' && out_lab == '0') {
                if (file_init(file_in)) {
                    cout << average() << endl;
                }
                break;
            } else if (in_lab == '1' && out_lab == '1') {
                if (file_init(file_in)) {
                    file_out << average() << endl;
                }
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
