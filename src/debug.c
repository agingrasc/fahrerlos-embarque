//
// Created by jenifael on 11/23/17.
//
#include <stm32f4xx_conf.h>
#include <misc.h>
#include "debug.h"

void init_debug_communication(uint16_t baudrate) {
    //Activation de la clock
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
    //Activation de l'alternate function
    GPIO_PinAFConfig(GPIOA, GPIO_Pin_9 | GPIO_Pin_10, GPIO_AF_USART1);

    //Init des pin TX/RX
    GPIO_InitTypeDef pin_init;
    GPIO_StructInit(&pin_init);
    pin_init.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;
    pin_init.GPIO_PuPd = GPIO_PuPd_NOPULL;
    pin_init.GPIO_OType = GPIO_OType_PP;
    pin_init.GPIO_Mode = GPIO_Mode_AF;
    GPIO_Init(GPIOA, &pin_init);

    //Init Usart
    USART_InitTypeDef usart_init;
    USART_StructInit(&usart_init);
    usart_init.USART_BaudRate = baudrate;
    usart_init.USART_Parity = USART_Parity_Even;
    usart_init.USART_WordLength = USART_WordLength_9b;
    usart_init.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    USART_Init(USART1, &usart_init);

    USART_ITConfig(USART1, USART1_IRQn, ENABLE);

    NVIC_InitTypeDef nvic_init;
    nvic_init.NVIC_IRQChannel = USART1_IRQn;
    nvic_init.NVIC_IRQChannelPreemptionPriority = 5;
    nvic_init.NVIC_IRQChannelSubPriority = 0;
    nvic_init.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&nvic_init);
}
