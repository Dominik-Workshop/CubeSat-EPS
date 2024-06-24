/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define USER_BUTTON_0_Pin GPIO_PIN_13
#define USER_BUTTON_0_GPIO_Port GPIOC
#define USER_BUTTON_1_Pin GPIO_PIN_14
#define USER_BUTTON_1_GPIO_Port GPIOC
#define CHARGER1_IMON_Pin GPIO_PIN_1
#define CHARGER1_IMON_GPIO_Port GPIOC
#define CHARGER2_IMON_Pin GPIO_PIN_2
#define CHARGER2_IMON_GPIO_Port GPIOC
#define CHARGER_SYNC_Pin GPIO_PIN_3
#define CHARGER_SYNC_GPIO_Port GPIOC
#define BATTERY1_VOLTAGE_Pin GPIO_PIN_1
#define BATTERY1_VOLTAGE_GPIO_Port GPIOA
#define BATTERY2_VOLTAGE_Pin GPIO_PIN_2
#define BATTERY2_VOLTAGE_GPIO_Port GPIOA
#define POWER_GOOD_3V3_Pin GPIO_PIN_4
#define POWER_GOOD_3V3_GPIO_Port GPIOC
#define MODE_3V3_Pin GPIO_PIN_5
#define MODE_3V3_GPIO_Port GPIOC
#define POWER_GOOD_5V_Pin GPIO_PIN_1
#define POWER_GOOD_5V_GPIO_Port GPIOB
#define MODE_5V_Pin GPIO_PIN_2
#define MODE_5V_GPIO_Port GPIOB
#define POWER_SWITCH2_Pin GPIO_PIN_13
#define POWER_SWITCH2_GPIO_Port GPIOB
#define POWER_SWITCH1_Pin GPIO_PIN_14
#define POWER_SWITCH1_GPIO_Port GPIOB
#define USER_LED_Pin GPIO_PIN_2
#define USER_LED_GPIO_Port GPIOD
#define POWER_GOOD_CHARGER1_Pin GPIO_PIN_6
#define POWER_GOOD_CHARGER1_GPIO_Port GPIOB
#define POWER_GOOD_CHARGER2_Pin GPIO_PIN_7
#define POWER_GOOD_CHARGER2_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
