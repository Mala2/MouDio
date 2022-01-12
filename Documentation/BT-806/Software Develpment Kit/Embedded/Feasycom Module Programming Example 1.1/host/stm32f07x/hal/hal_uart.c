
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "private.h"
#include "debug.h"

#include "hal.h"
#include "hal_uart.h"


typedef struct
{
	uint32 baudrate;
	void (*tx_callback)(void);
	void (*rx_callback)(uint8 c);
	void (*cts_callback)(void);
	void (*rx_wakeup_callback)(void);
}theUART_t;


static USART_InitTypeDef USART_InitStructure;
static theUART_t theBUART;

#ifdef HAVE_HUART
static theUART_t theHUART;

static void phy_huart_init(void)
{
	USART_DeInit(HUART);
	USART_InitStructure.USART_BaudRate = 115200;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_Init(HUART, &USART_InitStructure);
	USART_ITConfig(HUART,USART_IT_RXNE,ENABLE);
	USART_Cmd(HUART,ENABLE);
	USART_ClearFlag(HUART,USART_FLAG_TC);
}


static void  huart_init(void)
{
	memset(&theHUART,0,sizeof(theUART_t));
	
	phy_huart_init();
}

static void huart_send(const uint8 *buffer, uint16_t length)
{
	uint16_t i;
	for(i = 0; i < length; i++)
	{
		USART_SendData(HUART,buffer[i]);
		while (USART_GetFlagStatus(HUART,USART_FLAG_TXE) == RESET) {}	
	}
}

static const uart_inst_t huart_inst =
{
	huart_init,
	NULL,
	NULL,
	NULL,
	huart_send,
	NULL,
};

const uart_inst_t * get_huart_instance(void)
{
	return &huart_inst;
}
#endif //HAVE_HUART

void phy_buart_dma_init(void)
{
	DMA_InitTypeDef   DMA_InitStructure;

	DMA_DeInit(DMA1_Channel2);
	DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&BUART->TDR;
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
	DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
	DMA_InitStructure.DMA_Priority = DMA_Priority_High;
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
	DMA_Init(DMA1_Channel2, &DMA_InitStructure);

	DMA_ITConfig(DMA1_Channel2,DMA_IT_TC,ENABLE);

	DMA_Cmd(DMA1_Channel2, DISABLE);	

	USART_DMACmd(BUART,USART_DMAReq_Tx,ENABLE);
}

static void phy_buart_init(void)
{
	USART_DeInit(BUART);
	USART_InitStructure.USART_BaudRate = 115200;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_Init(BUART, &USART_InitStructure);
	USART_Cmd(BUART,ENABLE);
	USART_ITConfig(BUART,USART_IT_RXNE,ENABLE);
	USART_Cmd(BUART,ENABLE);
	USART_ClearFlag(BUART,USART_FLAG_TC);

	phy_buart_dma_init();
}

void DMA1_Channel2_3_IRQHandler(void)
{	
	if((DMA1->ISR & DMA1_IT_TC2) != (uint32_t)RESET) 
	{
		DMA1->IFCR = DMA1_IT_GL2;
		if(theBUART.tx_callback) (*theBUART.tx_callback)();
	}
}

void BUART_IRQ_HANDLER(void) {
	if ( USART_GetITStatus(BUART,USART_IT_RXNE) )
	{
		uint8_t rec = BUART->RDR;
		USART_ClearITPendingBit(BUART,USART_IT_RXNE);
		if(theBUART.rx_callback) (*theBUART.rx_callback)(rec);
	}
	USART_ClearITPendingBit(BUART,USART_IT_ORE);
}

static void  buart_init(void)
{
	memset(&theBUART,0,sizeof(theUART_t));

	phy_buart_init();
}

static void buart_set_callback(void (*tx_callback)(void),void (*rx_callback)(uint8_t c),void (*cts_callback)(void),void (*rx_wakeup_callback)(void))
{
	theBUART.tx_callback = tx_callback;
	theBUART.rx_callback = rx_callback;	
	theBUART.cts_callback = cts_callback;
	theBUART.rx_wakeup_callback = rx_wakeup_callback;	
}

static void buart_send(const uint8 *buffer, uint16_t length)
{
	DMA1_Channel2->CCR &= ~DMA_CCR_EN;
	DMA1_Channel2->CMAR = (uint32_t)buffer;
	DMA1_Channel2->CNDTR = length;
	DMA1_Channel2->CCR |= DMA_CCR_EN;
}

static const uart_inst_t buart_inst =
{
	buart_init,
	buart_set_callback,
	NULL,
	NULL,
	buart_send,
	NULL,
};

const uart_inst_t * get_buart_instance(void)
{
	return &buart_inst;
}


