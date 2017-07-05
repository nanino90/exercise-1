#include <stdio.h>
#include <stdint.h>
#include "functions.h"
#include "ReadEeprom.h"
#include "controller_context.h"

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
			cc->status =READ_EEPROM;
			RobotTask(cc->command);
				break;

			case ERROR:
			default:
				printf("ERRORR");
				return;
				break;
		}
	TimerISR();
	}
	return 0;
}
