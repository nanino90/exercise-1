#include <stdio.h>
#include <stdint.h>
#include "functions.h"
#include "ReadEeprom.h"
#include "controller_context.h"
#include "debug_led.h"

int main()
{
	CONTROLLER_CONTEXT* cc;

	cc = initialize_controller_context();

//Initialize peripherals
	SPIInit();
	TimerInit();

//Task loop
	for( ; ; )
	{
		switch(cc->status)
		{
			case READ_EEPROM:
			cc->command = ReadEeprom();
			cc->status = EXECUTE_COMMAND;
				break;

			case EXECUTE_COMMAND:
			RobotTask(cc->command);
			//This if is to ensure the interrupt function hasn't triggered the ERROR state
			if( cc->status == EXECUTE_COMMAND)
				cc->status =READ_EEPROM;
				break;

			case ERROR:
			default:
				break;
		}
		debug_led();
	}
	return 0;
}
