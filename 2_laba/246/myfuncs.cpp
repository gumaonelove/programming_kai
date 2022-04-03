#include <iostream>

#include <string>
#include<vector>
#include <map>


#include "functions.h"

using namespace std;

extern int n;
extern vector<int> my_vector;


string my_func() {
    if (isAscendingSequence(my_vector)){
        return "Образуют 'возрастающую' последовательность ";
    } else {
       return "Не образуют 'возрастающую' последовательность"; 
    }
}


bool isAscendingSequence(vector<int> now_vector)
{
    bool ans = true;

    for (int i = 1; i < n; i++)
    {
        ans *= (now_vector[i] < now_vector[i+1]);
    }

    ans *= (now_vector[n] < 2 * now_vector[1]);

    for (int i = 1; i < n; i++)
    {
        ans *= ((i + 1) * now_vector[i] < (i + 1) * now_vector[i+1]);
    }

    return ans;
}