#include "functions.h"
#include "CheckSensor.h"
#include "controller_context.h"

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
	static CONTROLLER_CONTEXT* cc = NULL;
	if(cc==NULL)
		cc = get_controller_context();

	//Disable the CS for the EEPROM to avoid possible collisions with EEPROM
	SPIEepromDisable();

	if(CheckSensor())
	{
		RobotStop();
		cc->status = ERROR;
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


