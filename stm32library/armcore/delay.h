/*
 * delay5.h
 *
 *  Created on: 2012/11/15
 *      Author: sin
 */

#ifndef DELAY2_H_
#define DELAY2_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include "stm32f4xx.h"
#include "armcore.h"

extern volatile uint32_t __counter_micros;
extern volatile uint32_t __counter_millis;
extern volatile boolean __clear_millis;
	
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
uint32_t micros(void);
uint32_t millis(void);
void clearMillis(void);
void delay_ms(uint32_t);
void delay_us(uint32_t);
void TIM2_timer_start(void);

void TIM2_IRQHandler(void);

#ifdef __cplusplus
}
#endif


#endif /* DELAY5_H_ */
