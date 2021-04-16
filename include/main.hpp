#pragma once

#include <stm32f7xx_hal.h>

#define USER_Btn_GPIO_Port GPIOC
#define MCO_GPIO_Port GPIOH
#define RMII_MDC_GPIO_Port GPIOC
#define RMII_REF_CLK_GPIO_Port GPIOA
#define RMII_MDIO_GPIO_Port GPIOA
#define RMII_CRS_DV_GPIO_Port GPIOA
#define RMII_RXD0_GPIO_Port GPIOC
#define RMII_RXD1_GPIO_Port GPIOC
#define RMII_TXD1_GPIO_Port GPIOB
#define LD3_GPIO_Port GPIOB
#define STLK_RX_GPIO_Port GPIOD
#define STLK_TX_GPIO_Port GPIOD
#define USB_PowerSwitchOn_GPIO_Port GPIOG
#define USB_OverCurrent_GPIO_Port GPIOG
#define USB_SOF_GPIO_Port GPIOA
#define USB_VBUS_GPIO_Port GPIOA
#define USB_ID_GPIO_Port GPIOA
#define USB_DM_GPIO_Port GPIOA
#define USB_DP_GPIO_Port GPIOA
#define TMS_GPIO_Port GPIOA
#define TCK_GPIO_Port GPIOA
#define RMII_TX_EN_GPIO_Port GPIOG
#define RMII_TXD0_GPIO_Port GPIOG
#define SWO_GPIO_Port GPIOB
#define LD2_GPIO_Port GPIOB
#define LD1_GPIO_Port GPIOB

void Error_Handler();

constexpr uint_fast8_t USER_Btn_Pin{GPIO_PIN_13};
constexpr uint16_t MCO_Pin{GPIO_PIN_0};
constexpr uint16_t RMII_MDC_Pin{GPIO_PIN_1};
constexpr uint16_t RMII_REF_CLK_Pin{GPIO_PIN_1};
constexpr uint16_t RMII_MDIO_Pin{GPIO_PIN_2};
constexpr uint16_t RMII_CRS_DV_Pin{GPIO_PIN_7};
constexpr uint16_t RMII_RXD0_Pin{GPIO_PIN_4};
constexpr uint16_t RMII_RXD1_Pin{GPIO_PIN_5};
constexpr uint16_t RMII_TXD1_Pin{GPIO_PIN_13};
constexpr uint16_t LD3_Pin{GPIO_PIN_14};
constexpr uint16_t STLK_RX_Pin{GPIO_PIN_8};
constexpr uint16_t STLK_TX_Pin{GPIO_PIN_9};
constexpr uint16_t USB_PowerSwitchOn_Pin{GPIO_PIN_6};
constexpr uint16_t USB_OverCurrent_Pin{GPIO_PIN_7};
constexpr uint16_t USB_SOF_Pin{GPIO_PIN_8};
constexpr uint16_t USB_VBUS_Pin{GPIO_PIN_9};
constexpr uint16_t USB_ID_Pin{GPIO_PIN_10};
constexpr uint16_t USB_DM_Pin{GPIO_PIN_11};
constexpr uint16_t USB_DP_Pin{GPIO_PIN_12};
constexpr uint16_t TMS_Pin{GPIO_PIN_13};
constexpr uint16_t TCK_Pin{GPIO_PIN_14};
constexpr uint16_t RMII_TX_EN_Pin{GPIO_PIN_11};
constexpr uint16_t RMII_TXD0_Pin{GPIO_PIN_13};
constexpr uint16_t SWO_Pin{GPIO_PIN_3};
constexpr uint16_t LD2_Pin{GPIO_PIN_7};
constexpr uint16_t LD1_Pin{GPIO_PIN_0};
