/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.h
 * @brief          : Header for main.c file.
 *                   This file contains the common defines of the application.
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under Ultimate Liberty license
 * SLA0044, the "License"; You may not use this file except in compliance with
 * the License. You may obtain a copy of the License at:
 *                             www.st.com/SLA0044
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stm32f7xx_hal.h>

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
static constexpr uint32_t USER_Btn_Pin{GPIO_PIN_13};
#define USER_Btn_GPIO_Port GPIOC
static constexpr uint32_t  MCO_Pin{GPIO_PIN_0};
#define MCO_GPIO_Port GPIOH
static constexpr uint32_t RMII_MDC_Pin{GPIO_PIN_1};
#define RMII_MDC_GPIO_Port GPIOC
static constexpr uint32_t RMII_REF_CLK_Pin{GPIO_PIN_1};
#define RMII_REF_CLK_GPIO_Port GPIOA
static constexpr uint32_t RMII_MDIO_Pin{GPIO_PIN_2};
#define RMII_MDIO_GPIO_Port GPIOA
static constexpr uint32_t RMII_CRS_DV_Pin{GPIO_PIN_7};
#define RMII_CRS_DV_GPIO_Port GPIOA
static constexpr uint32_t RMII_RXD0_Pin{GPIO_PIN_4};
#define RMII_RXD0_GPIO_Port GPIOC
static constexpr uint32_t RMII_RXD1_Pin{GPIO_PIN_5};
#define RMII_RXD1_GPIO_Port GPIOC
static constexpr uint32_t RMII_TXD1_Pin{GPIO_PIN_13};
#define RMII_TXD1_GPIO_Port GPIOB
static constexpr uint32_t LD3_Pin{GPIO_PIN_14};
#define LD3_GPIO_Port GPIOB
static constexpr uint32_t STLK_RX_Pin{GPIO_PIN_8};
#define STLK_RX_GPIO_Port GPIOD
static constexpr uint32_t STLK_TX_Pin{GPIO_PIN_9};
#define STLK_TX_GPIO_Port GPIOD
static constexpr uint32_t USB_PowerSwitchOn_Pin{GPIO_PIN_6};
#define USB_PowerSwitchOn_GPIO_Port GPIOG
static constexpr uint32_t USB_OverCurrent_Pin{GPIO_PIN_7};
#define USB_OverCurrent_GPIO_Port GPIOG
static constexpr uint32_t USB_SOF_Pin{GPIO_PIN_8};
#define USB_SOF_GPIO_Port GPIOA
static constexpr uint32_t USB_VBUS_Pin{GPIO_PIN_9};
#define USB_VBUS_GPIO_Port GPIOA
static constexpr uint32_t USB_ID_Pin{GPIO_PIN_10};
#define USB_ID_GPIO_Port GPIOA
static constexpr uint32_t USB_DM_Pin{GPIO_PIN_11};
#define USB_DM_GPIO_Port GPIOA
static constexpr uint32_t USB_DP_Pin{GPIO_PIN_12};
#define USB_DP_GPIO_Port GPIOA
static constexpr uint32_t TMS_Pin{GPIO_PIN_13};
#define TMS_GPIO_Port GPIOA
static constexpr uint32_t TCK_Pin{GPIO_PIN_14};
#define TCK_GPIO_Port GPIOA
static constexpr uint32_t RMII_TX_EN_Pin{GPIO_PIN_11};
#define RMII_TX_EN_GPIO_Port GPIOG
static constexpr uint32_t RMII_TXD0_Pin{GPIO_PIN_13};
#define RMII_TXD0_GPIO_Port GPIOG
static constexpr uint32_t SWO_Pin{GPIO_PIN_3};
#define SWO_GPIO_Port GPIOB
static constexpr uint32_t LD2_Pin{GPIO_PIN_7};
#define LD2_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

static constexpr uint32_t LD1_Pin{GPIO_PIN_0};
#define LD1_GPIO_Port GPIOB

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
