/*
 * eps.c
 *
 *  Created on: Jun 19, 2024
 *      Author: Dominik
 */

#include "eps.h"
#include "main.h"

/**
 * @brief Checks the status of power good signals.
 *
 * @param pg Pointer to a PowerGood structure where the signal status will be stored.
 * @return uint8_t Bitmask indicating the status of the signals.
 */
uint8_t checkPowerGoodSignals(PowerGood* pg) {
	uint8_t status = POWER_GOOD_OK;

	pg->charger_1 = HAL_GPIO_ReadPin(POWER_GOOD_CHARGER1_GPIO_Port, POWER_GOOD_CHARGER1_Pin);
	if (!pg->charger_1) {
		status |= POWER_GOOD_CHARGER1_FAIL;
	}

	pg->charger_2 = HAL_GPIO_ReadPin(POWER_GOOD_CHARGER2_GPIO_Port, POWER_GOOD_CHARGER2_Pin);
	if (!pg->charger_2) {
		status |= POWER_GOOD_CHARGER2_FAIL;
	}

	pg->converter_5V = HAL_GPIO_ReadPin(POWER_GOOD_5V_GPIO_Port, POWER_GOOD_5V_Pin);
	if (!pg->converter_5V) {
		status |= POWER_GOOD_5V_FAIL;
	}

	pg->converter_3V3 = HAL_GPIO_ReadPin(POWER_GOOD_3V3_GPIO_Port, POWER_GOOD_3V3_Pin);
	if (!pg->converter_3V3) {
		status |= POWER_GOOD_3V3_FAIL;
	}

	return status;
}

/**
 * @brief Handles errors based on the power good status bitmask.
 *
 * @param status Bitmask indicating which power good signals have failed.
 */
void handlePowerGoodErrors(EPS* eps){
	if (eps->powerStatus == POWER_GOOD_OK) {
		setLedPattern(&(eps->led), LED_BLINK_SLOW);
		return;
	}

	if (eps->powerStatus & POWER_GOOD_CHARGER1_FAIL) {
		setLedPattern(&(eps->led), LED_BLINK_BURST);
	}

	if (eps->powerStatus & POWER_GOOD_CHARGER2_FAIL) {
		setLedPattern(&(eps->led), LED_BLINK_BURST);
	}

	if (eps->powerStatus & POWER_GOOD_5V_FAIL) {
		setLedPattern(&(eps->led), LED_BLINK_FAST);
	}

	if (eps->powerStatus & POWER_GOOD_3V3_FAIL) {
		setLedPattern(&(eps->led), LED_BLINK_FAST);
	}
}

void deployAntenna(){
	HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(POWER_SWITCH2_GPIO_Port, POWER_SWITCH2_Pin, GPIO_PIN_SET);
	HAL_Delay(5000);
	HAL_GPIO_WritePin(POWER_SWITCH2_GPIO_Port, POWER_SWITCH2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, GPIO_PIN_RESET);
}
void deploySolarPanels(){
	HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(POWER_SWITCH1_GPIO_Port, POWER_SWITCH1_Pin, GPIO_PIN_SET);
	HAL_Delay(5000);
	HAL_GPIO_WritePin(POWER_SWITCH1_GPIO_Port, POWER_SWITCH1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, GPIO_PIN_RESET);
}
