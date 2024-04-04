#include "Timer.h"

int Timer(unsigned int tocountdown, unsigned long *temp)
{
    if(*temp == 0)
    {
        *temp = currenttime;
    }
    else if(currenttime - *temp >= tocountdown)
    {
        *temp = 0;
        return 1;
    }

    return 0;
}