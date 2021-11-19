/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
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
#include "stm32g0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
#define RXBUFFERSIZE          8 //TXBUFFERSIZE
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
extern uint8_t aRxBuffer[RXBUFFERSIZE];
/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
//PORTA
#define COLOR_595_EN_Pin 				    GPIO_PIN_5 //GPIO_PIN_14
#define COLOR_595_EN_GPIO_Port 			GPIOA //GPIOC

#define COLOR_450_EN_Pin 				    GPIO_PIN_4//GPIO_PIN_15
#define COLOR_450_EN_GPIO_Port 			GPIOA //GPIOC

#define COLOR_365_EN_Pin 				    GPIO_PIN_0//GPIO_PIN_8
#define COLOR_365_EN_GPIO_Port 			GPIOA //GPIOB

#define COLOR_850_EN_Pin 				    GPIO_PIN_6
#define COLOR_850_EN_GPIO_Port 			GPIOA

#define COLOR_940_EN_Pin 				    GPIO_PIN_7
#define COLOR_940_EN_GPIO_Port 			GPIOA

//PORTB
#define COLOR_W_EN_Pin 					    GPIO_PIN_0
#define COLOR_W_EN_GPIO_Port 			  GPIOB

#define COLOR_415_EN_Pin 				    GPIO_PIN_8//GPIO_PIN_5
#define COLOR_415_EN_GPIO_Port 			GPIOB //GPIOA

//PORTC
#define COLOR_C_505_EN_Pin 				  GPIO_PIN_15//GPIO_PIN_0
#define COLOR_C_505_EN_GPIO_Port 		GPIOC //GPIOA

#define COLOR_730_EN_Pin 				    GPIO_PIN_14//GPIO_PIN_4
#define COLOR_730_EN_GPIO_Port 			GPIOC //GPIOA
/* USER CODE BEGIN Private defines */


/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
