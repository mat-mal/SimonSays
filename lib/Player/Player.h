#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <Arduino.h>
#include "Interface.h"
#include "Simon.h"

class Simon;

class Player
{
private:
    int playerInput[numberOfColors] = {0};
    unsigned long player_timer;
public:
    int LightsOrder[simonDifficulty] = {0};
    int playerCounter;
    bool isPlayerTurn;
    
    Player();
    void PlayerTurn();
    void ResetPlayer();
};

extern Player player;

#endif