
#pragma once

#include <stdint.h>

#if defined __cplusplus
extern "C" {
#endif
#include "config.h"

typedef struct 
{
	void (*init)(void);
	void (*set_callback)(void (*tx_callback)(void),void (*rx_callback)(uint8 c),void (*cts_callback)(void),void (*rx_wakeup_callback)(void));
	int (*set_baudrate)(uint32_t baudrate);
	void (*receive)(uint8 *buffer, uint16_t length);
	void (*send)(const uint8 *buffer, uint16_t length);
	void (*disable_rx)(uint8 enable);
} uart_inst_t;

const uart_inst_t * get_huart_instance(void);
const uart_inst_t * get_buart_instance(void);


#if defined __cplusplus
}
#endif
