#ifndef _SERIALSTREAM_STM32F4_H
#define _SERIALSTREAM_STM32F4_H

#include "SerialStream.h"

class SerialUSART2: public SerialStream{
	public:
		SerialUSART2(int baudrate);
		virtual char getChar(void);
		virtual void sendChar(char c);
};

class SerialUSART1 : public SerialStream{
	public:
		SerialUSART1(int baudrate);
		virtual char getChar(void);
		virtual void sendChar(char c);
};

#endif
