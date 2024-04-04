#ifndef _INTERFACE_H_
#define _INTERFACE_H_
#include <Arduino.h>
#include "Timer.h"

const int BUZZER_PIN = 3;

enum ButtonsPIN
{
    Button_RED = 4,
    Button_YELLOW = 5,
    Button_GREEN = 6,
    Button_BLUE = 7
};

enum LightsPIN
{
    Light_RED = 9,
    Light_YELLOW = 10,
    Light_GREEN = 11,
    Light_BLUE = 12
};

enum BuzzerFreq
{
    Freq_RED = 350,
    Freq_YELLOW = 500,
    Freq_GREEN = 700,
    Freq_BLUE = 1450
};

class Interface
{
private:
    unsigned long button_timer;
    int lastState;
    int button_PIN;
    int lights_PIN;
    int buzzerFreq;
public:
    bool isPush;
    const int lightTime = 500;
    unsigned long light_timer;

    Interface(ButtonsPIN button, LightsPIN lights, BuzzerFreq buzFreq);
    bool* PushButton();
    void ToggleLight(bool* isOn);
};

extern Interface Red;
extern Interface Yellow;
extern Interface Green;
extern Interface Blue;

#endif