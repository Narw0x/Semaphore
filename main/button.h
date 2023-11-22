#pragma once

#include "driver/gpio.h"


class Button
{
    private:
        gpio_num_t m_pin = GPIO_NUM_0;
    public:
        Button(gpio_num_t pin);
        Button();
        bool isPressed();
};