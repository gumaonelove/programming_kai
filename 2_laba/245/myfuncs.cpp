#include <iostream>
#include <limits>
#include <string>
#include <fstream>
#include <vector>

#include "functions.h"

using namespace std;

extern int n;
extern int g_A_array[30];
extern int g_B_array[40];
extern std::vector<int> g_C_array;


string my_function() {
    string answer = "Неверно";
    int a_ind_neg_oc = get_index_negative_occurrence_from_array(g_A_array, 30);
    int b_ind_neg_oc = get_index_negative_occurrence_from_array(g_B_array, 40);
    int c_ind_neg_oc = get_index_negative_occurrence_from_vector(g_C_array);
    
    if ((c_ind_neg_oc < a_ind_neg_oc) && (c_ind_neg_oc < b_ind_neg_oc))
        answer = "Верно";
    
    return answer;
}

int get_index_negative_occurrence_from_array(int now_array[], int lenght)
{
    for (int i = 0; i < lenght; i++)
    {
        if (now_array[i] < 0)
            return i;
        
    }
    return -1;
}

int get_index_negative_occurrence_from_vector(std::vector<int> now_vector)
{
    for (int i = 0; i < now_vector.size(); i++)
    {
        if (now_vector[i] < 0)
            return i;
        
    }
    return -1;
}