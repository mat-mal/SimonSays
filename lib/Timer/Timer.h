#ifndef _TIMER_H_
#define _TIMER_H_
#include<Arduino.h>

extern unsigned long currenttime;

int Timer(unsigned int tocountdown, unsigned long *timer);

#endif