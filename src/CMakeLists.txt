
add_executable(blinky)

target_sources(
    blinky
    PRIVATE
    main.cpp
    Nucleo_F767ZI_Init.cpp
    Nucleo_F767ZI_GPIO.cpp
    ${stm32cubef7_SOURCE_DIR}/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/cmsis_os2.c
    stm32f7xx_it.cpp
    stm32f7xx_hal_msp.cpp
    syscalls.cpp)

target_include_directories(
    blinky
    PRIVATE
    ${CMAKE_SOURCE_DIR}/include
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
