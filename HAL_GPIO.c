#include "HAL_GPIO.h"

void GPIO_CLK_INIT(GPIO_TypeDef *port)
{
	if(port == GPIOA)
	{
		RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	}
	else if(port == GPIOB)
	{
		RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
	}
	else if(port == GPIOC)
	{
		RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	}
}

void GPIO_INIT(GPIO_TypeDef *port, GPIO_TypeDef_Init *type)
{
	volatile uint32_t config = 0b0000;
	switch(type->mode)
	{
		case GPIO_MODE_INPUT_FLOATING:
		{
			config = GPIO_MODE_INPUT_FLOATING;
			break;
		}
		case GPIO_MODE_INPUT_PUPD:
		{
			config = GPIO_MODE_INPUT_PUPD;
			port->BSRR = (type->pull << type->pin);
			break;
		}
		case GPIO_MODE_OUTPUT_PP:
		{
			config = GPIO_MODE_OUTPUT_PP;
			config &= type->speed;
			break;
		}
		case GPIO_MODE_OUTPUT_OD:
		{
			config = GPIO_MODE_OUTPUT_OD;
			config &= type->speed;
			break;
		}
	}
	if(type->pin < 8)
	{
		port->CRL &= ~(0b1111 << (type->pin * 4));
		port->CRL |= (config << (type->pin * 4));
	}
	else
	{
		port->CRH &= ~(0b1111 << ((type->pin - 8) * 4));
		port->CRH |= (config << ((type->pin - 8) * 4));
	}
}

void GPIO_WRITE(GPIO_TypeDef *port, uint32_t pin, uint32_t pinState)
{
	if(pinState == SET)
	{
		port->BSRR = 1 << pin;
	}
	else
	{
		port->BSRR = 1 << (pin + 16);
	}
}

void GPIO_TOGGLE(GPIO_TypeDef *port, uint32_t pin)
{
	port->ODR ^= 1 << pin;
}

uint32_t GPIO_READ(GPIO_TypeDef *port, uint32_t pin)
{
	return port->IDR & (1 << pin);
}
