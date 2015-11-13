#include "dac_stm32f3.h"
#include "stm32f30x.h"                  // Device header

void dac_init(void){
	RCC_APB1PeriphClockCmd(RCC_APB1ENR_DACEN, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1ENR_DACEN, ENABLE);
	DAC_InitTypeDef myDAC;
	DAC_StructInit(&myDAC);
	myDAC.DAC_Buffer_Switch = DAC_BufferSwitch_Enable;
	myDAC.DAC_Trigger = DAC_Trigger_None;
	DAC_Init(DAC,DAC_Channel_1,&myDAC);
	DAC_Cmd(DAC,DAC_Channel_1,ENABLE);
}

void dac_write(float outVoltaje){
	int outVal = (int) (outVoltaje*(4095.0/3.3));
	DAC_SetChannel1Data(DAC, DAC_Align_12b_R,outVal);
}
