#include <iostream>
#include <fstream>
#include "myfuncts.h"


using namespace std;

int main() {
    ifstream file_in("in.txt");
    ofstream file_out("out.txt");
    vector<double>multipliers;
    while(true){
        cout << "Insert from console[0] or from file[1]." << endl;
        if(insert()){
            cout << "Output from console[0] or from file[1]." << endl;
            int n = insFile(file_in);
            if(insert()){
                file_out << makeAns(multisMas(n),n) << endl;
            }else{
                cout << makeAns(multisMas(n),n) << endl;
            }
            return 0;
        }else{
            int n = insN();
            cout << "Output from console[0] or from file[1]." << endl;
            if(insert()){
                file_out << makeAns(multisMas(n),n) <<endl;
            }else{
                cout << "The answer is:" <<makeAns(multisMas(n),n) << endl;
            }
        }
        cout << "Do you want to continue? No[0] Yes[1]" << endl;
        if(insert()){
            continue;
        }else{
            cout << "See you next time." << endl;
            file_in.close();
            file_out.close();
            return 0;
        }
    }
}
