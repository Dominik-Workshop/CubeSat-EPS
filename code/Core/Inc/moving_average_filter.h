/**
 * @file moving_average_filter.h
 * @author Dominik Pluta
 * @brief
 * @version 0.1
 * @date 2023-04-29
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef MOVING_AVERAGE_FILTER_H
#define MOVING_AVERAGE_FILTER_H

#include "stdint.h"
#define NUM_OF_READINGS 20

typedef struct {
	uint16_t readings[NUM_OF_READINGS]; //stores defined amount of readings to be averaged out
	uint8_t readIndex;         			//the index of the current reading
	uint32_t total;                     //sum of all readings
	uint16_t average;
}MovingAverage;

void initAverage(MovingAverage * mvngAverage, uint16_t initialValue);
uint16_t calculateAverage(MovingAverage * mvngAverage, uint16_t reading);

#endif
