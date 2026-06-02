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
	}
	// Activar señal de reloj
	// RCC->AHB1ENR |= (1 << 0);
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

	// Limpiando la posicion primero, por posibles valores previos
//	GPIOA->OSPEEDR &= ~(0b11 << GPIO_OSPEEDER_OSPEEDR5_Pos);
//
//	// Configurar pin A5 como salida
//	GPIOA->MODER |= (0b01 << GPIO_MODER_MODE5_Pos);
//
//	// Configurar pin A5 como salida push-pull
//	GPIOA->OTYPER &= ~(GPIO_OTYPER_OT5);
//
//	// Seleccionando la velocidad -- fast
//	GPIOA->OSPEEDR |= ~(0b10 << GPIO_OSPEEDER_OSPEEDR5_Pos);
//
//	// Escribir un 1 en la posicion 5 -> encender el LED2
//	//GPIOA->ODR |= (GPIO_ODR_OD5);
//
//
//	// Configurando el TIM3
//	// Limpiando la posicion TIM3EN
//	RCC->APB1ENR &= ~(RCC_APB1ENR_TIM3EN);
//
//	// Activamos señal de reloj para el TIM3
//	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
//
//	// Para generar una señal de 250ms
//	TIM3->ARR = 249;
//
//	// La señal que incrementa el CNT es de 1KHz
//	TIM3->PSC = 15999;
//
//	// Reiniciamos el CNT (aunque no es necesario)
//	TIM3->CNT = 0;
//
//	// Configuramos para que el TIM3 cuente de fomra ascendente
//	TIM3->CR1 &= ~(TIM_CR1_DIR);
//
//	// Limpiamos la posicion ARPE para tenerla en un estado conocido
//	TIM3->CR1 &= ~(TIM_CR1_ARPE);
//
//	// Activamos el registro de precarga del ARR
//	TIM3->CR1 |= TIM_CR1_ARPE;
//
//	// Activamos la IRQ del TIM3 para que el NVIC reciba señales de ella
//	__NVIC_EnableIRQ(TIM3_IRQn);
//
//	// Bajamos la bandera de la interrupcion del TIM3
//	TIM3->SR &= ~(TIM_SR_UIF);
//
//	//Limpiamos la posicion UIE del registro para garantizar un estado conocido
//	TIM3->DIER &= ~(TIM_DIER_UIE);
//
//	// Activamos la interrupcion de actualizacion del TIM3
//	TIM3->DIER |= TIME_DIER_UIE;
//
//	// Ponemos a 1 en CEN, de forma que el TIM3 comience a contar
//	TIM3->CR1 |= TIM_CR1_CEN;

	/* Loop forever */
	while(1){

	}

	return 0;

}
