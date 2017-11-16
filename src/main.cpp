#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include <stm32f4xx_conf.h>


int main() {
    GPIO_InitTypeDef gpio_init;
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

    gpio_init.GPIO_Mode = GPIO_Mode_OUT;
    gpio_init.GPIO_Pin = GPIO_Pin_15;
    GPIO_Init(GPIOD, &gpio_init);

    while(true) {
        for (int i = 0; i < 10000; i++) {
            (void)0;
        }
        GPIO_ToggleBits(GPIOD, GPIO_Pin_15);
    }
}