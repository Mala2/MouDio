

#ifndef __UTILS_H
#define __UTILS_H


#if defined __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "debug.h"


#define BIT0   				0x00000001  
#define BIT1   				0x00000002 
#define BIT2   				0x00000004 
#define BIT3   				0x00000008 
#define BIT4   				0x00000010 
#define BIT5   				0x00000020 
#define BIT6   				0x00000040  
#define BIT7   				0x00000080
#define BIT8   				0x00000100 
#define BIT9   				0x00000200  
#define BIT10  				0x00000400  
#define BIT11  				0x00000800  
#define BIT12  				0x00001000  
#define BIT13  				0x00002000  
#define BIT14  				0x00004000 
#define BIT15  				0x00008000 
#define BIT16  				0x00010000 
#define BIT17  				0x00020000  
#define BIT18  				0x00040000  
#define BIT19  				0x00080000
#define BIT20  				0x00100000
#define BIT21  				0x00200000
#define BIT22  				0x00400000 
#define BIT23  				0x00800000 
#define BIT24  				0x01000000 
#define BIT25  				0x02000000 
#define BIT26  				0x04000000
#define BIT27  				0x08000000 
#define BIT28  				0x10000000  
#define BIT29  				0x20000000  
#define BIT30  				0x40000000 
#define BIT31  				0x80000000 

#define TASK_MASK_ADDR_BIT						BIT0
#define TASK_MASK_VER_BIT						BIT1
#define TASK_MASK_NAME_BIT						BIT2
#define TASK_MASK_PIN_BIT						BIT3
#define TASK_MASK_BAUD_BIT						BIT4
#define TASK_MASK_SSP_BIT						BIT5
#define TASK_MASK_COD_BIT						BIT6
#define TASK_MASK_LENAME_BIT					BIT7
#define TASK_MASK_LEADDR_BIT					BIT8
#define TASK_MASK_PLIST_BIT						BIT9
#define TASK_MASK_SCAN_BIT						BIT10


#define BD_ADDR_LEN 6
typedef uint8_t bd_addr_t[BD_ADDR_LEN];


int char2hex(uint8_t s);
char* addr_to_str(bd_addr_t addr);
int str_to_addr(bd_addr_t dest,uint8_t *p);


#define the_smaller(x,y)	(((x) < (y)) ? (x) : (y)) 
#define the_bigger(x,y)		(((x) < (y)) ? (y) : (x)) 
#define is_equal(x,y)		((x) == (y))

#define bd_addr_exist(addr) (!(!addr[0] && !addr[1] && !addr[2] && !addr[3] && !addr[4] && !addr[5]))

#define REVERSE16(v)    ((uint16_t)(v) << 8 | (uint16_t)(v) >> 8)


void delay_nops(uint32_t n);

#if defined __cplusplus
}
#endif
		
#endif // __UTILS_H
