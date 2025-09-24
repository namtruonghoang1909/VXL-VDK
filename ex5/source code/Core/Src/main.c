/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include <stdint.h>

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define SEG_PORT GPIOB
#define LIGHT_PORT GPIOA
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
//led count
int count_x = 10;
int count_y = 10;
int counter = 0;
uint8_t digit_bits[10] = { // Binary notation
		0b1111110,//0
		0b0110000,//1
		0b1101101,//2
		0b1111001,//3
		0b0110011,//4
		0b1011011,//5
		0b1011111,//6
		0b1110000,//7
		0b1111111,//8
		0b1111011 //9
};



///----- LIGHTS CONTROL -----///
void Turn_Led_On(uint16_t ledOn, uint16_t ledOff1, uint16_t ledOff2)
{
	//function to turn on 1 led and turn off others
	HAL_GPIO_WritePin(LIGHT_PORT, ledOn, RESET);
	HAL_GPIO_WritePin(LIGHT_PORT, ledOff1, SET);
	HAL_GPIO_WritePin(LIGHT_PORT, ledOff2, SET);
}

void Traffic_Lights(int *count_x, int *count_y) //CONTROLING THE LIGHTS
{
	// RESET COUNTDOWNS
		  if(*count_x == 0) *count_x = 10;
		  if(*count_y == 0) *count_y = 10;

		  // HORIZONTAL LIGHTS//
		  if(*count_x > 5)
		  {
			  Turn_Led_On(LED_RED_X_Pin, LED_YELLOW_X_Pin, LED_GREEN_X_Pin);
		  }
		  else if(*count_x > 2)
		  {
			  Turn_Led_On(LED_GREEN_X_Pin, LED_RED_X_Pin, LED_YELLOW_X_Pin);
		  }
		  else if(*count_x > 0)
		  {
			  Turn_Led_On(LED_YELLOW_X_Pin, LED_RED_X_Pin, LED_GREEN_X_Pin);
		  }

		  //VERTICAL LIGHTS//
		  if(*count_y > 7)
		  {
			  Turn_Led_On(LED_GREEN_Y_Pin, LED_RED_Y_Pin, LED_YELLOW_Y_Pin);
		  }
		  else if(*count_y >5)
		  {
			  Turn_Led_On(LED_YELLOW_Y_Pin, LED_GREEN_Y_Pin, LED_RED_Y_Pin);
		  }
		  else if(*count_y > 0)
		  {
			  Turn_Led_On(LED_RED_Y_Pin, LED_GREEN_Y_Pin, LED_YELLOW_Y_Pin);
		  }

		  //countdown
		  (*count_x)--;
		  (*count_y)--;
}


///----- TIMER CONTROL -----///
//--- HORIZONTAL TIMER ---//
void display7SEG_x(int n)
{
	uint8_t bits_of_n = digit_bits[n];
	HAL_GPIO_WritePin(SEG_PORT, ax_Pin, (bits_of_n & 0b1000000) != 0 ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(SEG_PORT, bx_Pin, (bits_of_n & 0b0100000) != 0 ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(SEG_PORT, cx_Pin, (bits_of_n & 0b0010000) != 0 ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(SEG_PORT, dx_Pin, (bits_of_n & 0b0001000) != 0 ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(SEG_PORT, ex_Pin, (bits_of_n & 0b0000100) != 0 ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(SEG_PORT, fx_Pin, (bits_of_n & 0b0000010) != 0 ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(SEG_PORT, gx_Pin, (bits_of_n & 0b0000001) != 0 ? GPIO_PIN_RESET : GPIO_PIN_SET);
}

void horizontal_timer(int count_x)
{
	//5 -> 3 -> 2
	if(count_x >= 5)
	{
		display7SEG_x(count_x - 4);
	}
	else if(count_x >= 2)
	{
		display7SEG_x(count_x - 1);
	}
	else if(count_x >= 0)
	{
		display7SEG_x(count_x+1);
	}
}


//--- VERTICAL TIMER ---//
void display7SEG_y(int n)
{
	uint8_t bits_of_n = digit_bits[n];
	HAL_GPIO_WritePin(SEG_PORT, ay_Pin, (bits_of_n & 0b1000000) != 0 ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(SEG_PORT, by_Pin, (bits_of_n & 0b0100000) != 0 ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(SEG_PORT, cy_Pin, (bits_of_n & 0b0010000) != 0 ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(SEG_PORT, dy_Pin, (bits_of_n & 0b0001000) != 0 ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(SEG_PORT, ey_Pin, (bits_of_n & 0b0000100) != 0 ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(SEG_PORT, fy_Pin, (bits_of_n & 0b0000010) != 0 ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(SEG_PORT, gy_Pin, (bits_of_n & 0b0000001) != 0 ? GPIO_PIN_RESET : GPIO_PIN_SET);
}

void vertical_timer(int count_y)
{
	//5 -> 3 -> 2
	if(count_y >= 7)
	{
		display7SEG_y(count_y - 6);
	}
	else if(count_y >= 5)
	{
		display7SEG_y(count_y - 4);
	}
	else if(count_y >= 0)
	{
		display7SEG_y(count_y+1);
	}
}
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

	  Traffic_Lights(&count_x, &count_y);
	  horizontal_timer(count_x);
	  vertical_timer(count_y);

	  HAL_GPIO_TogglePin(HEART_GPIO_Port, HEART_Pin);
	  HAL_Delay(1000);
	  /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_RED_X_Pin|LED_YELLOW_X_Pin|LED_GREEN_X_Pin|LED_GREEN_Y_Pin
                          |LED_YELLOW_Y_Pin|LED_RED_Y_Pin|HEART_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, ax_Pin|bx_Pin|cx_Pin|cy_Pin
                          |dy_Pin|ey_Pin|fy_Pin|gy_Pin
                          |dx_Pin|ex_Pin|fx_Pin|gx_Pin
                          |ay_Pin|by_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_RED_X_Pin LED_YELLOW_X_Pin LED_GREEN_X_Pin LED_GREEN_Y_Pin
                           LED_YELLOW_Y_Pin LED_RED_Y_Pin HEART_Pin */
  GPIO_InitStruct.Pin = LED_RED_X_Pin|LED_YELLOW_X_Pin|LED_GREEN_X_Pin|LED_GREEN_Y_Pin
                          |LED_YELLOW_Y_Pin|LED_RED_Y_Pin|HEART_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : ax_Pin bx_Pin cx_Pin cy_Pin
                           dy_Pin ey_Pin fy_Pin gy_Pin
                           dx_Pin ex_Pin fx_Pin gx_Pin
                           ay_Pin by_Pin */
  GPIO_InitStruct.Pin = ax_Pin|bx_Pin|cx_Pin|cy_Pin
                          |dy_Pin|ey_Pin|fy_Pin|gy_Pin
                          |dx_Pin|ex_Pin|fx_Pin|gx_Pin
                          |ay_Pin|by_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
