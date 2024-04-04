#include "SimonSays.h"

Interface Red(Button_RED, Light_RED, Freq_RED);
Interface Yellow(Button_YELLOW, Light_YELLOW, Freq_YELLOW);
Interface Green(Button_GREEN, Light_GREEN, Freq_GREEN);
Interface Blue(Button_BLUE, Light_BLUE, Freq_BLUE);

void setup() 
{
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(Light_RED, OUTPUT);
    pinMode(Light_YELLOW, OUTPUT);
    pinMode(Light_GREEN, OUTPUT);
    pinMode(Light_BLUE, OUTPUT);
    pinMode(Button_RED, INPUT_PULLUP);
    pinMode(Button_YELLOW, INPUT_PULLUP);
    pinMode(Button_GREEN, INPUT_PULLUP);
    pinMode(Button_BLUE, INPUT_PULLUP);
}

void loop() 
{
    currenttime = millis();
    Red.PushButton();
    Red.ToggleLight();
    Yellow.PushButton();
    Yellow.ToggleLight();
    Green.PushButton();
    Green.ToggleLight();
    Blue.PushButton();
    Blue.ToggleLight();
}

