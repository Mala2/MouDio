
#include <stdint.h>

#include "config.h"
#include "debug.h"
#include "private.h"

#include "module.h"


#define PLAIN_PATTERN				""

static const bt_pattern_t bt_pattern_table[] = 
{
	{ FSC_BT_AT,		PLAIN_PATTERN},
	{ FSC_BT_NAME,		"+NAME"},
	{ FSC_BT_PIN, 		"+PIN"},
	{ FSC_BT_SSP,		"+SSP"},
	{ FSC_BT_PLIST,		"+PLIST"},
	{ FSC_BT_BAUD,		"+BAUD"},
	{ FSC_BT_LPM,		"+LPM"},
	{ FSC_BT_VER,		"+VER"},
	{ FSC_BT_ADDR,		"+ADDR"},
	{ FSC_BT_LENAME,	"+LENAME"},
	{ FSC_BT_LEADDR,	"+LEADDR"},
	{ FSC_BT_FSCPID,	"+FSCPID"},

	{ FSC_BT_COD,		"+COD"},	
	{ FSC_BT_WECHAT,	"+WECHAT"},
	{ FSC_BT_ADVDATA,	"+ADVDATA"},
	{ FSC_BT_FLOWCTL,	"+FLOWCTL"},
	{ FSC_BT_HSM,		"+HSM"},
	{ FSC_BT_BTEN,		"+BTEN"},
#ifdef HAVE_SPP_MASTER
	{ FSC_BT_SPPCONN,	"+SPPCONN",},
	{ FSC_BT_SPPCP,		"+SPPCP"},
#endif
#ifdef HAVE_IBEACON
	{ FSC_BT_IBEACON,	"+IBEACON"},
#endif
	{ FSC_BT_CONNMODE,	"+CONNMODE"},
	{ FSC_BT_MODE,		"+MODE"},
	{ FSC_BT_SECURITY,	"+SECURITY"},
	{ FSC_BT_REBOOT,	"+REBOOT"},
	{ FSC_BT_RESTORE,	"+RESTORE"},
	{ END_OF_COMMANDS,	PLAIN_PATTERN},
	
	{ FSC_RESP_OK,		"OK"},
	{ FSC_RESP_ERROR,	"ERROR"},
	{ END_OF_RESPONSES,	PLAIN_PATTERN},

	{ FSC_TP_INCOMING,	PLAIN_PATTERN},
	{ FSC_TP_OUTGOING,	PLAIN_PATTERN},
	{ END_OF_TP_PATTERNS,	PLAIN_PATTERN},

	{ END_OF_ALL_PATTERNS,	PLAIN_PATTERN},
};

static const module_t bt826_module =
{
	.init_time = 1600,
	.dedicated_at_response_timeout = 150,
	.bt_pattern_table = bt_pattern_table,
};

const module_t* get_module(void)
{
	return &bt826_module;
}


