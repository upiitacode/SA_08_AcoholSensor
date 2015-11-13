#include "cmsis_os.h"                   // ARM::CMSIS:RTOS:Keil RTX
#include "SerialStream_stm32f3.h"
#include "dac_stm32f3.h"
#include  <cmath>

void tarea1(void const * arguments); //tarea 1
osThreadId  tarea1ID;	//identificador del hilo tarea 1
osThreadDef (tarea1,osPriorityNormal,1,0);// macro para definir tareas (aputandor de la funcion, prioridad,?,?)

void tarea2(void const * arguments); //tarea 2
osThreadId  tarea2ID;	//identificador del hilo  tarea 2
osThreadDef (tarea2,osPriorityNormal,1,0);// macro para definir tareas (aputandor de la funcion, prioridad,?,?)

void tarea1Init(void);//funcion que iniciliza la tarea1
void tarea2Init(void);//funcion que iniciliza la tarea1

int main(){
	dac_init();
	SerialUSART2 serial(9600);
	serial.printf("\nEl dinero es dinero ara ara\n");
	//User application
	osKernelInitialize();
	tarea1Init();
	tarea2Init();
	osKernelStart();
	while(1){
		osDelay(1000);
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
		for(float time = 0.0; time < 3.1416*2; time += 0.1){
			float volt = (sin(time)+1)*(3.3/2);
			dac_write(volt);
			osDelay(1);
		}
	}
}

void tarea2(void const * arguments){
	while(1){
		osDelay(10);
	}
}
