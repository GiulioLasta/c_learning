#include "grains.h"
#include <math.h>


uint64_t square(uint8_t index)
{
    if(index == 0) {
        return 0;
    } else if(index == 1) {
        return 1;
    } else if(index > 64) {
        return 0;
    }
    return (uint64_t)1 << (index - 1);

    // if(index == 1) {
    //     return 1;
    // }
    // return pow(2, index-1);
}



uint64_t total(void)
{
    uint64_t total = 0;

    for(int i = 0;i < 64; i++)
    {
        total = total  + square(i+1);
    }

    return total;
}
