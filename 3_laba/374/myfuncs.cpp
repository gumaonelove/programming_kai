#include <string>
#include <cmath>

#include "functions.h"

#define PI 3.14159265

using namespace std;

extern int n;

string my_function() 
{  
    string answer;
    vector< vector<double> > _my_vector = get_vector();
    int ans = get_count(_my_vector);

    answer = "Положительных элементов содержит матрица: ";
    answer += to_string(ans);
    return answer;
}


vector< vector<double> > get_vector()
{
    double _param;
    double _sin;
    vector<double> _now_vector;
    vector< vector<double> > _vector_sinus;

    for (int i = 1; i <= n ; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            _param = i + j / 2;
            _sin = sin(_param * PI / 180);

            _now_vector.push_back(_sin);
        }
        _vector_sinus.push_back(_now_vector);
        _now_vector.clear();
    }

    return _vector_sinus;
}


int get_count (vector< vector<double> > _my_vector) 
{
    int _count = 0;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (_my_vector[i][j] > 0)
            {
                _count += 1;
            }
        }
    }

    return _count;
}