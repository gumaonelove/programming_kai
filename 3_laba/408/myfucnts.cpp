#include <iostream>
#include <vector>
#include <string>
#include "functs.h"

using namespace std;


vector<double> from_string_to_vector(const string& line) {
    vector<double> new_vect;
    string nstring;
    double elem;
    for (char i : line) {
        if (i != ' ') {
            nstring += i;
        } else {
            elem = stod(nstring);
            new_vect.push_back(elem);
            nstring = "";
        }
    }
    return new_vect;
}

double mainfunct(vector<vector<double> > working_field, int n) {
    double answer = 0;
    vector<double> senior = working_field[0];
    vector<double> middle = working_field[1];
    vector<double> junior = working_field[2];

    for (int i = 1; i < n - 1; i++) {
        double checksum = (senior[i] + junior[i] + middle[i - 1] + middle[i + 1]) / 4;
        if (middle[i] >= checksum)
            answer += (middle[i] * middle[i]);
    }
    return answer;
}

bool insert() {
    string a;
    string zero = "0";
    string one = "1";
    while (true) {
        getline(cin, a);
        if (a == one or a == zero) {
            if (a == zero) {
                return false;
            } else {
                return true;
            }
        } else {
            cout << "Incorrect answer. Please try again.";
        }
    }
}

string checkline(int n){
    string rstring;
    while(true){
        try{
            string nstring;
            getline(cin, nstring);
            vector<double>temp = from_string_to_vector(nstring);
            if(temp.size()!= n-1 ){
                throw ("Not enought arguments");
            }
            rstring = nstring;
            break;
        }catch(...){
            cout << "Try again" << endl;
        }
    }
    return rstring;
}