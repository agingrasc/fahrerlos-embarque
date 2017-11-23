SET(CMAKE_SYSTEM_NAME Generic)

SET(CMAKE_C_COMPILER /opt/arm-none-eabi/bin/arm-none-eabi-gcc)
SET(CMAKE_CXX_COMPILER /opt/arm-none-eabi/bin/arm-none-eabi-g++)
SET(CMAKE_ASM_COMPILER /opt/arm-none-eabi/bin/arm-none-eabi-as)
SET(CMAKE_OBJCOPY "/opt/arm-none-eabi/bin/arm-none-eabi-objcopy" CACHE FILEPATH "Cross toolchain objcopy command" FORCE)

set(LINKER_SCRIPT "/home/jenifael/git/fahrerlos-embedded/stm32_flash.ld" CACHE STRING "")
SET(CMAKE_EXE_LINKER_FLAGS "--specs=nosys.specs -T ${LINKER_SCRIPT} -nostartfiles" CACHE INTERNAL "")

SET(CMAKE_FIND_ROOT_PATH /opt/arm-none-eabi/arm-none-eabi)