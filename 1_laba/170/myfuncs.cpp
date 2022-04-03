#include <iostream>

#include <string>
#include<vector>
#include <map>


#include "functions.h"

using namespace std;

extern vector<int> my_vector;
extern map<int, int> my_dict;

string my_func() {
    
    string answer;
    QuickSort(my_vector);

    //Осторожно говонокод
    int a_i, a_j, a_k, a_l, i, j, k, l;
    a_i = my_vector[1];
    a_j = my_vector[2];
    a_k = my_vector[3];
    a_l = my_vector[4];

    i = my_dict[a_i];
    j = my_dict[a_j];
    k = my_dict[a_k];
    l = my_dict[a_l];
    
    answer = "Ответ: ";
    answer += to_string(i) + ", " + to_string(j) + ", " + to_string(k) + ", " + to_string(l) + ".";
    
    return answer;
}


// Прочитать про сортировки
// https://academy.yandex.ru/posts/osnovnye-vidy-sortirovok-i-primery-ikh-realizatsii
// Буду использовать быструю сортировку


int Partition(vector<int>& values, int l, int r)
{
    int x = values[r];
    int less = l;

    for (int i = l; i < r; ++i)
    {
        if (values[i] <= x) 
        {
            swap(values[i], values[less]);
            ++less;
        }
    }

    swap(values[less], values[r]);
    return less;
}


void QuickSortImpl(vector<int>& values, int l, int r)
{
    if (l < r) 
    {
        int q = Partition(values, l, r);
        QuickSortImpl(values, l, q - 1);
        QuickSortImpl(values, q + 1, r);
    }
}


void QuickSort(vector<int>&values)
{
    if (!values.empty())
    {
        QuickSortImpl(values, 0, values.size() - 1);
    }
}