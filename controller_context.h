#ifndef _CONTROLLER_CONTEXT_
#define _CONTROLLER_CONTEXT_

#include <stdint.h>

typedef enum
{
	IDLE,
	READ_EEPROM,
	EXECUTE_COMMAND,
	ERROR,

	STATUS_SIZE
}STATUS;

typedef struct _CONTROLLER_CONTEXT
{
	STATUS status;
	uint8_t command;
	uint8_t sensor_value;

} CONTROLLER_CONTEXT;

CONTROLLER_CONTEXT* initialize_controller_context();

CONTROLLER_CONTEXT* get_controller_context();


#endif
