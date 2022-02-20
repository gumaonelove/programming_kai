#include <iostream>
#include <fstream>

const unsigned NM {3};
double mass[NM][NM];
unsigned i1{0};
unsigned i2{1};

bool init();
bool finit(std::ifstream & f);
void fsum(std::ostream & f);
unsigned char get_0_1();
bool getNext();

int main() {
    std::ifstream fin("in.txt");
    std::ofstream fout("out.txt");
    unsigned char in_lab;
    unsigned char out_lab;
    while (true) {
        if (fin.is_open() && fout.is_open()) {
            std::cout << "Ввод с консоли (0) или из файла (1):  ";
            in_lab = get_0_1();
            std::cout << "Вывод на консоль (0) или в файл (1): ";
            out_lab = get_0_1();
            if (in_lab == '0' && out_lab == '0') {
                if(init()) {
                    fsum(std::cout);
                }
                if(getNext()) {
                    continue;
                } else {
                    break;
                }
            } else if (in_lab == '0' && out_lab == '1') {
                if(init()) {
                    fsum(fout);
                }
                if(getNext()) {
                    continue;
                } else {
                    break;
                }
            } else if (in_lab == '1' && out_lab == '0') {
                if (finit(fin)) {
                    fsum(std::cout);
                }
                break;
            } else if (in_lab == '1' && out_lab == '1') {
                if (finit(fin)) {
                    fsum(fout);
                }
                break;
            }
        } else {
            std::cout << "Не удалось открыть файл(ы)!" << std::endl;
            break;
        }
    }
    fin.close();
    fout.close();
    return 0;

}