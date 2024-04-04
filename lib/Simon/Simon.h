#ifndef _SIMON_H_
#define _SIMON_H_
#include <Arduino.h>
#include "Interface.h"

const int simonLimit = 10;

class Simon
{
private:
    int lights_PIN;
    int lightsOrder[simonLimit];
    int counter;
    int interval = 600;
    unsigned long simonLights_timer;
    bool redOn;
    bool yellowOn;
    bool greenOn;
    bool blueOn;
public:
    Simon();
    void SimonLights();

};

extern Simon simon;

#endif