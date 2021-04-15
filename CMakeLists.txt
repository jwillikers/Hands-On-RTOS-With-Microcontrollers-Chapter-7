cmake_minimum_required(VERSION 3.20)
project(Hands-On-RTOS-With-Microcontrollers-Chapter-7 LANGUAGES C CXX ASM)

set(CMAKE_CXX_STANDARD 20 CACHE STRING "")
set(CMAKE_CXX_STANDARD_REQUIRED yes CACHE BOOL "")
set(CMAKE_CXX_EXTENSIONS no CACHE BOOL "")

set(CMAKE_INCLUDE_CURRENT_DIR yes)

include(FetchContent)

FetchContent_Declare(
    freertos
    GIT_REPOSITORY https://github.com/freertos/freertos.git
    GIT_TAG 202012.00
    GIT_SUBMODULES_RECURSE yes
)

FetchContent_GetProperties(freertos)

if (NOT freertos_POPULATED)
  FetchContent_Populate(freertos)
endif ()

set(FREERTOS_PATH ${freertos_SOURCE_DIR} CACHE PATH "")

FetchContent_Declare(
    stm32-cmake
    GIT_REPOSITORY https://github.com/ObKo/stm32-cmake.git
    GIT_TAG master)

FetchContent_GetProperties(stm32-cmake)

if (NOT stm32-cmake_POPULATED)
  FetchContent_Populate(stm32-cmake)
  list(APPEND CMAKE_MODULE_PATH ${stm32-cmake_SOURCE_DIR}/cmake)
endif ()

set(CMAKE_TOOLCHAIN_FILE ${stm32-cmake_SOURCE_DIR}/cmake/stm32_gcc.cmake)

include(${stm32-cmake_SOURCE_DIR}/cmake/stm32/common.cmake)
include(${stm32-cmake_SOURCE_DIR}/cmake/stm32/utilities.cmake)

stm32_fetch_cube(F7)
stm32_fetch_cmsis(F7)
stm32_fetch_hal(F7)

find_package(CMSIS COMPONENTS STM32F7 REQUIRED)
find_package(HAL COMPONENTS STM32F7 REQUIRED)
find_package(FreeRTOS COMPONENTS ARM_CM7 REQUIRED)
find_package(BSP COMPONENTS STM32F7xx_Nucleo_144 REQUIRED)

add_executable(blinky)

target_sources(
    blinky
    PRIVATE
    main.cpp
    FreeRTOSConfig.h
    stm32f7xx_hal_conf.h
    Nucleo_F767ZI_Init.cpp
    Nucleo_F767ZI_GPIO.cpp
    # todo Incorporate directly through the existing STM32CubeF7 repository: Middleware/Third_Party/Source/CMSIS_RTOS_V2
    cmsis_os2.c

    # todo Incorporate directly from template project: https://github.com/STMicroelectronics/STM32CubeF7/tree/c7c5ec99c7482ea8bcdbf0a869c930af4547088f/Projects/STM32F767ZI-Nucleo/Templates/Src
    #   Don't forget to include the corresponding headers like main.h, by the way.
    stm32f7xx_it.c
    stm32f7xx_hal_msp.c
    syscalls.c
)

target_link_libraries(
    blinky
    PRIVATE
    FreeRTOS::EventGroups
    FreeRTOS::StreamBuffer
    FreeRTOS::Timers
    FreeRTOS::Heap::4
    FreeRTOS::ARM_CM7
    HAL::STM32::F7
    HAL::STM32::F7::ADC
    HAL::STM32::F7::CORTEX
    HAL::STM32::F7::DMA
    HAL::STM32::F7::ETH
    HAL::STM32::F7::EXTI
    HAL::STM32::F7::FLASH
    HAL::STM32::F7::GPIO
    HAL::STM32::F7::I2C
    HAL::STM32::F7::PCD
    HAL::STM32::F7::PWR
    HAL::STM32::F7::PWREx
    HAL::STM32::F7::RCC
    HAL::STM32::F7::RCCEx
    HAL::STM32::F7::TIM
    HAL::STM32::F7::TIMEx
    HAL::STM32::F7::UART
    CMSIS::STM32::F767ZI
    BSP::STM32::STM32F7xx_Nucleo_144
    STM32::NoSys
)

add_custom_target(
    flash
    openocd -f board/st_nucleo_f7.cfg -c \"program $<TARGET_FILE:blinky> verify reset exit\"
    USES_TERMINAL
)
