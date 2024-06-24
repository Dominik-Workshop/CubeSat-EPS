/**
 * @file led.h
 * @brief LED control library for managing different blinking patterns.
 * @version 0.1
 * @date 2024-06-19
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef LED_H
#define LED_H

#include "stdint.h"

// Enumeration for different LED states
typedef enum {
    LED_OFF,
    LED_ON,
    LED_BLINK_SLOW,
    LED_BLINK_FAST,
	LED_BLINK_BURST
} LED_State;

// Struct to keep track of LED state and timing
typedef struct {
    LED_State state;
    uint32_t last_toggle_tick;
    uint32_t on_time;
    uint32_t off_time;
} LED;

// Function to initialize the LED state and timing
void setLedPattern(LED *led, LED_State state);

// Function to update the LED based on the state and timing
void updateLed(LED *led);

#endif // LED_H
