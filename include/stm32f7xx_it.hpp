#pragma once

void NMI_Handler();
[[noreturn]] void HardFault_Handler();
[[noreturn]] void MemManage_Handler();
[[noreturn]] void BusFault_Handler();
[[noreturn]] void UsageFault_Handler();
void DebugMon_Handler();
void SysTick_Handler();
