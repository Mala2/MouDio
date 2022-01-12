//=============================================================================
// Filename  :  
//=============================================================================
// Author      :  Feasycom Software Team
// Company  :  www.feasycom.com
// Revision  :  1.0
// Date         :  4/30/2019
//=============================================================================

#include <string.h>
#include <stdio.h>

#include "private.h"

#include "hal_uart.h"
#include "hal.h"


static volatile unsigned int hsys_ticks = 0;

static void dummy_handler(void){};

static void (*tick_handler)(void) = &dummy_handler;

void hal_tick_set_handler(void (*handler)(void))
{
    if(handler == NULL)
    {
        tick_handler = &dummy_handler;
        return;
    }
    tick_handler = handler;
}

void delay_ticks(uint32_t ticks)
{
	uint32_t _ticks_last = hsys_ticks;
	while ((hsys_ticks - _ticks_last) < ticks);
}

void delay_ms(uint32_t ms)
{
	uint32_t time_last = _TO_MSEC(hsys_ticks);
	while ((_TO_MSEC(hsys_ticks) - time_last) < ms);
}

void SysTick_Handler(void)
{	
	hsys_ticks++;
	(*tick_handler)();
}

static void nvic_init(void)
{
	NVIC_InitTypeDef   NVIC_InitStructure;

	NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel2_3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPriority = 0x00;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
#ifdef HAVE_HUART
	NVIC_InitStructure.NVIC_IRQChannel = HUART_IRQN;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
#endif

	NVIC_InitStructure.NVIC_IRQChannel = BUART_IRQN;
	NVIC_Init(&NVIC_InitStructure);
}

void hal_pio_set(uint8_t port, uint8_t pin)
{
	if(!IS_VALID_GPIO_PORT(port))
		return ;
	if(!IS_VALID_GPIO_PIN(pin))
		return ;
	GPIO_SetBits((GPIO_TypeDef*)(GPIOA_BASE + port * 0x400),(uint16_t)(0x0001 << pin));
}

void hal_pio_reset(uint8_t port, uint8_t pin)
{
	if(!IS_VALID_GPIO_PORT(port))
		return ;
	if(!IS_VALID_GPIO_PIN(pin))
		return ;
	GPIO_ResetBits((GPIO_TypeDef*)(GPIOA_BASE + port * 0x400),(uint16_t)(0x0001 << pin));		
}

int hal_pio_read(uint8_t port, uint8_t pin)
{
	if(!IS_VALID_GPIO_PORT(port))
		return 0;
	if(!IS_VALID_GPIO_PIN(pin))
		return 0;
	return GPIO_ReadInputDataBit((GPIO_TypeDef*)(GPIOA_BASE + port * 0x400),(uint16_t)(0x0001 << pin));
}

int hal_bt_connected(void)
{
	return hal_pio_read(BT_PORT_A,BT_PIN_0);
}

static void hal_gpio_init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;

	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
#ifdef HAVE_HUART
	GPIO_InitStructure.GPIO_Pin = HUART_RX_PIN;
	GPIO_Init(HUART_RX_PORT, &GPIO_InitStructure);
#endif
	GPIO_InitStructure.GPIO_Pin = BUART_RX_PIN;
	GPIO_Init(BUART_RX_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
#ifdef HAVE_HUART
	GPIO_InitStructure.GPIO_Pin = HUART_TX_PIN;
	GPIO_Init(HUART_TX_PORT, &GPIO_InitStructure);
#endif
	GPIO_InitStructure.GPIO_Pin = BUART_TX_PIN;
	GPIO_Init(BUART_TX_PORT, &GPIO_InitStructure);

#ifdef HAVE_HUART
	GPIO_PinAFConfig(HUART_TX_PORT,HUART_TX_PIN_SOURCE,HUART_AF_N);
	GPIO_PinAFConfig(HUART_RX_PORT,HUART_RX_PIN_SOURCE,HUART_AF_N);
#endif
	GPIO_PinAFConfig(BUART_TX_PORT,BUART_TX_PIN_SOURCE,BUART_AF_N);
	GPIO_PinAFConfig(BUART_RX_PORT,BUART_RX_PIN_SOURCE,BUART_AF_N);

#ifdef HAVE_LED
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2; //PB2 PIN32 LED
	GPIO_Init(GPIOB, &GPIO_InitStructure);
#endif

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0; //PA0 for reading BT connection status
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}

static void hal_system_tick_init(void)
{
	RCC_ClocksTypeDef RCC_Clocks;
	RCC_GetClocksFreq(&RCC_Clocks);
	SysTick_Config(RCC_Clocks.SYSCLK_Frequency * TICK_PERIOD_IN_MS / 1000);
}

static void hal_uart_init(void)
{
#ifdef HAVE_HUART
	theApp.huart = get_huart_instance();
	theApp.huart->init();
#endif
	theApp.buart = get_buart_instance();
	theApp.buart->init();
}

void hal_init(void)
{
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA | RCC_AHBPeriph_GPIOB | RCC_AHBPeriph_GPIOC | RCC_AHBPeriph_GPIOF | RCC_AHBPeriph_DMA1, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR | HUART_CLK | RCC_APB1Periph_TIM3, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG | BUART_CLK, ENABLE);

	hal_system_tick_init();

	hal_gpio_init();

	nvic_init();

	hal_uart_init();
}


