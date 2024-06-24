/**
 * @file led.c
 * @brief LED control library for managing different blinking patterns.
 * @version 0.1
 * @date 2024-06-19
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "led.h"
#include "main.h"

void setLedPattern(LED *led, LED_State state) {
    led->state = state;
    //led->last_toggle_tick = HAL_GetTick();

    switch (state) {
        case LED_OFF:
            led->on_time = 0;
            led->off_time = 0;
            HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, GPIO_PIN_RESET);
            break;
        case LED_ON:
            led->on_time = 0;
            led->off_time = 0;
            HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, GPIO_PIN_SET);
            break;
        case LED_BLINK_SLOW:
            led->on_time = 500;
            led->off_time = 500;
            break;
        case LED_BLINK_FAST:
            led->on_time = 100;
            led->off_time = 100;
            break;
        case LED_BLINK_BURST:
			led->on_time = 50;
			led->off_time = 1000;
			break;
    }
}

void updateLed(LED *led) {
    uint32_t elapsed = HAL_GetTick() - led->last_toggle_tick;

    if (led->state == LED_ON || led->state == LED_OFF) {
        return; // No need to update if LED is constantly on or off
    }

    if (HAL_GPIO_ReadPin(USER_LED_GPIO_Port, USER_LED_Pin) == GPIO_PIN_SET) {
        // LED is currently on
        if (elapsed >= led->on_time) {
            HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, GPIO_PIN_RESET);
            led->last_toggle_tick = HAL_GetTick();
        }
    } else {
        // LED is currently off
        if (elapsed >= led->off_time) {
            HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, GPIO_PIN_SET);
            led->last_toggle_tick = HAL_GetTick();
        }
    }
}
