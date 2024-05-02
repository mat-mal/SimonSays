#include "Simon.h"
#include "Player.h"
#include "Game.h"

Simon simon;

Simon::Simon()
{
    countRounds = 0;
    countSteps = 0;
    simonLights_timer = 0;
    isSimonTurn = false;
}

void Simon::SimonTurn()
{
    if(countRounds < simonDifficulty && isSimonTurn && Timer(interval, &simonLights_timer))
    {
        if(countSteps < (countRounds + 1))
        {
            LightsOrder[countRounds] = random(RED_LED_PIN, BLUE_LED_PIN + 1);
            rounds[countRounds][countSteps] = LightsOrder[countSteps];
            if(rounds[countRounds][countSteps] == RED_LED_PIN) Red->isLightON = true;
            if(rounds[countRounds][countSteps] == YELLOW_LED_PIN) Yellow->isLightON = true;
            if(rounds[countRounds][countSteps] == GREEN_LED_PIN) Green->isLightON = true;
            if(rounds[countRounds][countSteps] == BLUE_LED_PIN) Blue->isLightON = true;   
            countSteps++;
        }
        else
        {
            isSimonTurn = false;
            player.isPlayerTurn = true;
        }
    }

    game.IsPlayerCorrect(countRounds);
    if((countRounds + 1) == countSteps && player.playerCounter > countRounds && !isSimonTurn && game.isCorrect && Timer(interval, &simonLights_timer))
    {
        countRounds++;
        countSteps = 0;
        player.playerCounter = 0;
        isSimonTurn = true;
        player.isPlayerTurn = false;
        memset(player.LightsOrder, 0, sizeof(player.LightsOrder));
    }
}

void Simon::ResetSimon()
{
    simon = Simon();
}