#include "Simon.h"

Simon simon;

Simon::Simon()
{
    counter = 0;
    simonLights_timer = 0;
    redOn = false;
    yellowOn = false;
    greenOn = false;
    blueOn = false;
}

void Simon::SimonLights()
{
    if(counter < simonLimit && Timer(interval, &simonLights_timer))
    {
        lightsOrder[counter] = random(Light_RED, Light_BLUE + 1);
        if(lightsOrder[counter] == Light_RED) redOn = true;
        if(lightsOrder[counter] == Light_YELLOW) yellowOn = true;
        if(lightsOrder[counter] == Light_GREEN) greenOn = true;
        if(lightsOrder[counter] == Light_BLUE) blueOn = true;    
        counter++;
    }
    Red.ToggleLight(&redOn);
    Yellow.ToggleLight(&yellowOn);
    Green.ToggleLight(&greenOn);
    Blue.ToggleLight(&blueOn);  
}
