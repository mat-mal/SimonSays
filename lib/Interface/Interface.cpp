#include "Interface.h"

Interface Colors[numberOfColors] = {Interface(RED_BUTTON_PIN, RED_LED_PIN, RED_FREQ), Interface(YELLOW_BUTTON_PIN, YELLOW_LED_PIN, YELLOW_FREQ), Interface(GREEN_BUTTON_PIN, GREEN_LED_PIN, GREEN_FREQ), Interface(BLUE_BUTTON_PIN, BLUE_LED_PIN, BLUE_FREQ)};
Interface* Red = &Colors[RED];
Interface* Yellow = &Colors[YELLOW];
Interface* Green = &Colors[GREEN];
Interface* Blue = &Colors[BLUE];

Interface::Interface(ButtonsPIN button, LEDPIN lights, BuzzerFreq buzFreq)
{
    button_PIN = button;
    led_PIN = lights;
    buzzerFreq = buzFreq;
    button_timer = 0;
    light_timer = 0;    
    lastState = HIGH;
    isPush = false;
    isLightON = false;
    isMuted = false;
    selectedLight = 0;
}

int Interface::PushButton()
{
    int currentState = digitalRead(button_PIN);

    if(currentState == LOW && lastState == HIGH && (millis() - button_timer) > 50)
    {
        selectedLight = led_PIN;
    }
    else
    {
        selectedLight = 0;
    }
    lastState = currentState;

    return selectedLight;
}

void Interface::ToggleLight()           //Try to make that buzzer don't squeak when two or more buttons are pushed
{
    if(isLightON)
    {
        digitalWrite(led_PIN, HIGH);

        if(!isMuted)
        {
            tone(BUZZER_PIN, buzzerFreq);   
        }

        if(Timer(lightTime, &light_timer))
        {
            digitalWrite(led_PIN, LOW);
            noTone(BUZZER_PIN);
            isLightON = false;
            isMuted = false;
        }
    }
}