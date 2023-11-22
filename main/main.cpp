#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "led.h"
#include "button.h"
#include "semaphore.h"

enum class SemaphoreState
{
    OFF,
    GREEN_CARS,
    BTN_PUSHED_GREEN,
    ORANGE_AFTER_GREEN,
    RED_CARS,
    GREEN_PEDS,
    PEDS_TRANSIT,
    ORANGE_AFTER_RED
};

#define BUTTON_PIN GPIO_NUM_23
#define RED_LED_CARS_PIN GPIO_NUM_21
#define ORANGE_LED_CARS_PIN GPIO_NUM_19
#define GREEN_LED_CARS_PIN GPIO_NUM_18
#define RED_LED_PEDS_PIN GPIO_NUM_32
#define GREEN_LED_PEDS_PIN GPIO_NUM_33
#define WAIT_LED_PIN GPIO_NUM_22


extern "C"
{
void app_main(void)
{
    Led red_car_led(RED_LED_CARS_PIN);
    Led green_car_led(GREEN_LED_CARS_PIN);
    Led orange_car_led(ORANGE_LED_CARS_PIN);
    Led red_ped_led(RED_LED_PEDS_PIN);
    Led green_ped_led(GREEN_LED_PEDS_PIN);
    Led wait_led(WAIT_LED_PIN);
    Button semaphore_button(BUTTON_PIN);

    SemaphoreState state = SemaphoreState::OFF;
    Semaphore* Cars_semaphore = new Semaphore(red_car_led, green_car_led, Semaphore::FOR_CARS, orange_car_led);
    Semaphore* Peds_semaphore = new Semaphore(red_ped_led, green_ped_led, Semaphore::FOR_PEDS);


    while(1)
    {
        switch (state)
        {
            case SemaphoreState::OFF:
                Cars_semaphore->turnOffAllLeds();
                Peds_semaphore->turnOffAllLeds();
                state = SemaphoreState::GREEN_CARS;
                break;
            case SemaphoreState::GREEN_CARS:
                Cars_semaphore->greenLight();
                Peds_semaphore->redLight();
                while(!semaphore_button.isPressed()){
                    vTaskDelay(1);
                }
                state = SemaphoreState::BTN_PUSHED_GREEN;
                break;
            case SemaphoreState::BTN_PUSHED_GREEN:
                wait_led.on();
                vTaskDelay(5000 / portTICK_PERIOD_MS);
                state = SemaphoreState::ORANGE_AFTER_GREEN;
                break;
            case SemaphoreState::ORANGE_AFTER_GREEN:
                Cars_semaphore->orangeLight();
                vTaskDelay(2000 / portTICK_PERIOD_MS);
                state = SemaphoreState::RED_CARS;
                break;
            case SemaphoreState::RED_CARS:
                Cars_semaphore->redLight();
                vTaskDelay(1000 / portTICK_PERIOD_MS);
                state = SemaphoreState::GREEN_PEDS;
                break;
            case SemaphoreState::GREEN_PEDS:
                wait_led.off();
                Peds_semaphore->greenLight();
                vTaskDelay(5000 / portTICK_PERIOD_MS);
                state = SemaphoreState::PEDS_TRANSIT;
                break;
            case SemaphoreState::PEDS_TRANSIT:
                Peds_semaphore->redLight();
                vTaskDelay(2000 / portTICK_PERIOD_MS);
                state = SemaphoreState::ORANGE_AFTER_RED;
                break;
            case SemaphoreState::ORANGE_AFTER_RED:
                Cars_semaphore->orangeLight();
                vTaskDelay(1000 / portTICK_PERIOD_MS);
                state = SemaphoreState::GREEN_CARS;
                break;
        }
    }
}
}
