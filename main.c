#include <stdio.h>
#include <stdint.h>
#include "functions.h"
#include "ReadEeprom.h"

int main()
{
	uint8_t command = 0;

//Initialize peripherals
	SPIInit();
	TimerInit();

//Task loop
	for( ; ; )
	{

		command =  ReadEeprom();

		RobotTask(command);
	
	}
	return 0;
}
