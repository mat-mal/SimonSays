#ifndef _SIMON_H_
#define _SIMON_H_
#include <Arduino.h>
#include "Interface.h"             

const int simonDifficulty = 5;                  //how many light will be on last round

class Player;
class Game;

class Simon
{
private:
    int rounds[simonDifficulty][simonDifficulty] = {0};
    int interval = 600;
    unsigned long simonLights_timer;
public:
    int countSteps;                                      //step - playing one note/push button once
    int LightsOrder[simonDifficulty];                    //full series of lights
    bool isSimonTurn;
    int countRounds;

    Simon();
    void SimonTurn();
    void ResetSimon();
};

extern Simon simon;

#endif