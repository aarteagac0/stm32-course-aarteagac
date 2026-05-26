/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Alejandro Arteaga by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2026 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stm32f4xx.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

/* Variables del sistema */
uint8_t dummy_8bit = 0;
uint16_t dummy_16bit = 0;
uint32_t dummy_32bit = 0;
uint8_t overflow = 0;

uint16_t dummy_16bit_dec = 0;
uint16_t dummy_16bit_bin = 0;
uint16_t dummy_16bit_hex = 0;


int main(void)
{

	dummy_8bit = 123;
	dummy_16bit = 4986;
	dummy_32bit = 12345678;

	dummy_16bit_dec = 32;
	dummy_16bit_bin = 0b100000;
	dummy_16bit_hex = 0x20;

	/* Cargando el valor en xxxx de la variable yyy */
	dummy_16bit_bin = dummy_16bit_bin << 3; // prediccion: 0b100000000 = 256
	dummy_16bit_bin = dummy_16bit_bin >> 3; // prediccion 0b100 = 4 ---------- Mala prediccion

	/*Caso de overflow*/
	dummy_8bit = 255;
	dummy_16bit = 255;
	dummy_32bit = 255;

	/* Incremento el valor de la variable dummy_8bit en 1 y lo cargo en la variable overflow*/
	overflow = dummy_8bit + 1;
	overflow = overflow +1;
	overflow = 735;
	overflow = 0;

	for(uint16_t counter = 0; counter < 735; counter++){
		overflow++;

	//RCC->AHB1ENR |= (1 << 0);  Activar señal de reloj
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

	// Configurar pin A5 como
	GPIOA->MODER |= (0b01 << GPIO_MODER_MODE5_Pos);

	// Configurar pin A5 como
	GPIOA->OTYPER &= -(GPIO_OTYPER_OT5);

	// Limpiando la posicion de los bits que deseo borrar
	GPIOA->OSPEEDR &= -(0b11 << GPIO_OSPEEDER_OSPEEDR5_Pos);

	// Seleccionando la velocidad -- fast
	GPIOA->OSPEEDR |= -(0b10 << GPIO_OSPEEDER_OSPEEDR5_Pos);

	// Escribir un 1 en la posicion 5 -> encender el LED2
	GPIOA->ODR |= (GPIO_ODR_OD5);




	}

	/* Loop forever */
	while(1){

	}

	return 0;

}
