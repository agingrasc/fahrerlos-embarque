#include <stm32f4xx_conf.h>
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_conf.h"

#include "debug.h"

uint32_t timestamp;


void SysTick_Handler() {
    timestamp++;
}

void delay(uint32_t delay) {
    uint32_t target_time = delay + timestamp;
    while (timestamp < target_time);
}

int main() {
    SystemInit();

    SysTick_Config(SystemCoreClock/1000);

    GPIO_InitTypeDef gpio_init;
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

    gpio_init.GPIO_Mode = GPIO_Mode_OUT;
    gpio_init.GPIO_Pin = GPIO_Pin_15;
    gpio_init.GPIO_Speed = GPIO_Speed_100MHz;
    gpio_init.GPIO_OType = GPIO_OType_PP;
    gpio_init.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOD, &gpio_init);

    GPIO_ResetBits(GPIOD, GPIO_Pin_15);

    while(1) {
        GPIO_ToggleBits(GPIOD, GPIO_Pin_15);
        delay(500);
    }
}