#include "button.h"
#include "esp_log.h"

static const char *TAG = "BUTTON";

Button::Button(gpio_num_t pin)
{
    m_pin = pin;
    gpio_reset_pin(m_pin);
    gpio_set_direction(m_pin, GPIO_MODE_INPUT);
}

Button::Button()
{
    m_pin = GPIO_NUM_0;
}

bool Button::isPressed()
{
    return (!gpio_get_level(m_pin));
}