#ifndef PLATFORM
#define PLATFORM
#include <stdint.h>
#include "Motor.h"

typedef struct Platform
{
    Motor * motor_front;
    Motor * motor_back;
} Platform;


int InitPlatform(Platform * p, uint8_t addr_front, uint8_t addr_back);
int MovingAhead(Platform * p, int speed);
int StopPlatform(Platform * p);
int Rotation(Platform * p, uint8_t orientation, int speed);

#endif	
