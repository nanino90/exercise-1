#include <stdio.h>
#include <stdint.h>
#include "functions.h"

int main()
{
	uint8_t command = 0;

//Initialize peripherals
	SPIInit();
	TimerInit();

//Task loop
	for( ; ; )
	{

		SPIEepromEnable();

		command = SPIRead();

		SPIEepromDisable();

		RobotTask(command);
	
	}
	return 0;
}
