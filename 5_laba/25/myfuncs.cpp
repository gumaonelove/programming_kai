//
// Created by Булат Гумеров on 16.05.2022.
//

#include <iostream>
#include <string>
#include "myfuncs.h"

std::string my_function(unsigned long long nnum, std::string subsequence)
{
    using namespace std;

    unsigned long long bits;
    unsigned long long mask;
    for(int i = 0; i< subsequence.length(); i++){
        bits |= (subsequence[i] & 1) << i;
        mask |= 1 << i;
    }
 
    for(int i = 0; i < 64 - subsequence.length(); i++){
        if(!(nnum & (mask << i)) ^ (bits << i)){
            cout << "\nOn " << i + subsequence.length() << "th position\n";
            return 0;
        }
    }
 
    cout << "\nВхождений нет\n";
};