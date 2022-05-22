//
// Created by Булат Гумеров on 16.05.2022.
//

#include <iostream>
#include "myfuncs.h"

unsigned long long shiftr(unsigned char nbyte, unsigned long long nnum)
{
    using namespace std;

    unsigned long long mask;

    switch (nbyte)
    {
        case 1: mask = 0xFF; break;
        case 2: mask = 0xFFFF; break;
        case 3: mask = 0xFFFFFF; break;
        case 4: mask = 0xFFFFFFFF; break;
        case 5: mask = 0xFFFFFFFFFF; break;
        case 6: mask = 0xFFFFFFFFFFFF; break;
        case 7: mask = 0xFFFFFFFFFFFFFF; break;
        case 8: mask = 0xFFFFFFFFFFFFFFFF; break;
        default:;
    }
    
    return mask & ( ((nnum & 0x1) << (nbyte * 8 - 1)) | (nnum >> 1));
};