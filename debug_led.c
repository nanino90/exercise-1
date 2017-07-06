#include <stdint.h>
#include "functions.h"
#include "debug_led.h"
#include "controller_context.h"
#include "defines.h"


void debug_led()
{
	uint32_t time=0;
	static CONTROLLER_CONTEXT* cc = NULL;
	if(cc==NULL)
		cc = get_controller_context();

	time = TimetGetus();
//It is run every second
	if( !(time%1000000) )
	{
		switch(cc->status)
		{
			case READ_EEPROM:
				break;

			case EXECUTE_COMMAND:
				toggle_green_led();
				break;

			case ERROR:
				toggle_red_led();

		break;
			default:
			break;
		}
	}
	return;
}

void toggle_green_led()
{
	return;
}

void toggle_red_led()
{
	return;
}
