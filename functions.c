#include "functions.h"
#include "CheckSensor.h"

void RobotTask(uint8_t u8Command)
{
	return;
}

void RobotStop (void)
{
	return;
}

void TimerInit(void)
{
	return;
}

void TimerISR(void)
{
//Disable the CS for the EEPROM to avoid collisions
	SPIEepromDisable();

	if(CheckSensor())
	{
		RobotStop();
//Stay in the interrupt forever
		while(1);
	}
	return;
}

uint32_t TimetGetus(void)
{
	return 0;
}

void SPIInit(void)
{
	return;
}

void SPIEepromEnable(void)
{
	return;
}

void SPIEepromDisable(void)
{
	return;
}

void SPISensorEnable(void)
{
	return;
}

void SPISensorDisable(void)
{
	return;
}

uint8_t SPIRead(void)
{
	return 0;
}


