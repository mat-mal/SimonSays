#include "Player.h"

Player player;

Player::Player()
{
    playerCounter = 0;
    player_timer = 0;
    isPlayerTurn = false;
}

void Player::PlayerTurn()
{
    if(isPlayerTurn)
    {
        for(int i = 0; i < numberOfColors; i++)
        {
            playerInput[i] = Colors[i].PushButton();
            if(playerInput[i] && playerCounter <= simon.countRounds)
            {
                LightsOrder[playerCounter] = playerInput[i];
                Colors[i].isLightON = true;
                playerCounter++;
            }
        }
    }
}

void Player::ResetPlayer()
{
    player = Player();
    memset(LightsOrder, 0, sizeof(LightsOrder));
}