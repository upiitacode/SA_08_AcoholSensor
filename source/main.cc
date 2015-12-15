#include "cmsis_os.h"                   // ARM::CMSIS:RTOS:Keil RTX
#include "SerialStream_stm32f3.h"
#include "cadc_stm32f3.h"
#include "ctimers_stm32f3.h"
#include  <cmath>
#include "Interpolator.h"

#define SIZE_OF_ARRAY(arr) (sizeof(arr)/size(float))

const float achohol_concentration[] = {0.10181, 0.21787, 0.40569, 1.03672, 1.65255, 2.54795, 4.06116, 6.12486, 7.99489, 9.98280};//mg/L
const float relative_resistance[] = {2.26758, 1.51289, 0.99011, 0.53957, 0.38884, 0.28843, 0.20194, 0.15871, 0.13216, 0.11437};//Rs/Ro
const float rh85_temp[] = {-9.85609, -4.85097, 0.11267, 5.11970, 11.58757, 20.10110, 30.16157, 40.13888, 50.15904};//C
const float rh85_factor[] = {1.36426, 1.24955, 1.14073, 1.06733, 0.98224, 0.89139, 0.84492, 0.80582, 0.79033};//Rs/Ro
const float rh33_temp[] = {-9.887231, -4.924621, 0.080701, 5.085886, 11.427193, 20.064684, 30.123995, 40.101236, 50.162874};//C
const float rh33_factor[] = {1.59295, 1.46200, 1.35172, 1.23848, 1.12534, 1.00647, 0.93492, 0.89434, 0.87295};//Rs/Ro


void adc_timer6_init(void){
	timer6_init(500, PERIOD_IN_MICROSECONDS);
	adc_injected(ADC_TRIGGER_TIMER6);
}

void adc_timer6_start(void){
	timer6_start();
}

#define SAMPLES_PER_READING 100

float get_stable_reading(int channel){
	float accu = 0;
	for(int i = 0; i < SAMPLES_PER_READING; i++){
		accu += adc_getInjectedChannelValue(channel);
		osDelay(1);
	}
	return (accu)*(3.3/(4095.0*(SAMPLES_PER_READING)))*(1.008471);
}

float get_resistance(void){
	float current = get_stable_reading(0)/1000000.0;
	float voltage = 2.5;
	float resistance = voltage/current;
	return resistance;
}

float get_temperature(void){
	return get_stable_reading(1)*(100.0);
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
		serial->printf("Rs = %10.1f, T = %5.1f\n",get_resistance(), get_temperature());
	}
}
