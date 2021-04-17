/**
 * LED implementation for Red, Green, and Blue discrete LED's on
 * Nucleo-F767ZI
 */

#include <include/Nucleo_F767ZI_GPIO.h>
#include <stm32f7xx_hal.h>

void GreenOn() { HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET); }
void GreenOff() { HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET); }
LED GreenLed = {GreenOn, GreenOff};

void BlueOn() { HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET); }
void BlueOff() { HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET); }
LED BlueLed = {BlueOn, BlueOff};

void RedOn() { HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET); }
void RedOff() { HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET); }
LED RedLed = {RedOn, RedOff};

uint_fast8_t ReadPushButton() { return HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13); }
