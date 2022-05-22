#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "functs.h"

using namespace std;

int main()
{
    ifstream file_in("in.txt");
    ofstream file_out("out.txt");
    while(true)
    {
        vector<vector<double> >working_field;
        double ans = 0;
        cout << "Insert from console[0] or from file[1]." << endl;

        if(insert())
        {
            string str;
            getline(file_in, str);
            int n = stoi(str);
            int k = 0;

            while( getline(file_in, str) )
            {
                if(k<3){
                    working_field.push_back(from_string_to_vector(str));
                    if(k==2){
                        ans+= mainfunct(working_field, n);
                    }
                }else{
                    auto iter = working_field.cbegin();
                    working_field.erase(iter);
                    working_field.push_back(from_string_to_vector(str));
                    ans+= mainfunct(working_field, n);
                }
                k+=1;
            }
            cout << "Output from console[0] or from file[1]." << endl;
            if (insert())
            {
                file_out << ans << endl;
            } else
            {
                cout << ans << endl;
            }
            return 0;
        } else
        {
            cout << "Vvedite poryadok matrici:" << endl;
            bool A = false;
            int n;
            while(!A) {
                try {
                    string lin;
                    getline(cin,lin);
                    n = stoi(lin);
                    A = true;
                } catch (...) {
                    cout << "exception caught" << endl;
                }
            }
            cout << "Vvedite stroki matrici:" << endl;
            for(int i = 0;i<n;i++)
            {   vector<double>temp;
                string line = checkline(n);
                temp = from_string_to_vector(line);
                if(i<3) {
                    working_field.push_back(temp);
                    if (i == 2) {
                        ans += mainfunct(working_field, n);
                    }
                }
                else{
                    auto iter = working_field.cbegin();
                    working_field.erase(iter);
                    working_field.push_back(temp);
                    ans+= mainfunct(working_field, n);
                    }
            }
            cout << "Output from console[0] or from file[1]." << endl;
            if(insert())
            {
                file_out << ans <<endl;
            } else
            {
                cout << "The answer is:" << ans << endl;
            }
        }
        cout << "Do you want to continue? No[0] Yes[1]" << endl;
        if (insert())
        {
            continue;
        } else
        {
            cout << "See you next time." << endl;
            file_in.close();
            file_out.close();
            return 0;
        }
    }
}