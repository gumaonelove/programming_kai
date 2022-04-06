#include <iostream>
#include <limits>
#include <string>
#include <fstream>
#include <vector>

#include "functions.h"

using namespace std;

extern int n;
extern bool answer;

string my_function() {
    string str = "Неверно";
    
    if (answer)
        str = "Верно";
    
    return str;
}

int get_index_negative_occurrence_from_array(int now_array[], int length)
{
    for (int i = 0; i < length; i++)
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

int *get_array_from_console (const int size_array)
{
    int array[size_array] = {};
    int now_value = 0;
    bool is_negative = false;

    for (int i = 0; i < size_array; i++)
    {
        cout << "a[" << i + 1 << "] = ";
        now_value = getIndex();
        array[i] = now_value;
        if (now_value < 0)
            is_negative = true;
    }

    if (!is_negative)
        array[0] = -1;
    
    return array;
}


vector<int> get_vector_from_console()
{
    int now_value = 0;
    vector<int> my_vector;
    bool is_negative = false;

    for (int i = 0; i < n; i++)
    {
        cout << "c[" << i + 1 << "] = ";
        now_value = getIndex();
        my_vector.push_back(now_value);
        if (now_value < 0)
            is_negative = true;
    }

    if (!is_negative)
        return {};
    
    return my_vector;
}


int *get_array_from_file (const int size_array, std::ifstream & file)
{
    int array[size_array] = {};
    int now_value = 0;
    bool is_negative = false;
    string line;

    for (int i = 0; i < size_array; i++)
    {
        getline(file, line);
        now_value = stoi(line);
        array[i] = now_value;
    
        if (now_value < 0)
            is_negative = true;
    }

    if (!is_negative)
        array[0] = -1;
    
    return array;
}



vector<int> get_vector_from_file(std::ifstream & file)
{
    int now_value = 0;
    vector<int> my_vector;
    bool is_negative = false;
    string line;

    for (int i = 0; i < n; i++)
    {
        getline(file, line);
        now_value = stoi(line);

        my_vector.push_back(now_value);
        if (now_value < 0)
            is_negative = true;
    }

    if (!is_negative)
        return {};
    
    return my_vector;
}