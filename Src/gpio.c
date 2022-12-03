#include "gpio.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"
#include <stdint.h>

static GPIO_InitTypeDef GPIO_InitStruct = {0};

void LED_GPIO_Init(void)
{
    /* 启用GPIO Ports时钟 */
    __HAL_RCC_GPIOB_CLK_ENABLE();

    /* 设置GPIO初始输出电平 */
    HAL_GPIO_WritePin(LED_R_Port, LED_R_Pin, GPIO_PIN_RESET);

    /* 设置GPIO */
    GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;    /* GPIO输出 */
    GPIO_InitStruct.Pull  = GPIO_PULLDOWN;          /* 下拉 */
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;    /* 低速 */

    GPIO_InitStruct.Pin   = LED_R_Pin;              /* 设置Pin */
    HAL_GPIO_Init(LED_R_Port, &GPIO_InitStruct);

    return;
}

void LED_GPIO_DeInit(void)
{
    HAL_GPIO_DeInit(LED_R_Port, LED_R_Pin);
    HAL_GPIO_DeInit(LED_G_Port, LED_G_Pin);
    HAL_GPIO_DeInit(LED_B_Port, LED_B_Pin);

    return;
}

void KEY_GPIO_Init(void)
{
    /* 启用GPIO Ports时钟 */
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();

    /* 设置GPIO初始输出电平 */
    HAL_GPIO_WritePin(KEY1_Port, KEY1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(KEY2_Port, KEY2_Pin, GPIO_PIN_RESET);

    /* 设置GPIO（没有时钟速度设置） */
    GPIO_InitStruct.Mode  = GPIO_MODE_INPUT;        /* GPIO输入 */
    GPIO_InitStruct.Pull  = GPIO_NOPULL;            /* 无上拉下拉 */

    GPIO_InitStruct.Pin   = KEY1_Pin | KEY2_Pin;    /* 设置Pin */
    HAL_GPIO_Init(KEY1_Port, &GPIO_InitStruct);

    return;
}

void KEY_GPIO_DeInit(void)
{
    HAL_GPIO_DeInit(KEY1_Port, KEY1_Pin);
    HAL_GPIO_DeInit(KEY2_Port, KEY2_Pin);

    return;
}
KEY_STATE KEY_Scan(GPIO_TypeDef *GPIOx, uint16_t GPIO_PIN)
{
    uint8_t time = 0;

    if(HAL_GPIO_ReadPin(GPIOx, GPIO_PIN) == KEY_ON)
    {
        while(HAL_GPIO_ReadPin(GPIOx, GPIO_PIN) == KEY_ON)
        {
            time++;
            HAL_Delay(1);
        }

        if(time > DELAY)
        {
            return KEY_ON;
        }
        else
        {
            return KEY_OFF;
        }
    }
    else
    {
        return KEY_OFF;
    }
}
