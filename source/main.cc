#include "cmsis_os.h"                   // ARM::CMSIS:RTOS:Keil RTX
#include "SerialStream_stm32f3.h"
#include "cadc_stm32f3.h"
#include "ctimers_stm32f3.h"
#include  <cmath>

void tarea1(void const * arguments); //tarea 1
osThreadId  tarea1ID;	//identificador del hilo tarea 1
osThreadDef (tarea1,osPriorityNormal,1,0);// macro para definir tareas (aputandor de la funcion, prioridad,?,?)

void tarea2(void const * arguments); //tarea 2
osThreadId  tarea2ID;	//identificador del hilo  tarea 2
osThreadDef (tarea2,osPriorityNormal,1,0);// macro para definir tareas (aputandor de la funcion, prioridad,?,?)

void tarea1Init(void);//funcion que iniciliza la tarea1
void tarea2Init(void);//funcion que iniciliza la tarea1

void adc_timer6_init(void){
	timer6_init(10000, PERIOD_IN_MICROSECONDS);
	adc_injected(ADC_TRIGGER_TIMER6);
}

void adc_timer6_start(void){
	timer6_start();
}

int main(){
	SerialUSART2 serial(9600);
	serial.printf("\nEl dinero es dinero ara ara\n");
	adc_timer6_init();
	//User application
	osKernelInitialize();
	tarea1Init();
	tarea2Init();
	osKernelStart();
	adc_timer6_start();
	while(1){
		serial.printf("adc_ch1 = %u\n",adc_getInjectedChannelValue(ADC_INJECTED_CH1));
		osDelay(200);
	}
}

void tarea1Init(void){
	tarea1ID= osThreadCreate(osThread(tarea1),NULL);
}

void tarea2Init(void){
	tarea2ID= osThreadCreate(osThread(tarea2),NULL);
}

void tarea1(void const * arguments){
	while(1){
		osDelay(100);
	}
}

void tarea2(void const * arguments){
	while(1){
		osDelay(100);
	}
}
