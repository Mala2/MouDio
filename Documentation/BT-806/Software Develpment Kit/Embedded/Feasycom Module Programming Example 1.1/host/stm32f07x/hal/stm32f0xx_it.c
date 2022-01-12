

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_it.h"
#include "hal.h"
#include "private.h"
#include "common.h"


void NMI_Handler(void)
{
	/* If HSE is not detected at program startup or HSE clock failed during program execution */
	if ((RCC_GetFlagStatus(RCC_FLAG_HSERDY) == RESET) || (RCC_GetITStatus(RCC_IT_CSS) != RESET))
	{
		/* Clear Clock Security System interrupt pending bit */
		RCC_ClearITPendingBit(RCC_IT_CSS);
		/* Enable HSE */
		RCC_HSEConfig(RCC_HSE_ON);
		/* Wait till HSE is ready */
		while (RCC_GetFlagStatus(RCC_FLAG_HSERDY) == RESET) {}
		/* Generate a system reset */
		NVIC_SystemReset();
	}
}

void HardFault_Handler(void)
{
	//while(1);
	NVIC_SystemReset();
}

void HUART_IRQ_HANDLER(void) {
	if(USART_GetITStatus(HUART,USART_IT_RXNE))
	{
		uint8_t rec = HUART->RDR;
		USART_ClearITPendingBit(HUART,USART_IT_RXNE);	
	}
	USART_ClearITPendingBit(HUART,USART_IT_ORE);
}




