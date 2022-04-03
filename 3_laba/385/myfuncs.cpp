#include <string>
#include <vector>

#include <fstream>

#include "functions.h"

using namespace std;

extern int n;
extern vector< vector <double> > my_matrix;

double minumum = 1000000000;
int line_with_min_number = 0;

string my_function() 
{  
    string answer;
    answer = "Сумма элементов строки: ";
    answer +=  to_string(getSum());
    
    return answer;
}


vector <double> get_vector(string now_line, int string_number)
{
    vector  <double> _now_vector;
    string now_str = "";
    
    double tmp_number;

    for (int i = 0; i < now_line.size(); i++)
    {
        if (now_line[i] != ' ') 
        {
            now_str += now_line[i];
        } else 
        {   
            tmp_number = stod(now_str);
            _now_vector.push_back(tmp_number);
            now_str = "";

            if (tmp_number < minumum) 
            {
                minumum = tmp_number;
                line_with_min_number = string_number;
            }
        }
    }

    tmp_number = stod(now_str);
    _now_vector.push_back(tmp_number);
    if (tmp_number < minumum) 
    {
        minumum = tmp_number;
        line_with_min_number = string_number;
    }

    return _now_vector;
}

int getSum()
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += my_matrix[line_with_min_number][i];
    }

    return sum;
}