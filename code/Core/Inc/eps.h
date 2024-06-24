/*
 * eps.h
 *
 *  Created on: Jun 19, 2024
 *      Author: Dominik
 */

#ifndef INC_EPS_H_
#define INC_EPS_H_

#include "inttypes.h"
#include "battery.h"
#include "led.h"

/**
 * @brief Error codes for power good signal checks.
 */
typedef enum {
    POWER_GOOD_OK         = 0x00,
    POWER_GOOD_CHARGER1_FAIL = 0x01,
    POWER_GOOD_CHARGER2_FAIL = 0x02,
    POWER_GOOD_5V_FAIL       = 0x04,
    POWER_GOOD_3V3_FAIL      = 0x08
} PowerGoodStatus;

typedef struct {
    uint8_t charger_1;
    uint8_t charger_2;
    uint8_t converter_5V;
    uint8_t converter_3V3;
} PowerGood;

typedef struct {
	PowerGood powerGoodSignals;
	PowerGoodStatus powerStatus;
	Battery battery1;
	Battery battery2;
	LED led;
} EPS;

PowerGoodStatus checkPowerGoodSignals(PowerGood* pg);
void handlePowerGoodErrors(EPS* eps);
void deployAntenna();
void deploySolarPanels();

#endif /* INC_EPS_H_ */
