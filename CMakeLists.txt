cmake_minimum_required(VERSION 2.6)
project(fahrerlos-embedded)

include_directories("./inc"
        "STM32F4-Discovery_FW_V1.1.0/Libraries/CMSIS/Include"
        "STM32F4-Discovery_FW_V1.1.0/Libraries/CMSIS/ST/STM32F4xx/Include"
        "STM32F4-Discovery_FW_V1.1.0/Libraries/STM32F4xx_StdPeriph_Driver/inc")

set(STM_SRC
        STM32F4-Discovery_FW_V1.1.0/Libraries/STM32F4xx_StdPeriph_Driver/src)

set(SOURCE_FILES
        src/main.cpp
        ${STM_SRC}/stm32f4xx_rcc.c
        ${STM_SRC}/stm32f4xx_gpio.c)

set(COMPILE_DEFINES "-DSTM32F4 -DUSE_STDPERIPH_DRIVER -DSTM32F40XX -DSTM32F40_41xx")

#set_source_files_properties(${SOURCE_FILES} PROPERTY COMPILE_FLAGS "${COMPILE_DEFINES}")
add_definitions(-DSTM32F4 -DUSE_STDPERIPH_DRIVER)
add_executable(main ${SOURCE_FILES})