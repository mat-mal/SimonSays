#include "SimonSays.h"

void setup() 
{
    Serial.begin(9600);
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(YELLOW_LED_PIN, OUTPUT);
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(BLUE_LED_PIN, OUTPUT);
    pinMode(RED_BUTTON_PIN, INPUT_PULLUP);
    pinMode(YELLOW_BUTTON_PIN, INPUT_PULLUP);
    pinMode(GREEN_BUTTON_PIN, INPUT_PULLUP);
    pinMode(BLUE_BUTTON_PIN, INPUT_PULLUP);
    int seed = (analogRead(A0) + analogRead(A1) + analogRead(A2) - analogRead(A3) + analogRead(A4)) * analogRead(A5);       //for better seed distribution
    randomSeed(seed);
    currenttime = 0;
}

void loop() 
{
    currenttime = millis();
    game.StartGame();
    simon.SimonTurn();
    player.PlayerTurn();
    game.WinLoseCheck();

    Red->ToggleLight();
    Yellow->ToggleLight();
    Green->ToggleLight();
    Blue->ToggleLight();
}

