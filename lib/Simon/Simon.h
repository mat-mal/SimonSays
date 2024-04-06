#ifndef _SIMON_H_
#define _SIMON_H_
#include <Arduino.h>
#include "Interface.h"

const int difficultyLevel = 10;                     //how many light will be on last stage
const int maxSteps = 10;                            //step - playing one note/push button once

class Simon
{
private:
    int lights_PIN;
    int series[difficultyLevel];                    //full series of lights
    int stages[difficultyLevel][maxSteps] = {0};
    int countSteps;
    int countStages;
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