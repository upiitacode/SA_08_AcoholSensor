#include "retarget_stm32f3.h"                  // Device header

int main(){
	//System configuration
	Serial_stream* serial = new SerialUSART2(9600);

	//User application
	serial->printf("Hello World\n");
	while(1){
	}
}
