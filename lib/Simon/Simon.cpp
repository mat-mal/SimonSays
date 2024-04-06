#include "Simon.h"

Simon simon;

Simon::Simon()
{
    countStages = 0;
    countSteps = 0;
    simonLights_timer = 0;
    redOn = false;
    yellowOn = false;
    greenOn = false;
    blueOn = false;
}

void Simon::SimonLights()
{
    if(countStages < difficultyLevel && Timer(interval, &simonLights_timer))
    {
        Serial.print(countStages);
        if(countSteps < (countStages + 1))
        {
            Serial.print(countSteps);
            series[countStages] = random(Light_RED, Light_BLUE + 1);
            stages[countStages][countSteps] = series[countSteps];
            Serial.print(" ");
            Serial.println(stages[countStages][countSteps]);
            if(stages[countStages][countSteps] == Light_RED) redOn = true;
            if(stages[countStages][countSteps] == Light_YELLOW) yellowOn = true;
            if(stages[countStages][countSteps] == Light_GREEN) greenOn = true;
            if(stages[countStages][countSteps] == Light_BLUE) blueOn = true;   
            countSteps++;

        }
        if((countStages + 1) == countSteps)
        {
            countStages++;
            countSteps = 0;
        }
        
    }
    // Serial.println(stages[countStages][countSteps]);
    Red.ToggleLight(&redOn);
    Yellow.ToggleLight(&yellowOn);
    Green.ToggleLight(&greenOn);
    Blue.ToggleLight(&blueOn);  
}
