#include "semaphore.h"
#include "led.h"

Semaphore::Semaphore(Led redLED, Led greenLED, SemaphoreMode mode, Led orangeLED)
{
    m_redLED = redLED;
    m_greenLED = greenLED;
    m_s_mode = mode;
    m_orangeLED = orangeLED;
}

void Semaphore::redLight()
{
    turnOffAllLeds();
    m_redLED.on();    
}

void Semaphore::orangeLight()
{
    turnOffAllLeds();
    if(m_s_mode == FOR_CARS) m_orangeLED.on();
}

void Semaphore::greenLight()
{
    turnOffAllLeds();
    m_greenLED.on();
}

void Semaphore::turnOffAllLeds()
{
    m_redLED.off();
    if(m_s_mode == FOR_CARS) m_orangeLED.off();
    m_greenLED.off();
}