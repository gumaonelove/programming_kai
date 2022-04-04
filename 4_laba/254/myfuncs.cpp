#include <string>
#include <vector>

#include "functions.h"

using namespace std;

extern int n;
extern vector<char> my_vector;


string my_function() 
{  
    string  len = ", и - не содержатся в последовательности";
    bool answer = search(my_vector);

    if (answer)
    {
        len = ", и - содержатся в последовательности";
        return len;
    } else 
    {
        return len;
    }
        
}

bool search (vector<char> now_vector) 
{
    for (int i = 1; i < n; i++)
    {
        if (now_vector[i] == ',' && now_vector[i+1] == '-')
            return true;
    }
    return false;
}


