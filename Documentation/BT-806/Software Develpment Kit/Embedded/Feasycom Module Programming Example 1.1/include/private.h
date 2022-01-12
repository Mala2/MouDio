#ifndef __PRIVATE_H_
#define __PRIVATE_H_

#include <stdbool.h>

#include "config.h"
#include "utils.h"

#include "hal.h"
#include "hal_uart.h"


#define TICK_PERIOD_IN_MS 							(5)
#define _TO_TICKS(tm)								((tm) / TICK_PERIOD_IN_MS)
#define _TO_MSEC(tk)								((tk) * TICK_PERIOD_IN_MS)


#define LED_ON_TIMEOUT								(500)
#define LED_OFF_TIMEOUT								(500)

#define BUART_RX_DATA_BUFFER_SIZE					(1024)
#define BT_INCOMING_DATA_BUFFER_SIZE				(1024)


#define CACHE_IDX_BASE								(0)
#define CACHE_IDX_BUART_RX							(CACHE_IDX_BASE)
#define CACHE_IDX_BT_INCOMING_DATA					(CACHE_IDX_BUART_RX+1)
#define CACHE_IDX_END								(CACHE_IDX_BT_INCOMING_DATA) 
#define CACHE_MAX_NUM 								(CACHE_IDX_END+1)


typedef struct
{
	uint16_t on;
	uint16_t off;
}theLED_t;

typedef enum
{
	BTD_DISCONNECTED = 0,
	BTD_CONNECTED,
}bt_dev_state_t;

typedef struct
{
	bd_addr_t					bt_addr;
	char						bt_version[32];
	bd_addr_t					bt_paired_device[MAX_PAIRED_DEVICE_NUM];
	uint8_t						bt_plist_num;
	uint16_t					state_mask;
	bt_dev_state_t				bt_state;
	uint32_t					conn_state_detect_tickout;
#ifdef HAVE_HUART
	const uart_inst_t *			huart;
#endif
	const uart_inst_t *			buart;
}theApp_t;


void bt_led_update(void); 
uint16_t app_get_task(uint16_t mask);
void app_start_task(uint16_t mask);
void app_terminate_task(uint16_t bits);
uint32_t app_get_ticks(void);
uint32_t app_get_time(void);

extern theLED_t theLED;
extern theApp_t theApp;


#endif // __PRIVATE_H_

