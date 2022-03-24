#include <string>
#include <cmath>

#include "variables.h"
#include "functions.h"

#define PI 3.14159265 

using namespace std;


string my_function() 
{  
    string answer;
    int ans;
    

    
    answer = "Положительных элементов содержит матрица: ";
    answer += to_string(ans);
    return answer;
}


vector<vector<double>> get_vector() 
{
    double param;

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            param = i + j / 2;
            my_vector[i][j] = sin(param * PI / 180);
        }
    }
}

int get_count (vector<vector<double>> my_vector) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            
        }
    }
}

