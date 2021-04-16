#include <main.hpp>
#include <stm32f7xx_it.hpp>

/******************************************************************************/
/*            Cortex-M7 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
 * @brief   This function handles NMI exception.
 * @param  None
 * @retval None
 */
void NMI_Handler() {}

/**
 * @brief  This function handles Hard Fault exception.
 * @param  None
 * @retval None
 */
[[noreturn]] void HardFault_Handler() {
  /* Go to infinite loop when Hard Fault exception occurs */
  while (true) {
  }
}

/**
 * @brief  This function handles Memory Manage exception.
 * @param  None
 * @retval None
 */
[[noreturn]] void MemManage_Handler() {
  /* Go to infinite loop when Memory Manage exception occurs */
  while (true) {
  }
}

/**
 * @brief  This function handles Bus Fault exception.
 * @param  None
 * @retval None
 */
[[noreturn]] void BusFault_Handler() {
  /* Go to infinite loop when Bus Fault exception occurs */
  while (true) {
  }
}

/**
 * @brief  This function handles Usage Fault exception.
 * @param  None
 * @retval None
 */
[[noreturn]] void UsageFault_Handler() {
  /* Go to infinite loop when Usage Fault exception occurs */
  while (true) {
  }
}

/**
 * @brief  This function handles SVCall exception.
 * @param  None
 * @retval None
 */
// void SVC_Handler()
//{
//}

/**
 * @brief  This function handles Debug Monitor exception.
 * @param  None
 * @retval None
 */
void DebugMon_Handler() {}

/**
 * @brief  This function handles PendSVC exception.
 * @param  None
 * @retval None
 */
// void PendSV_Handler(void)
//{
//}

/**
 * @brief  This function handles SysTick Handler.
 * @param  None
 * @retval None
 */
void SysTick_Handler() { HAL_IncTick(); }

/******************************************************************************/
/*                 STM32F7xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f7xx.s).                                               */
/******************************************************************************/

/**
 * @brief  This function handles PPP interrupt request.
 * @param  None
 * @retval None
 */
/*void PPP_IRQHandler()
{
}*/
