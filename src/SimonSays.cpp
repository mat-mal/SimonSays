#include "SimonSays.h"

// Interface Red(Button_RED, Light_RED, Freq_RED);
// Interface Yellow(Button_YELLOW, Light_YELLOW, Freq_YELLOW);
// Interface Green(Button_GREEN, Light_GREEN, Freq_GREEN);
// Interface Blue(Button_BLUE, Light_BLUE, Freq_BLUE);

void setup() 
{
    Serial.begin(9600);
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(Light_RED, OUTPUT);
    pinMode(Light_YELLOW, OUTPUT);
    pinMode(Light_GREEN, OUTPUT);
    pinMode(Light_BLUE, OUTPUT);
    pinMode(Button_RED, INPUT_PULLUP);
    pinMode(Button_YELLOW, INPUT_PULLUP);
    pinMode(Button_GREEN, INPUT_PULLUP);
    pinMode(Button_BLUE, INPUT_PULLUP);
    int seed = (analogRead(A0) + analogRead(A1) + analogRead(A2) - analogRead(A3) + analogRead(A4)) * analogRead(A5);       //for better seed distribution
    randomSeed(seed);
}

void loop() 
{
    currenttime = millis();
    Red.ToggleLight(Red.PushButton());
    Yellow.ToggleLight(Yellow.PushButton());
    Green.ToggleLight(Green.PushButton());
    Blue.ToggleLight(Blue.PushButton());
    simon.SimonLights();
    
}

