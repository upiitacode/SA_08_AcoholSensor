#include "stm32f30x.h"                  // Device header

void led_init(void);
void button_init(void);

int main(){
	led_init();
	button_init();
	while(1){
		GPIOB->ODR = GPIOC->IDR;  
	}
	return 0;
}


void led_init(void){
	RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
	GPIOB->MODER &=~(GPIO_MODER_MODER13);
	GPIOB->MODER |=GPIO_MODER_MODER13_0;//output
	GPIOB->ODR |= GPIO_ODR_13;
}

void button_init(void){
	RCC->APB2ENR|= RCC_APB2ENR_SYSCFGEN;
	RCC->AHBENR |= RCC_AHBENR_GPIOCEN;
	
	GPIOC->MODER &=~(GPIO_MODER_MODER13);
	GPIOC->PUPDR |= GPIO_PUPDR_PUPDR13_0;
}


