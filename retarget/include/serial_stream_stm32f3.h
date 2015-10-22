#ifndef _SERIAL_STREAM_STM32F3_H
#define _SERIAL_STREAM_STM32F3_H

#include "serial_stream.h"

class SerialUSART2: public Serial_stream{
	public:
		SerialUSART2(int baudrate);
		virtual char getChar(void);
		virtual void sendChar(char c);
};

class SerialUSART1 : public Serial_stream{
	public:
		SerialUSART1(int baudrate);
		virtual char getChar(void);
		virtual void sendChar(char c);
};

#endif
