#include <iostream>
#include <fstream>

bool finit (std::ifstream & f);
char get_0_1();
bool init();
void main_func(std::ostream & f);
bool getNext();

int main() {
    using namespace std;
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    unsigned char in_lab;
    unsigned char out_lab;
    while (true) {
        if (fin.is_open() && fout.is_open()) {
            cout << "Ввод с консоли (0) или из файла (1):  ";
            in_lab = get_0_1();
            cout << "Вывод на консоль (0) или в файл (1): ";
            out_lab = get_0_1();
            if (in_lab == '0' && out_lab == '0') {
                if(init()) {
                    main_func(cout);
                }
                if(getNext()) {
                    continue;
                } else {
                    break;
                }
            } else if (in_lab == '0' && out_lab == '1') {
                if(init()) {
                    main_func(fout);
                }
                if(getNext()) {
                    continue;
                } else {
                    break;
                }
            } else if (in_lab == '1' && out_lab == '0') {
                if (finit(fin)) {
                    main_func(cout);
                }
                break;
            } else if (in_lab == '1' && out_lab == '1') {
                if (finit(fin)) {
                    main_func(fout);
                }
                break;
            }
        } else {
            cout << "Не удалось открыть файл(ы)!" << endl;
            break;
        }
    }
    fin.close();
    fout.close();
    delete [] my_array; // clean memory
    return 0;
}

