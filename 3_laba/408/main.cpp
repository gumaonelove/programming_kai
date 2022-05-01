#include <iostream>
#include <fstream>
#include <vector>

#include "functs.h"

using namespace std;

int main() {
    ifstream file_in("in.txt");
    ofstream file_out("out.txt");
    while(true){
        vector<vector<double>>working_field(3);
        vector<double>first;
        vector<double>second;
        vector<double>third;
        double ans = 0;
        cout << "Insert from console[0] or from file[1]." << endl;
        if(insert()){
            string str;
            int I = 0;
            int n;
            while(getline(file_in, str)){
                if(I==0){
                    n = stoi(str);
                }else if(I==1){
                    vector<double>temp = push_str(str);
                    for(int k=0; k<n; k++){
                        first.push_back(temp[k]);
                    }
                }else if(I==2){
                    vector<double>temp = push_str(str);
                    for(int k=0; k<n; k++){
                        second.push_back(temp[k]);
                    }
                }else if(I==3){
                    vector<double>temp = push_str(str);
                    for(int k=0; k<n; k++){
                        third.push_back(temp[k]);
                    }
                }else{
                    vector<double>temp = push_str(str);
                    mainfunct(first, second, third, ans);
                    rescript(temp,first,second,third, n);
                }
                I+=1;
            }
            cout << "Output from console[0] or from file[1]." << endl;
            if(insert()){
                file_out << ans << endl;
            }else{
                cout << ans << endl;
            }
            return 0;
        }else{
            cout << "Vvedite poryadok matrici:" << endl;
            string N;
            cin >>N;
            int n = stoi(N);
            cout << "Vvedite stroki matrici:" << endl;
            for(int i = 0;i<n;i++){
                string ins = getlin();
                vector<double>temp = push_str(ins);
                if(i==0){
                    for(int k = 0; k<n; k++){
                        first.push_back(temp[k]);
                    }
                }else if(i==1){
                    for(int k = 0; k<n; k++){
                        second.push_back(temp[k]);
                    }
                }else if(i==2){
                    for(int k = 0; k<n; k++){
                        third.push_back(temp[k]);
                    }
                }else{
                    mainfunct(first, second, third, ans);
                    rescript(temp , first , second , third, n);
                }
            }
            cout << "Output from console[0] or from file[1]." << endl;
            if(insert()){
                file_out << ans <<endl;
            }else{
                cout << "The answer is:" << ans << endl;
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