#ifndef HAL_GPIO
#define HAL_GPIO

#include "stm32f10x.h"
#include "stdint.h"

typedef struct
{
	
	uint32_t   pin;
	
	uint32_t   mode;
	
	uint32_t   pull;
	
	uint32_t   speed;
	
}GPIO_TypeDef_Init;
	
#define   GPIO_MODE_INPUT_FLOATING   ((uint32_t) 0b0100)
#define   GPIO_MODE_INPUT_PUPD       ((uint32_t) 0b1000)
#define   GPIO_MODE_OUTPUT_PP        ((uint32_t) 0b0011)
#define   GPIO_MODE_OUTPUT_OD        ((uint32_t) 0b0111)

#define   GPIO_SPEED_LOW             ((uint32_t) 0b1110)
#define   GPIO_SPEED_MEDIUM          ((uint32_t) 0b1101)
#define   GPIO_SPEED_HIGH            ((uint32_t) 0b1111)

#define   GPIO_PULLUP                ((uint32_t) 0b1)
#define   GPIO_PULLDOWN              ((uint32_t) 0b1 << 16)

void GPIO_CLK_INIT(GPIO_TypeDef *port);
void GPIO_INIT(GPIO_TypeDef *port, GPIO_TypeDef_Init *type);
void GPIO_WRITE(GPIO_TypeDef *port, uint32_t pin, uint32_t pinState);
void GPIO_TOGGLE(GPIO_TypeDef *port, uint32_t pin);
uint32_t GPIO_READ(GPIO_TypeDef *port, uint32_t pin);

#endif
