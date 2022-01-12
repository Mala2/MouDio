
#ifndef _BTAPI_H_
#define _BTAPI_H_

#include <stdint.h>
#include <stdbool.h>
#include "common.h"


#define BT_OK								(0)
#define BT_ERR_UNINITIALIZED				(-1)
#define BT_ERR_BUART_BUSY					(-2)
#define BT_ERR_UNKNOWN_CMD					(-3)
#define BT_ERR_READ_BUSY					(-4)
#define BT_ERR_NOT_TP_STATE					(-5)
#define BT_ERR_NOT_ATCMD_STATE				(-6)


typedef const uint8_t      *ptr;

typedef enum
{
	FSC_BT_AT = 1001,
	FSC_BT_NAME,
	FSC_BT_PIN,
	FSC_BT_SSP,
	FSC_BT_PLIST,
	FSC_BT_BAUD,
	FSC_BT_LPM,
	FSC_BT_VER,
	FSC_BT_ADDR,
	FSC_BT_LENAME,
	FSC_BT_LEADDR,
	FSC_BT_FSCPID,

	FSC_BT_COD,
	FSC_BT_WECHAT,
	FSC_BT_ADVDATA,
	FSC_BT_FLOWCTL,
	FSC_BT_HSM,
	FSC_BT_BTEN,
#ifdef HAVE_SPP_MASTER
	FSC_BT_SPPCONN,
	FSC_BT_SPPCP,
#endif
#ifdef HAVE_IBEACON
	FSC_BT_IBEACON,
#endif
	FSC_BT_CONNMODE,
	FSC_BT_MODE,
	FSC_BT_SECURITY,
	FSC_BT_REBOOT,
	FSC_BT_RESTORE,
	END_OF_COMMANDS, // end of the AT commands

	FSC_RESP_OK = 2001,
	FSC_RESP_ERROR,
	END_OF_RESPONSES, // end of the AT responses

	FSC_TP_INCOMING = 3001,
	FSC_TP_OUTGOING,
	END_OF_TP_PATTERNS, // end of the throughput patterns

	END_OF_ALL_PATTERNS,
} bt_pattern_index_t;

typedef struct
{
	const bt_pattern_index_t	index;
    const char					*pattern;
} bt_pattern_t;

typedef void(*read_response_handler_t)(char *, int);
typedef void(*message_dispatcher_t)(const bt_pattern_t *, uint8_t *, int);

int at_cmd_send(bt_pattern_index_t cmd_idx, const uint8_t *params, uint16_t plen);
int tp_send(const uint8_t *packet, uint16_t size);
void at_engine_register_message_dispatcher(message_dispatcher_t message_dispatcher);
int bt_initialized(void);
void at_engine_run(void);
void at_engine_init(void);


#endif

