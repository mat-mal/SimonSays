#include "Game.h"
#include "Simon.h"
#include "Player.h"

Game game;

Game::Game()
{
    isWinning = true;
    begin_timer = 0;
    lose_timer = 0;
    colorCounter = 0;
    isCorrect = true;
}
void Game::IsPlayerCorrect(int Round)
{
    for(int i = 0; i <= Round; i++)
    {
        if(player.LightsOrder[i] != 0)
        {
            Serial.print(player.LightsOrder[i]);
            Serial.println(simon.LightsOrder[i]);
            if(player.LightsOrder[i] == simon.LightsOrder[i])
            {
                isCorrect = true;
                isWinning = true;
            }
            else
            {
                isCorrect = false;
                isWinning = false;
                break;
            }
        }
    }
}

void Game::StartGame()
{
    if(!simon.isSimonTurn && !player.isPlayerTurn)
    {
        if(Timer(interval, &begin_timer))
        {
            Colors[colorCounter].isLightON = true;
            Colors[colorCounter].isMuted = true;

            colorCounter = (++colorCounter)%numberOfColors;
        }

        if(Red->PushButton() || Yellow->PushButton() || Green->PushButton() || Blue->PushButton())
        {
            simon.isSimonTurn = true;
        }
    }
}

void Game::WinLoseCheck()
{
    if(isWinning && simon.countRounds == simonDifficulty)
    {
        PlayWinSound();
        player.ResetPlayer();
        simon.ResetSimon(); 
    }
    else if(!isWinning && Timer(interval, &lose_timer))
    {
        PlayLoseSound();
        isWinning = true;
        player.ResetPlayer();
        simon.ResetSimon();        
    }
}

void Game::PlayLoseSound()
{
    delay(600);
    tone(BUZZER_PIN, 550, 600);
    delay(600);
    tone(BUZZER_PIN, 440, 600);
    delay(600);
    tone(BUZZER_PIN, 330, 600);
    delay(600);
    tone(BUZZER_PIN, 220, 600);
    delay(600);
    tone(BUZZER_PIN, 110, 700);
    delay(700);
    noTone(BUZZER_PIN);
}

void Game::PlayWinSound()
{
    tone(BUZZER_PIN, 660, 300);
    delay(300);
    tone(BUZZER_PIN, 880, 300);
    delay(300);
    tone(BUZZER_PIN, 1100, 700);
    delay(800);
    noTone(BUZZER_PIN);
}