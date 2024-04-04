#include "Interface.h"

Interface Red(Button_RED, Light_RED, Freq_RED);
Interface Yellow(Button_YELLOW, Light_YELLOW, Freq_YELLOW);
Interface Green(Button_GREEN, Light_GREEN, Freq_GREEN);
Interface Blue(Button_BLUE, Light_BLUE, Freq_BLUE);

Interface::Interface(ButtonsPIN button, LightsPIN lights, BuzzerFreq buzFreq)
{
    button_PIN = button;
    lights_PIN = lights;
    buzzerFreq = buzFreq;
    button_timer = 0;
    light_timer = 0;    
    lastState = HIGH;
    isPush = false;
}

bool* Interface::PushButton()
{
    int currentState = digitalRead(button_PIN);

    if(currentState == LOW && lastState == HIGH && (millis() - button_timer) > 20)
    {
        isPush = true;
    }
    lastState = currentState;

    return &isPush;
}

void Interface::ToggleLight(bool* isOn)           //Spróbować, żeby buzzer nie jęczał po wciśnięciu wielu przycisków
{
    if(*isOn)
    {
        digitalWrite(lights_PIN, HIGH);
        tone(BUZZER_PIN, buzzerFreq);
            
        if(Timer(lightTime, &light_timer))
        {
            digitalWrite(lights_PIN, LOW);
            noTone(BUZZER_PIN);
            *isOn = false;
        }
    }
}