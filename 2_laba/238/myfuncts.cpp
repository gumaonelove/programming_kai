#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include "myfuncts.h"
#include "vars.h"


using namespace std;
//проверка выбора ввода и вывода
bool insert(){
    string a;
    string zero = "0";
    string one = "1";
    while(true){
        cin >> a;
        if (a == one or a == zero){
            if( a == zero){
                return false;
            }else{
                return true;
            }
        }else{
            cout << "Incorrect answer. Please try again.";
        };
    };
};

//ввод N с консоли
int insN(){
    cout << "Please insert N." << endl;
    while(true){
        cin >> N;
        if(isNum(N)){
            int n = stoi(N);
            return n;
        }else{
            cout << "Input wasnt a number. Please try again" << endl;
        }
    }
}

//проверка ввода числа N
bool isNum(char K[256]) {
    for (int i = 0; i < strlen(K); i++) {
        if (K[i] < 48 or K[i] > 57) {
            return false;
        }
    }
    return true;
}

//заполнения массива
vector<double> multisMas(int n){
    vector<double>multipliers;
    float k = 1;
    for(int i = 0; i<n; i++){
        if(i%2==0){
            multipliers.push_back(double((k+1)/k));
        }else{
            multipliers.push_back(double(k/(k+1)));
        }
        k+=1;
    }
    return multipliers;
}

//вычисление ответа
double makeAns(vector<double>multipliers, int n){
    double ans = 1;
    for(int i = 0;i<n;i++){
        ans*=multipliers[i];
    }
    return ans;
}

//ввод N из файла
int insFile(ifstream & file){
    string line;
    getline(file , line);
    int n = stoi(line);
    return n;
}