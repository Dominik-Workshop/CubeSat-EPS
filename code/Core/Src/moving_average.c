/**
 * @file moving_average_filter.c
 * @author Dominik Pluta
 * @brief
 * @version 0.1
 * @date 2023-04-29
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "moving_average_filter.h"

/**
 * @brief initializes the filter, this function must be called before using the filter
 *
 * @param mvngAverage
 * @param initialValue is the average value at the beginning
 */
void initAverage(MovingAverage* mvngAverage, uint16_t initialValue){
	for (int i = 0; i < NUM_OF_READINGS; ++i)
		mvngAverage->readings[i] = initialValue;
	mvngAverage->readIndex = 0;
	mvngAverage->average = initialValue;
	mvngAverage->total = initialValue * NUM_OF_READINGS;
}

/**
 * @brief calculates new average with given value "reading"
 *
 * @param mvngAverage
 * @param reading value that is being averaged out
 * @return uint16_t averaged value
 */
uint16_t calculateAverage(MovingAverage * mvngAverage, uint16_t reading){
	mvngAverage->total -= mvngAverage->readings[mvngAverage->readIndex];    //subtract the last reading:
	mvngAverage->readings[mvngAverage->readIndex] = reading;      			//read from the sensor:
	mvngAverage->total += mvngAverage->readings[mvngAverage->readIndex];    //add the reading to the total:
	++mvngAverage->readIndex;                        						//advance to the next position in the array:
	if (mvngAverage->readIndex >= NUM_OF_READINGS)   						//if we're at the end of the array...
		mvngAverage->readIndex = 0;                   						//...wrap around to the beginning:
	mvngAverage->average = mvngAverage->total / NUM_OF_READINGS;  			//calculate the average:
	return mvngAverage->average;
}
