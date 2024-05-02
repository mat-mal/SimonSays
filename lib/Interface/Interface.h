#ifndef _INTERFACE_H_
#define _INTERFACE_H_
#include <Arduino.h>
#include "Timer.h"

const int BUZZER_PIN = 3;
const int numberOfColors = 4;

enum ColorNumber
{
    RED = 0,
    YELLOW,
    GREEN,
    BLUE
};

enum ButtonsPIN
{
    RED_BUTTON_PIN = 4,
    YELLOW_BUTTON_PIN,
    GREEN_BUTTON_PIN,
    BLUE_BUTTON_PIN
};

enum LEDPIN
{
    RED_LED_PIN = 9,
    YELLOW_LED_PIN,
    GREEN_LED_PIN,
    BLUE_LED_PIN
};

enum BuzzerFreq
{
    RED_FREQ = 350,
    YELLOW_FREQ = 500,
    GREEN_FREQ = 700,
    BLUE_FREQ = 1450
};

class Interface
{
private:
    unsigned long button_timer;
    int lastState;
    int button_PIN;
    int led_PIN;
    int buzzerFreq;
    int selectedLight;
public:
    bool isPush;
    bool isMuted;
    bool isLightON;
    const int lightTime = 500;
    unsigned long light_timer;

    Interface(ButtonsPIN button, LEDPIN lights, BuzzerFreq buzFreq);
    int PushButton();
    void ToggleLight();
};

extern Interface *Red;
extern Interface *Yellow;
extern Interface *Green;
extern Interface *Blue;
extern Interface Colors[numberOfColors];

#endif