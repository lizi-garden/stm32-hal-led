#ifndef _GPIO_H
#define _GPIO_H

/* Include begin */
#include <stdbool.h>
#include <stdint.h>
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"
#include "stm32f1xx_hal_rcc.h"
#include "stm32f1xx_hal_rcc_ex.h"

/* Include end */

/* define Pin begin */
#define LED_R_Pin       GPIO_PIN_5
#define LED_G_Pin       GPIO_PIN_0
#define LED_B_Pin       GPIO_PIN_1

#define KEY1_Pin        GPIO_PIN_0
#define KEY2_Pin        GPIO_PIN_13

/* define Pin end */

/* define Port begin */
#define LED_R_Port      GPIOB
#define LED_G_Port      GPIOB
#define LED_B_Port      GPIOB

#define KEY1_Port       GPIOA
#define KEY2_Port       GPIOC

/* define Port end */

/* named function more friendly begin */
#define LED_R_TOGGLE    HAL_GPIO_TogglePin(LED_R_Port, LED_R_Pin)
#define LED_R_OFF       HAL_GPIO_WritePin(LED_R_Port, LED_R_Pin, GPIO_PIN_SET)
#define LED_R_ON        HAL_GPIO_WritePin(LED_R_Port, LED_R_Pin, GPIO_PIN_RESET)

#define LED_G_TOGGLE    HAL_GPIO_TogglePin(LED_G_Port, LED_G_Pin)
#define LED_G_OFF       HAL_GPIO_WritePin(LED_G_Port, LED_G_Pin, GPIO_PIN_SET)
#define LED_G_ON        HAL_GPIO_WritePin(LED_G_Port, LED_G_Pin, GPIO_PIN_RESET)

#define LED_B_TOGGLE    HAL_GPIO_TogglePin(LED_B_Port, LED_B_Pin)
#define LED_B_OFF       HAL_GPIO_WritePin(LED_B_Port, LED_B_Pin, GPIO_PIN_SET)
#define LED_B_ON        HAL_GPIO_WritePin(LED_B_Port, LED_B_Pin, GPIO_PIN_RESET)

/* named function friendly end */

/* define constant begin */
#define DELAY 10

/* define constant end */

/* define struct begin */
#define KEY_ON      GPIO_PIN_SET
#define KEY_OFF     GPIO_PIN_RESET
#define KEY_STATE   GPIO_PinState

/* define struct end */

void LED_GPIO_Init(void);

void LED_GPIO_DeInit(void);

void KEY_GPIO_Init(void);

void KEY_GPIO_DeInit(void);

KEY_STATE KEY_Scan(GPIO_TypeDef *GPIOx, uint16_t GPIO_PIN);

#endif
