#include "HAL_GPIO.h"

int main()
{
	GPIO_CLK_INIT(GPIOC);
	
	GPIO_TypeDef_Init type = {0};
	
	type.pin   = 13;
	type.mode  = GPIO_MODE_OUTPUT_PP;
	type.speed  = GPIO_SPEED_HIGH;
	
	GPIO_INIT(GPIOC, &type);
	
	while(1)
	{
		GPIO_WRITE(GPIOC, 13, SET);
		for(int i = 0; i < 100000; i++){}
		GPIO_WRITE(GPIOC, 13, RESET);
		for(int i = 0; i < 100000; i++){}
	}
}