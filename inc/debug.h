//
// Created by jenifael on 11/23/17.
//

#ifndef FAHRERLOS_EMBEDDED_DEBUG_H
#define FAHRERLOS_EMBEDDED_DEBUG_H

#include "stm32f4xx_usart.h"
#include "misc.h"

#define DEBUG_TX GPIO_Pin_9;
#define DEBUG_RX GPIO_Pin_10;

void init_debug_communication(uint16_t baudrate);

#endif //FAHRERLOS_EMBEDDED_DEBUG_H
