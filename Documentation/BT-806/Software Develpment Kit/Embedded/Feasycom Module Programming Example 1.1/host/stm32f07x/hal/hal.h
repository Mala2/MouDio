
#ifndef __HAL_H_
#define __HAL_H_

#include <string.h>  
#include <stdio.h>
#include <stdlib.h>

#include "config.h"

#include "stm32f0xx.h"
#include "stm32f0xx_it.h"


#define HOST_ENTER_CRITICAL()  do { \
	__disable_irq(); \
} while (0)
#define HOST_EXIT_CRITICAL()  do { \
	__enable_irq(); \
} while (0)


#define BT_PORT_A               0x00
#define BT_PORT_B               0x01
#define BT_PORT_C               0x02
#define BT_PORT_D               0x03
#define BT_PORT_E               0x04
#define BT_PORT_F               0x05

#define IS_VALID_GPIO_PORT(PORT) (((PORT) == BT_PORT_A) || \
                              ((PORT) == BT_PORT_B) || \
                              ((PORT) == BT_PORT_C) || \
                              ((PORT) == BT_PORT_D) || \
                              ((PORT) == BT_PORT_E) || \
                              ((PORT) == BT_PORT_F))

#define BT_PIN_0				0x00
#define BT_PIN_1				0x01
#define BT_PIN_2				0x02
#define BT_PIN_3				0x03
#define BT_PIN_4				0x04
#define BT_PIN_5				0x05
#define BT_PIN_6				0x06
#define BT_PIN_7				0x07
#define BT_PIN_8				0x08
#define BT_PIN_9				0x09
#define BT_PIN_10				0x0a
#define BT_PIN_11				0x0b
#define BT_PIN_12				0x0c
#define BT_PIN_13				0x0d
#define BT_PIN_14				0x0e
#define BT_PIN_15				0x0f

#define IS_VALID_GPIO_PIN(PIN) (((PIN) == BT_PIN_0) || \
                              ((PIN) == BT_PIN_1) || \
                              ((PIN) == BT_PIN_2) || \
                              ((PIN) == BT_PIN_3) || \
                              ((PIN) == BT_PIN_4) || \
                              ((PIN) == BT_PIN_5) || \
                              ((PIN) == BT_PIN_6) || \
                              ((PIN) == BT_PIN_7) || \
                              ((PIN) == BT_PIN_8) || \
                              ((PIN) == BT_PIN_9) || \
                              ((PIN) == BT_PIN_10) || \
                              ((PIN) == BT_PIN_11) || \
                              ((PIN) == BT_PIN_12) || \
                              ((PIN) == BT_PIN_13) || \
                              ((PIN) == BT_PIN_14) || \
                              ((PIN) == BT_PIN_15))


#define BUART_CTS_PORT           			GPIOB
#define BUART_CTS_PIN            			GPIO_Pin_13
#define BUART_RTS_PORT           			GPIOB
#define BUART_RTS_PIN            			GPIO_Pin_14

#define BUART                 				USART1
#define BUART_CLK             				RCC_APB2Periph_USART1
#define BUART_TX_PORT         				GPIOA
#define BUART_TX_PIN          				GPIO_Pin_9
#define BUART_RX_PORT         				GPIOA
#define BUART_RX_PIN          				GPIO_Pin_10
#define BUART_TX_PIN_SOURCE   				GPIO_PinSource9
#define BUART_RX_PIN_SOURCE   				GPIO_PinSource10
#define BUART_AF_N            				GPIO_AF_1
#define BUART_IRQ_HANDLER					USART1_IRQHandler
#define BUART_IRQN            				USART1_IRQn

#define HUART_CTS_PORT						GPIOA
#define HUART_CTS_PIN						GPIO_Pin_0

#define HUART                 				USART2
#define HUART_CLK             				RCC_APB1Periph_USART2
#define HUART_TX_PORT         				GPIOA
#define HUART_TX_PIN          				GPIO_Pin_2
#define HUART_RX_PORT         				GPIOA
#define HUART_RX_PIN          				GPIO_Pin_3
#define HUART_TX_PIN_SOURCE   				GPIO_PinSource2
#define HUART_RX_PIN_SOURCE   				GPIO_PinSource3
#define HUART_AF_N            				GPIO_AF_1
#define HUART_IRQ_HANDLER     				USART2_IRQHandler
#define HUART_IRQN            				USART2_IRQn


void hal_pio_set(uint8_t port, uint8_t pin);
void hal_pio_reset(uint8_t port, uint8_t pin);
int hal_pio_read(uint8_t port, uint8_t pin);
int hal_bt_connected(void);
void hal_tick_set_handler(void (*handler)(void));
void hal_init(void);

#endif // __HAL_H_

