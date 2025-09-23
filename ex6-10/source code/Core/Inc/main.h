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
#define leg0_Pin GPIO_PIN_4
#define leg0_GPIO_Port GPIOA
#define leg1_Pin GPIO_PIN_5
#define leg1_GPIO_Port GPIOA
#define leg2_Pin GPIO_PIN_6
#define leg2_GPIO_Port GPIOA
#define leg3_Pin GPIO_PIN_7
#define leg3_GPIO_Port GPIOA
#define leg4_Pin GPIO_PIN_8
#define leg4_GPIO_Port GPIOA
#define leg5_Pin GPIO_PIN_9
#define leg5_GPIO_Port GPIOA
#define leg6_Pin GPIO_PIN_10
#define leg6_GPIO_Port GPIOA
#define leg7_Pin GPIO_PIN_11
#define leg7_GPIO_Port GPIOA
#define leg8_Pin GPIO_PIN_12
#define leg8_GPIO_Port GPIOA
#define leg9_Pin GPIO_PIN_13
#define leg9_GPIO_Port GPIOA
#define leg10_Pin GPIO_PIN_14
#define leg10_GPIO_Port GPIOA
#define leg11_Pin GPIO_PIN_15
#define leg11_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
