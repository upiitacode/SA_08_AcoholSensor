#ifndef _DAC_STM32F3_H
#define _DAC_STM32F3_H

#ifdef __cplusplus
extern "C" {
#endif

void dac_init(void);
void dac_write(float voltaje);

#ifdef __cplusplus
}
#endif

#endif// _DAC_STM32F3_H
