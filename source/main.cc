#include "serial_stream_stm32f3.h"
#include "cmsis_os.h"                   // ARM::CMSIS:RTOS:Keil RTX
#include "stm32f30x.h"                  // Device header

void tarea1(void const * arguments); //tarea 1
osThreadId  tarea1ID;	//identificador del hilo tarea 1
osThreadDef (tarea1,osPriorityNormal,1,0);// macro para definir tareas (aputandor de la funcion, prioridad,?,?)

void tarea2(void const * arguments); //tarea 2
osThreadId  tarea2ID;	//identificador del hilo  tarea 2
osThreadDef (tarea2,osPriorityNormal,1,0);// macro para definir tareas (aputandor de la funcion, prioridad,?,?)

void tarea1Init(void);//funcion que iniciliza la tarea1
void tarea2Init(void);//funcion que iniciliza la tarea1

int main(){
	//System configuration
	Serial_stream* serial = new SerialUSART2(9600);
	SystemCoreClockUpdate();
	serial->printf("Starting System\n");
	serial->printf("ProcessorSpeed: %dHz\n",(int)SystemCoreClock);
	//User application
	serial->printf("Initializing kernel...");
	osKernelInitialize();
	serial->printf("done\n");
	serial->printf("Setting threads...");
	tarea1Init();
	tarea2Init();
	serial->printf("done\n");
	serial->printf("starting kernel...");
	osKernelStart();
	serial->printf("done\n");
	serial->printf("System ready, Runnig at thread \"main\"\n");

	int counter = 0;
	while(1){
		osDelay(1000);
		serial->printf("Time elapsed %d[s]\n",counter);
		counter++;
	}
}

void tarea1Init(void){
	tarea1ID= osThreadCreate(osThread(tarea1),NULL);
}

void tarea2Init(void){
	tarea2ID= osThreadCreate(osThread(tarea2),NULL);
}

void led_init(void){
	//Turn on the GPIOB peripherial
	RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
	//Configure PB13  as push pull ouput an set the output to high
	GPIOB->MODER &=~(GPIO_MODER_MODER13);
	GPIOB->MODER |=GPIO_MODER_MODER13_0;//output
	GPIOB->ODR |= GPIO_ODR_13;
}

void tarea1(void const * arguments){
	led_init();
	while(1){
		GPIO_WriteBit(GPIOB,GPIO_Pin_13,Bit_SET);
		osDelay(500);
		GPIO_WriteBit(GPIOB,GPIO_Pin_13,Bit_RESET);
		osDelay(500);
	}
}

void tarea2(void const * arguments){
	while(1){
		osDelay(10);
	}
}
