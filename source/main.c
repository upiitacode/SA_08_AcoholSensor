#include "stm32f30x.h"                  // Device header

void led_init(void);

int main(){
	led_init();
	return 0;
}

void led_init(void){
	RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
	GPIOB->MODER &=~(GPIO_MODER_MODER13);
	GPIOB->MODER |=GPIO_MODER_MODER13_0;//output
	GPIOB->ODR |= GPIO_ODR_13;
}


