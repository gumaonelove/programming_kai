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

            while( getline(file_in, str) )
            {
                working_field.push_back(from_string_to_vector(str));
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
            string N;
            cin >> N;
            int n = stoi(N);
            cout << "Vvedite stroki matrici:" << endl;

            for(int i = 0;i<n;i++)
            {
                string ins = getlin();
                cout << "ins = " << ins << endl;
                vector<double>temp = from_string_to_vector(ins);
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