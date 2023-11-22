#pragma once

#include "led.h"
#include "driver/gpio.h"

class Semaphore 
{
    public:
        enum SemaphoreMode{
            FOR_CARS,
            FOR_PEDS
        };

    private:
        Led m_redLED;
        Led m_orangeLED;
        Led m_greenLED;
        SemaphoreMode m_s_mode;

    public:
        Semaphore(Led redLED, Led greenLED, SemaphoreMode mode, Led orangeLED = Led(GPIO_NUM_0));

    public:
        void redLight();
        void orangeLight();
        void greenLight();
        void turnOffAllLeds();
};