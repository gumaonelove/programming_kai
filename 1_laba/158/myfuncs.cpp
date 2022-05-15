#include <iostream>

#include "functions.h"


using namespace std;

extern int n;


string my_function() 
{
    get_answer(my_arr, 39);
    string answer;

    for (int i = 0; i < 39; i++) 
    {
        answer += to_string(true_arr[i]);
    }
    return answer;
}

void get_answer(int *now_arr, int len)
{
    for (int i = 0; i <= 39; i++)
    {
        true_arr[i] = (now_arr[i] * now_arr[i]) % 2;
    }
}