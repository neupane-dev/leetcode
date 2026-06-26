#include <stdint.h>
#include "lc_9.h"

bool isPalindrome(int x)
{
    if(x < 0)
    {
        return false;
    }

    long divider = 1;

    while(x >= 10 * divider)
    {
        divider *= 10;
    }

    while(x)
    {
        int right = x % 10;
        int left = x / divider;

        if(left != right)
        {
            return false;
        }

        x = (x%divider)/10;
        divider = divider / 100;
    }
    return true;
}
