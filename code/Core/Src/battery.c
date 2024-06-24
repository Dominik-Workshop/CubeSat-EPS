/**
 * @file battery.c
 * @author Dominik Pluta
 * @brief
 * @version 0.1
 * @date 2023-04-29
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "battery.h"


/**
 * @brief calculates battery voltage based on the averaged out value from the ADC
 *
 * @param battery
 * @return float calculated voltage
 */
uint16_t calculateBatteryVoltage(Battery* battery){
	calculateAverage(&(battery->adcRawVoltageReadingMovingAverage), battery->adcRawVoltageReading);
	battery->voltage_mV = 1000.0 * battery->adcRawVoltageReadingMovingAverage.average * U_REF / RESOLUTION * (R_UPPER + R_LOWER) / R_LOWER;
	return battery->voltage_mV;
}

uint16_t calculateBatteryChargingCurrent(Battery* battery){
	calculateAverage(&(battery->adcRawCurrentReadingMovingAverage), battery->adcRawCurrentReading);
	battery->chargingCurrent_mA = 1000.0 * battery->adcRawCurrentReadingMovingAverage.average * U_REF / RESOLUTION / 20 / R_SHUNT;
	return battery->voltage_mV;
}
