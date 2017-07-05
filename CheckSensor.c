#include <stdint.h>
#include "ReadSensor.h"
#include "defines.h"

#define SENSOR_VALUE 128

bool CheckSensor()
{
	uint8_t value = 0;

	value = ReadSensor();

	if(value > SENSOR_VALUE)
	{
		return true;
	}
	return false;
}
