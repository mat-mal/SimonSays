#ifndef _GAME_H_
#define _GAME_H_
#include <Arduino.h>
#include "Interface.h"
#include <math.h>

class Player;
class Simon;

class Game
{
private:
    
    bool isWinning;
    unsigned long lose_timer;
    unsigned long begin_timer;
    int colorCounter;
    const int interval = 600;
public:
    bool isCorrect;
    
    Game();
    void IsPlayerCorrect(int countTurns);
    void WinLoseCheck();
    void PlayWinSound();
    void PlayLoseSound();
    void StartGame();
};

extern Game game;

#endif
