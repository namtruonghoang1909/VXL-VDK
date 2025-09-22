/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2025 STMicroelectronics.
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
#include "stm32f1xx_hal.h"

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
#define LED_RED_X_Pin GPIO_PIN_1
#define LED_RED_X_GPIO_Port GPIOA
#define LED_YELLOW_X_Pin GPIO_PIN_2
#define LED_YELLOW_X_GPIO_Port GPIOA
#define LED_GREEN_X_Pin GPIO_PIN_3
#define LED_GREEN_X_GPIO_Port GPIOA
#define LED_GREEN_Y_Pin GPIO_PIN_4
#define LED_GREEN_Y_GPIO_Port GPIOA
#define LED_YELLOW_Y_Pin GPIO_PIN_5
#define LED_YELLOW_Y_GPIO_Port GPIOA
#define LED_RED_Y_Pin GPIO_PIN_6
#define LED_RED_Y_GPIO_Port GPIOA
#define ax_Pin GPIO_PIN_0
#define ax_GPIO_Port GPIOB
#define bx_Pin GPIO_PIN_1
#define bx_GPIO_Port GPIOB
#define cx_Pin GPIO_PIN_2
#define cx_GPIO_Port GPIOB
#define cy_Pin GPIO_PIN_10
#define cy_GPIO_Port GPIOB
#define dy_Pin GPIO_PIN_11
#define dy_GPIO_Port GPIOB
#define ey_Pin GPIO_PIN_12
#define ey_GPIO_Port GPIOB
#define fy_Pin GPIO_PIN_13
#define fy_GPIO_Port GPIOB
#define gy_Pin GPIO_PIN_14
#define gy_GPIO_Port GPIOB
#define dx_Pin GPIO_PIN_3
#define dx_GPIO_Port GPIOB
#define ex_Pin GPIO_PIN_4
#define ex_GPIO_Port GPIOB
#define fx_Pin GPIO_PIN_5
#define fx_GPIO_Port GPIOB
#define gx_Pin GPIO_PIN_6
#define gx_GPIO_Port GPIOB
#define ay_Pin GPIO_PIN_8
#define ay_GPIO_Port GPIOB
#define by_Pin GPIO_PIN_9
#define by_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
