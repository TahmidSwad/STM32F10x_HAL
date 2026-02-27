# STM32F10X\_HAL

##### A Bare-Metal Hardware Abstraction Layer



I am developing this simple HAL to understand register-level peripheral configuration and low-level embedded programming.



This project implements custom HAL drivers by directly manipulating peripheral registers, providing experience with:



* Memory-mapped peripheral access
* STM32 reference manual navigation
* Interrupt configuration and handling
* Hardware initialization sequences
* Communication protocols





##### Features Implemented



1. GPIO Initialization with the specified mode, speed, pull-up/pull-down, and interrupt configuration.
2. GPIO read write and toggle 
3. Delay



###### Hard codded features

1. USART initialization and formatted message sending. 
2. PWM output through Pin B9
3. Sleep/Standby/Stop mode (Have bugs)



This project is currently on hold. I plan to return to it after gaining more experience with vendor-provided HALs to improve the implementation.





