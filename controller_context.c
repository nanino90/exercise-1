#include "controller_context.h"

CONTROLLER_CONTEXT cc;

CONTROLLER_CONTEXT* initialize_controller_context()
{
	cc.status	= READ_EEPROM;
	cc.command 	= 0;
	cc.sensor_value	= 0;
	
	return &cc;
}

CONTROLLER_CONTEXT* get_controller_context()
{
	return &cc;
}
