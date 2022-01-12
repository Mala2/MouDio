

#include <string.h>
#include <stdarg.h>

#include "debug.h"
#include "at_engine.h"

#include "common.h"




#ifdef HAVE_HUART
static char btprintf_buffer[128];
void dbg_printf( const char* Format, ... )
{
	va_list	 parms;
	uint16_t length = 0x00;
	va_start( parms, Format );
	length += vsprintf( &btprintf_buffer[0], Format, parms );
	va_end(parms);

	memcpy(btprintf_buffer+length,"\r\n",2);
	length += 2;
	theApp.huart->send((uint8_t*)btprintf_buffer, length);
}
#endif


struct queue_context {
	uint8_t   *buf;
	uint16_t  head;
	uint16_t  tail;
	uint16_t  size;
	uint16_t  max_size;
};

static struct queue_context _context[CACHE_MAX_NUM];

#define queue_head(context)           (context->head)
#define queue_next(context)           (context->tail)
#define queue_size(context)           (context->size)
#define queue_latter_size(context)    (context->max_size - context->head)
#define queue_latter_rest(context)    (context->max_size - context->tail)

#define queue_expand(context,n) do { \
	context->tail = (context->tail + n) % context->max_size; \
	context->size += n; \
} while (0)

#define queue_shrink(context,n) do { \
	context->head = (context->head + n) % context->max_size; \
	context->size -= n; \
} while (0)


void cache_init(uint8_t cid, uint8_t *buffer, uint16_t size)
{
	struct queue_context *context = &_context[cid];
	context->buf = buffer;
	context->head = 0;
	context->tail = 0;
	context->size = 0;
	context->max_size = size;
}

uint16_t cache_push(uint8_t cid, uint8_t *packet, uint16_t size)
{
	struct queue_context *context = &_context[cid];
	uint16_t num;
    
	size = the_smaller(context->max_size - queue_size(context), size);
	if(size)
	{
		num = the_smaller(size,queue_latter_rest(context));
		memcpy(context->buf + queue_next(context), packet, num);
		memcpy(context->buf, packet + num, size - num);
		queue_expand(context,size);
		return size;
	}
    
	return 0;
}

uint16_t cache_pop(uint8_t cid, uint8_t *packet, uint16_t size, uint8_t preserve)
{
	struct queue_context *context = &_context[cid];
	uint16_t num;

	size = the_smaller(queue_size(context), size);
	if(size)
	{
		num = the_smaller(size,queue_latter_size(context));
		if(packet)
		{
			memcpy(packet, context->buf + queue_head(context), num);
			memcpy(packet + num, context->buf, size - num);
		}
		if(!preserve)
		{
			HOST_ENTER_CRITICAL();
			queue_shrink(context,size);
			HOST_EXIT_CRITICAL();
		}
		return size;
	}

	return 0;
}

uint16_t cache_size(uint8_t cid)
{
	struct queue_context *context = &_context[cid];
	return queue_size(context);
}

