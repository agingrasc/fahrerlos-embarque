cmake_minimum_required(VERSION 2.6)
project(fahrerlos-embedded C ASM)

set(CMAKE_VERBOSE_MAKEFILE ON)

function(add_bin_from_elf bin elf)
    add_custom_target(${bin} ALL ${CMAKE_OBJCOPY} -Obinary ${elf} ${bin} DEPENDS ${elf})
endfunction()

include_directories("./inc"
        "STM32F4-Discovery_FW_V1.1.0/Libraries/CMSIS/Include"
        "STM32F4-Discovery_FW_V1.1.0/Libraries/CMSIS/ST/STM32F4xx/Include"
        "STM32F4-Discovery_FW_V1.1.0/Libraries/STM32F4xx_StdPeriph_Driver/inc")

set(STM_SRC
        STM32F4-Discovery_FW_V1.1.0/Libraries/STM32F4xx_StdPeriph_Driver/src)

set(SOURCE_FILES
        src/main.c
        src/system_stm32f4xx.c
        ${STM_SRC}/stm32f4xx_rcc.c
        ${STM_SRC}/stm32f4xx_gpio.c)

set(GENERAL_COMPILE_FLAGS "-Wall")
set(STM32_FLAGS "-mfpu=fpv4-sp-d16 -mthumb -mthumb-interwork -mlittle-endian -mfloat-abi=soft -march=armv7-m")
set(GENERAL_COMPILE_DEFINES "-DSTM32F4 -DUSE_STDPERIPH_DRIVER -DSTM32F40XX -DSTM32F40_41xx")

set_source_files_properties(${SOURCE_FILES} PROPERTY COMPILE_FLAGS "${GENERAL_COMPILE_DEFINES} ${GENERAL_COMPILE_FLAGS}")
if(${CMAKE_TOOLCHAIN_FILE} OR ${CMAKE_TOOLCHAIN_FILE} STREQUAL "toolchain-arm-none-eabi.cmake")
    #link_directories(/opt/arm-none-eabi/lib/hard /opt/arm-none-eabi/arm-none-eabi/lib/hard)
    set_source_files_properties(${SOURCE_FILES} PROPERTIES COMPILE_FLAGS "${STM32_FLAGS} ${GENERAL_COMPILE_FLAGS} ${GENERAL_COMPILE_DEFINES}")
endif()

set_source_files_properties(startup/startup_stm32.s PROPERTIES COMPILE_FLAGS "${STM32_FLAGS}" LANGUAGE ASM)
add_executable(fahrerlos-test ${SOURCE_FILES})
add_executable(${PROJECT_NAME}.elf ${SOURCE_FILES} startup/startup_stm32.s)
add_bin_from_elf(${PROJECT_NAME}.bin ${PROJECT_NAME}.elf)
add_custom_command(TARGET ${PROJECT_NAME}.bin POST_BUILD COMMAND st-flash write ${PROJECT_NAME}.bin 0x8000000)