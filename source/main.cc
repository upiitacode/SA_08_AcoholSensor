#include "retarget_stm32f3.h"                  // Device header
#include <stm32f3xx.h>

int main(){
	//System configuration
	Serial_stream* serial = new SerialUSART2(9600);
	SystemCoreClockUpdate();
	//User application
	serial->printf("Hello World\n");
	serial->printf("ProcessorSpeed %d\n",SystemCoreClock);
	while(1){
	}
}
