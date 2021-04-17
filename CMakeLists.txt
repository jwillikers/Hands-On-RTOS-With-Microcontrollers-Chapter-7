cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

function(build_bin_firmware TARGET_NAME)
  set(BIN_FILE ${PROJECT_BINARY_DIR}/${TARGET_NAME}.bin)
  add_custom_command(
    TARGET ${TARGET_NAME}
    POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -Obinary $<TARGET_FILE:${TARGET_NAME}> ${BIN_FILE}
    BYPRODUCTS ${BIN_FILE}
    COMMENT "Building ${BIN_FILE}")
endfunction()

function(build_hex_firmware TARGET_NAME)
  set(HEX_FILE ${PROJECT_BINARY_DIR}/${TARGET_NAME}.hex)
  add_custom_command(
    TARGET ${TARGET_NAME}
    POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -Oihex $<TARGET_FILE:${TARGET_NAME}> ${HEX_FILE}
    BYPRODUCTS ${HEX_FILE}
    COMMENT "Building ${HEX_FILE}")
endfunction()

project(
  Hands-On-RTOS-With-Microcontrollers-Chapter-7
  VERSION 0.0.1
  DESCRIPTION
    "LED-blinking application for Chapter 7 of Hands-On RTOS With Microcontrollers"
  HOMEPAGE_URL
    https://github.com/jwillikers/Hands-On-RTOS-With-Microcontrollers-Chapter-7
  LANGUAGES ASM C CXX)

set(CMAKE_CXX_STANDARD
    20
    CACHE STRING "")
set(CMAKE_CXX_STANDARD_REQUIRED
    yes
    CACHE BOOL "")
set(CMAKE_CXX_EXTENSIONS
    no
    CACHE BOOL "")

set(CMAKE_INTERPROCEDURAL_OPTIMIZATION
    yes
    CACHE BOOL "")

set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS no)
set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)

include(FetchContent)

FetchContent_Declare(
  cmake-scripts
  GIT_REPOSITORY https://github.com/StableCoder/cmake-scripts
  GIT_TAG 21.01)
FetchContent_GetProperties(cmake-scripts)
if(NOT cmake-scripts_POPULATED)
  FetchContent_Populate(cmake-scripts)
  list(APPEND CMAKE_MODULE_PATH ${cmake-scripts_SOURCE_DIR})
endif()

include(sanitizers)

set(FORMAT_CHECK_CMAKE
    yes
    CACHE BOOL "")
FetchContent_Declare(
  format
  GIT_REPOSITORY https://github.com/TheLartians/Format.cmake.git
  GIT_TAG v1.7.1)
FetchContent_MakeAvailable(format)

set(USE_CCACHE
    yes
    CACHE BOOL "")
FetchContent_Declare(
  ccache.cmake
  GIT_REPOSITORY https://github.com/TheLartians/Ccache.cmake.git
  GIT_TAG v1.2.3)
FetchContent_MakeAvailable(ccache.cmake)

FetchContent_Declare(
  freertos
  GIT_REPOSITORY https://github.com/freertos/freertos.git
  GIT_TAG 202012.00
  GIT_SUBMODULES_RECURSE yes)

FetchContent_GetProperties(freertos)

if(NOT freertos_POPULATED)
  FetchContent_Populate(freertos)
endif()

set(FREERTOS_PATH
    ${freertos_SOURCE_DIR}
    CACHE PATH "")

FetchContent_Declare(
  stm32-cmake
  GIT_REPOSITORY https://github.com/ObKo/stm32-cmake.git
  GIT_TAG master)

FetchContent_GetProperties(stm32-cmake)

if(NOT stm32-cmake_POPULATED)
  FetchContent_Populate(stm32-cmake)
  list(APPEND CMAKE_MODULE_PATH ${stm32-cmake_SOURCE_DIR}/cmake)
endif()

set(CMAKE_TOOLCHAIN_FILE ${stm32-cmake_SOURCE_DIR}/cmake/stm32_gcc.cmake)

include(${stm32-cmake_SOURCE_DIR}/cmake/stm32/common.cmake)
include(${stm32-cmake_SOURCE_DIR}/cmake/stm32/utilities.cmake)

stm32_fetch_cube(F7)
stm32_fetch_cmsis(F7)
stm32_fetch_hal(F7)

FetchContent_GetProperties(stm32cubef7)

find_package(
  CMSIS
  COMPONENTS STM32F7
  REQUIRED)
find_package(
  HAL
  COMPONENTS STM32F7
  REQUIRED)
find_package(
  FreeRTOS
  COMPONENTS ARM_CM7
  REQUIRED)
find_package(
  BSP
  COMPONENTS STM32F7xx_Nucleo_144
  REQUIRED)

add_executable(blinky)

target_sources(
  blinky
  PRIVATE
    src/main.cpp
    src/Nucleo_F767ZI_Init.cpp
    src/Nucleo_F767ZI_GPIO.cpp
    ${stm32cubef7_SOURCE_DIR}/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/cmsis_os2.c
    src/stm32f7xx_it.cpp
    src/stm32f7xx_hal_msp.cpp
    src/syscalls.cpp)

target_include_directories(
  blinky
  PRIVATE
    include
    ${stm32cubef7_SOURCE_DIR}/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2
)

target_link_libraries(
  blinky
  PRIVATE FreeRTOS::EventGroups
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
          STM32::NoSys)

target_link_options(
  blinky PRIVATE LINKER:-gc-sections LINKER:--print-memory-usage
  LINKER:-Map=${PROJECT_BINARY_DIR}/${PROJECT_NAME}.map)

build_bin_firmware(blinky)

build_hex_firmware(blinky)

add_custom_target(
  flash
  openocd
  -f
  board/st_nucleo_f7.cfg
  -c
  \"program
  $<TARGET_FILE:blinky>
  verify
  reset
  exit\"
  USES_TERMINAL)
