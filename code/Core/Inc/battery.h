/**
 * @file battery.h
 * @author Dominik Pluta
 * @brief
 * @version 1.0
 * @date 2024-06-20
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef BATTERY_H
#define BATTERY_H

#include "stdint.h"
#include "moving_average_filter.h"

#define RESOLUTION 4096 //resolution of the measurements
#define U_REF 3.3		//voltage reference of the ADC
#define R_UPPER 10000	//[ohm] upper resistor in voltage divider
#define R_LOWER 33000	//[ohm] lower resistor in voltage divider
#define R_SHUNT 0.025	//[ohm] lower resistor in voltage divider

typedef struct{
	uint16_t adcRawVoltageReading;	// 0-4095
	uint16_t adcRawCurrentReading;	// 0-4095
	uint16_t voltage_mV;
	uint16_t chargingCurrent_mA;
	MovingAverage adcRawVoltageReadingMovingAverage;
	MovingAverage adcRawCurrentReadingMovingAverage;
	uint8_t fill_level;
} Battery;

uint16_t calculateBatteryVoltage(Battery* battery);
uint16_t calculateBatteryChargingCurrent(Battery* battery);

#endif
