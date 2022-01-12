
#ifndef __DEBUG_
#define __DEBUG_

#include "config.h"
#include <stdio.h>

void dbg_printf(const char* Format, ... );

#define DEBUG_OPEN
#if defined(DEBUG_OPEN) && defined(HAVE_HUART)
#define DEBUG(x) dbg_printf x

#define print_current_function(pos)		dbg_printf("%s @ position:%d",__FUNCTION__,pos)

#else

#define DEBUG(x)
#define print_current_function(pos)

#endif

#endif // __DEBUG_
