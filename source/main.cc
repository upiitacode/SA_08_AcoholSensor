#include "cmsis_os.h"                   // ARM::CMSIS:RTOS:Keil RTX
#include "SerialStream_stm32f3.h"
#include "cadc_stm32f3.h"
#include "ctimers_stm32f3.h"
#include  <cmath>

void adc_timer6_init(void){
	timer6_init(1000, PERIOD_IN_MICROSECONDS);
	adc_injected(ADC_TRIGGER_TIMER6);
}

void adc_timer6_start(void){
	timer6_start();
}

#define SAMPLES_PER_READING 100

float get_stable_reading(void){
	float accu = 0;
	for(int i = 0; i < SAMPLES_PER_READING; i++){
		accu += adc_getInjectedChannelValue(ADC_INJECTED_CH1);
		osDelay(1);
	}
	return accu/SAMPLES_PER_READING;
}

SerialStream* serial;

int main(){
	//Initialized kernel
	osKernelInitialize();
	//Hardware initialization
	serial = new SerialUSART2(9600);
	adc_timer6_init();
	//Start thread switching
	osKernelStart();
	//User application
	adc_timer6_start();

	while(1){
		serial->printf("ADC = %f\n", get_stable_reading());
	}
}
