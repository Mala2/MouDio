

#ifndef __MODULE_H
#define __MODULE_H


#if defined __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "debug.h"
#include "at_engine.h"

typedef struct
{
	uint16_t init_time;
	uint16_t dedicated_at_response_timeout;
	const bt_pattern_t *bt_pattern_table;
} module_t;

extern const module_t* get_module(void);

#if defined __cplusplus
}
#endif
		
#endif // __MODULE_H
