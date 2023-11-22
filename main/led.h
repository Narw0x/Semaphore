#pragma once

#include "driver/gpio.h"

class Led
{
  private:
    gpio_num_t m_pin = GPIO_NUM_0;
  public:
    Led(gpio_num_t pin);
    Led();
    void on();
    void off();
    void toggle();
};