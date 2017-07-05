#include <stdint.h>
#include "functions.h"


uint8_t ReadEeprom()
{
	uint8_t command=0;

	SPIEepromEnable();

	command = SPIRead();

	SPIEepromDisable();

	return command;
}
