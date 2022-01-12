
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"
#include "debug.h"
#include "private.h"
#include "common.h"
#include "at_engine.h"

#include "hal_uart.h"
#include "hal.h"



#define SPLICE_TO_WRITE(params_str)		("="params_str)
#define APP_BT_NAME						"FeasycomSDK"
#define APP_BT_PIN						"1234"
#define APP_BT_BAUD						115200


static uint32_t app_ticks_now;
static uint32_t app_ticks_last;

theApp_t 	theApp;
#ifdef HAVE_LED
theLED_t	theLED;
#endif


uint8_t temp_buffer[256];
uint8_t buart_rx_data_buffer[BUART_RX_DATA_BUFFER_SIZE];
uint8_t bt_incoming_data_buffer[BT_INCOMING_DATA_BUFFER_SIZE];

#ifdef HAVE_LED
static void hal_set_led(uint16_t on_ticks,uint16_t off_ticks)
{
	theLED.on = on_ticks;
	theLED.off = off_ticks;
	hal_pio_set(BT_PORT_B,BT_PIN_2);
}
static void hal_reset_led(uint16_t on_ticks,uint16_t off_ticks)
{
	theLED.on = on_ticks;	
	theLED.off = off_ticks;
	hal_pio_reset(BT_PORT_B,BT_PIN_2);
}

void bt_led_update(void)
{
	if(!theLED.on && !theLED.off )
		return ;	
	if(theLED.on)
	{
		theLED.on--;
		if(!theLED.on)
			hal_reset_led(0, _TO_TICKS(LED_OFF_TIMEOUT));
	}
	else if(theLED.off)
	{
		theLED.off--;
		if(!theLED.off)
			hal_set_led(_TO_TICKS(LED_ON_TIMEOUT),0);
	}
}
#endif

void get_bt_mac(char *addr, int size)
{
	size = size;
	
	str_to_addr(theApp.bt_addr,(uint8_t*)&addr[1]);
	DEBUG(("BT MAC: %s",addr_to_str(theApp.bt_addr)));

	app_terminate_task(TASK_MASK_ADDR_BIT);
	app_start_task(TASK_MASK_NAME_BIT);
}

void get_bt_name(char *name, int size)
{
    // skip '='
	--size;
    name++;

	if(!memcmp(name,APP_BT_NAME,size) && size == strlen(APP_BT_NAME))
		DEBUG(("BT Name Updated"));
}

void app_excute_task(void)
{
	uint16_t tasks = theApp.state_mask;
	
	if(tasks & TASK_MASK_ADDR_BIT)
	{
		at_cmd_send(FSC_BT_ADDR,NULL,0); // read MAC address
	}
	
	if(tasks & TASK_MASK_NAME_BIT)
	{
		at_cmd_send(FSC_BT_NAME,SPLICE_TO_WRITE(APP_BT_NAME),strlen(SPLICE_TO_WRITE(APP_BT_NAME))); // write local device name
	}
}

void app_start_task(uint16_t mask)
{
	uint16_t changed_bits = (theApp.state_mask | mask) ^ theApp.state_mask;
	
	if(!changed_bits) return;

	theApp.state_mask |= mask;
}

void app_terminate_task(uint16_t mask)
{
	uint16_t changed_bits = (theApp.state_mask & ~mask) ^ theApp.state_mask;
	
	if(!changed_bits) return;
	
	theApp.state_mask &= ~mask;
}

uint16_t app_get_task(uint16_t bits)
{
	return theApp.state_mask & bits;
} 

bool event_timer_exist(uint32_t evt_tickout)
{
	return evt_tickout ? true : false;
}

void event_timer_set(uint32_t *evt_tickout, uint32_t ticks)
{
	*evt_tickout = ticks;
}

void event_process(uint32_t *evt_tickout, void (*tickout_handler)(void))
{
	volatile uint32_t *tickout = evt_tickout;
	if(*tickout)
	{
		(*tickout)--;
		if(!*tickout)
		{
			tickout_handler();
		}
	}
}

static void bt_ok_handler(int cmd_index)
{
	switch(cmd_index)
	{
		case FSC_BT_NAME:
			if(app_get_task(TASK_MASK_NAME_BIT))
			{
				app_terminate_task(TASK_MASK_NAME_BIT);
				at_cmd_send(FSC_BT_NAME,NULL,0); // read back to check
			}
			break;
		default:
			break;
	}
}

void bt_message_dispatcher(const bt_pattern_t *pattern, uint8_t *packet, int size)
{
	//DEBUG(("pattern_index=%d",pattern->index));

	switch(pattern->index)
	{
		case FSC_RESP_OK:
			bt_ok_handler(size);
			break;
		case FSC_BT_ADDR:
			get_bt_mac((char*)packet,size);
			break;
		case FSC_BT_NAME:
			get_bt_name((char*)packet,size);
			break;
		case FSC_TP_INCOMING:
			cache_push(CACHE_IDX_BT_INCOMING_DATA,packet,size);
			break;
		default:
			break;
	}
}

static void try_start_at_sequence(void)
{
	if(!bd_addr_exist(theApp.bt_addr) && !app_get_task(TASK_MASK_ADDR_BIT))
		app_start_task(TASK_MASK_ADDR_BIT);
}

static void conn_state_detect(void)
{
#ifdef HAVE_LED
	if(hal_bt_connected())
	{
		if(theApp.bt_state == BTD_DISCONNECTED)
			hal_set_led(0,0);
		theApp.bt_state = BTD_CONNECTED;
	}
	else
	{
		if(theApp.bt_state == BTD_CONNECTED)
			hal_set_led(_TO_TICKS(LED_ON_TIMEOUT), _TO_TICKS(LED_OFF_TIMEOUT));
		theApp.bt_state = BTD_DISCONNECTED;
	}
#endif
}

void app_test(void)
{
	int fifo_len = cache_size(CACHE_IDX_BT_INCOMING_DATA);
	int result;
	
	if(fifo_len)
	{
		fifo_len = cache_pop(CACHE_IDX_BT_INCOMING_DATA,temp_buffer,the_smaller(fifo_len,256),1);
		result = tp_send(temp_buffer,fifo_len); // send back to module
		if(result == BT_OK)
		{
			//DEBUG(("sent=%d",fifo_len));
			cache_pop(CACHE_IDX_BT_INCOMING_DATA,NULL,fifo_len,0);
		}
	}
}

void app_execute_once(void)
{
	try_start_at_sequence();

	app_excute_task();
	
	at_engine_run();

	app_test();

	if(app_ticks_last != app_ticks_now)
	{
		app_ticks_last = app_ticks_now;

		if(bt_initialized() && !event_timer_exist(theApp.conn_state_detect_tickout))
			event_timer_set(&theApp.conn_state_detect_tickout,_TO_TICKS(5));
		
		event_process(&theApp.conn_state_detect_tickout,conn_state_detect);
    } 
}

static void app_tick_handler(void)
{
	app_ticks_now++;
#ifdef HAVE_LED
	bt_led_update();
#endif
}

uint32_t app_get_ticks(void)
{
    return app_ticks_now;
}

uint32_t app_get_time(void)
{
    return app_ticks_now * TICK_PERIOD_IN_MS;
}

void app_execute(void)
{	
    app_ticks_now = 0;
	hal_tick_set_handler(&app_tick_handler);

    while (1)
	{
		app_execute_once();
	}
}

static void app_init(void)
{
	uint8_t i;
	memset(theApp.bt_addr,0,6);
	memset(theApp.bt_version,0,32);
	for(i = 0; i < MAX_PAIRED_DEVICE_NUM; i++)
	{
		memset(theApp.bt_paired_device[i],0,6);
	}
	theApp.bt_plist_num = 0;
	theApp.state_mask = 0;
}

static void fifo_init(void)
{
	cache_init(CACHE_IDX_BUART_RX,buart_rx_data_buffer,BUART_RX_DATA_BUFFER_SIZE);
	cache_init(CACHE_IDX_BT_INCOMING_DATA,bt_incoming_data_buffer,BT_INCOMING_DATA_BUFFER_SIZE);
}

int main(void)
{
	hal_init();
		
	app_init();
			
	fifo_init();

	DEBUG(("Feasycom SDK"));
#ifdef HAVE_LED
	hal_set_led(_TO_TICKS(LED_ON_TIMEOUT), _TO_TICKS(LED_OFF_TIMEOUT));
#endif
	at_engine_init();

	at_engine_register_message_dispatcher(bt_message_dispatcher);
	
	app_execute();

	return 0;
}

