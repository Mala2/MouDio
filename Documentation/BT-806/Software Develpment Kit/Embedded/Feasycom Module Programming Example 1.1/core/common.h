
#ifndef _COMMON_H_
#define _COMMON_H_

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "private.h"
#include "utils.h"

void cache_init(uint8_t cid, uint8_t *buffer, uint16_t size);
uint16_t cache_push(uint8_t cid, uint8_t *packet, uint16_t size);
uint16_t cache_pop(uint8_t cid, uint8_t *packet, uint16_t size, uint8_t preserve);
uint16_t cache_size(uint8_t cid);


#endif

