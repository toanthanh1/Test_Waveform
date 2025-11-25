/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/

#include "stm32f4xx.h"




int main(void)
{
  // Enable clock for GPIOD
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;

  // Configure PD14 as output
  GPIOD->MODER &= ~(3 << (14 * 2));
  GPIOD->MODER |=  (1 << (14 * 2)); // Output mode

  while (1)
  {
    // Vo = 1 (PD14 HIGH) for 3s
    GPIOD->ODR |= (1 << 14);
    for (volatile uint32_t i = 0; i < 2400000; ++i); // ~3s delay 

    // Vo = -1 (PD14 LOW) for 2s
    GPIOD->ODR &= ~(1 << 14);
    for (volatile uint32_t i = 0; i < 1600000; ++i); // ~2s delay
  }
}


// SystemClock_Config is not needed for bare metal (HSI default)







/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */

// Error_Handler is not needed for bare metal

