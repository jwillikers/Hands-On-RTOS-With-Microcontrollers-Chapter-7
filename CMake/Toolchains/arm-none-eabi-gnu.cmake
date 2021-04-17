list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake/Modules)

set(CMAKE_SYSTEM_NAME ARM-GNU)
set(CMAKE_SYSTEM_PROCESSOR ARM)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

find_program(CMAKE_C_COMPILER NAMES arm-none-eabi-gcc)
find_program(CMAKE_CXX_COMPILER NAMES arm-none-eabi-g++)
find_program(CMAKE_ASM_COMPILER NAMES arm-none-eabi-gcc)
set(CMAKE_AR arm-none-eabi-ar)
set(CMAKE_OBJCOPY arm-none-eabi-objcopy)
set(CMAKE_OBJDUMP arm-none-eabi-objdump)
set(SIZE arm-none-eabi-size)

