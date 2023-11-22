#include "led.h"

#include "esp_log.h"

Led::Led(gpio_num_t pin)
{
    m_pin = pin;
    gpio_reset_pin(m_pin);
    gpio_set_direction(m_pin, GPIO_MODE_INPUT_OUTPUT);
}


Led::Led()
{
    m_pin = GPIO_NUM_0;
}


void Led::on()
{
    gpio_set_level(m_pin, 1);
}

void Led::off()
{
    gpio_set_level(m_pin, 0);
}

void Led::toggle()
{
    int state = gpio_get_level(m_pin);
    gpio_set_level(m_pin, !state);
}