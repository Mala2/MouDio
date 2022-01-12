

#include <stdio.h>

#include "config.h"
#include "debug.h"

#include "utils.h"


char char_for_nibble(int nibble)
{
	if(nibble < 10) return '0' + nibble;
	nibble -= 10;
	if(nibble < 6) return 'A' + nibble;
	return '?';	
}

int char2hex(uint8_t s) 
{
	return ((s>= '0' && s<='9') ? (s-'0') : ((s>= 'a' && s<='f') ? (s-'a'+0xa) :(((s>= 'A' && s<='F') ? (s-'A'+0xa) :0xffff))));
}

static char bd_addr_to_str_buffer[13];  // 112233445566\0
char* addr_to_str(bd_addr_t addr)
{
	char * p = bd_addr_to_str_buffer;
	int i;
	for (i = 0; i < 6;i++) 
	{
		*p++ = char_for_nibble((addr[i] >> 4) & 0x0F);
		*p++ = char_for_nibble((addr[i] >> 0) & 0x0F);
	}
	bd_addr_to_str_buffer[12] = 0;
	return (char *) bd_addr_to_str_buffer;
}

int str_to_addr(bd_addr_t dest,uint8_t *p) 
{
	int i;
	int32_t high_4bits;
	int32_t low_4bits;
	for( i = 0 ; i < 6 ; i++)
	{
		high_4bits = char2hex(p[2*i]);
		low_4bits = char2hex(p[2*i+1]);
		if (high_4bits == 0xffff || low_4bits == 0xffff) {
			return -1;
		}
		dest[i] = high_4bits << 4 | low_4bits;
	}
	return 0;
}

void delay_nops(uint32_t n) 
{
	volatile uint32_t i;
	for (i=0;i<n;i++);
}


