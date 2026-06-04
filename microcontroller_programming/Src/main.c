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

/*#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

/* Variables del sistema */
//uint8_t dummy_8bit = 0;
//uint16_t dummy_16bit = 0;
//uint32_t dummy_32bit = 0;
//uint8_t overflow = 0;
//
//uint16_t dummy_16bit_dec = 0;
//uint16_t dummy_16bit_bin = 0;
//uint16_t dummy_16bit_hex = 0;


//int main(void)
//{

//	dummy_8bit = 123;
//	dummy_16bit = 4986;
//	dummy_32bit = 12345678;

//	dummy_16bit_dec = 32;
//	dummy_16bit_bin = 0b100000;
//	dummy_16bit_hex = 0x20;

	/* Cargando el valor en xxxx de la variable yyy */
//	dummy_16bit_bin = dummy_16bit_bin << 3; // prediccion: 0b100000000 = 256
//	dummy_16bit_bin = dummy_16bit_bin >> 3; // prediccion 0b100 = 4 ---------- Mala prediccion

	/*Caso de overflow*/
//	dummy_8bit = 255;
//	dummy_16bit = 255;
//	dummy_32bit = 255;

	/* Incremento el valor de la variable dummy_8bit en 1 y lo cargo en la variable overflow*/
//	overflow = dummy_8bit + 1;
//	overflow = overflow +1;
//	overflow = 735;
//	overflow = 0;

//	for(uint16_t counter = 0; counter < 735; counter++){
//		overflow++;
//	}
	// Activar señal de reloj
	// RCC->AHB1ENR |= (1 << 0);
//	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

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





//Definicion de variables
volatile led_ok = 0;
volatile cambio = 0;
volatile uint8_t aumentar_counter = 0;
uint8_t counter = 0;
uint8_t color = 0; // 0 verde, 1 amarillo y 2 rojo



//Cabeceras de funciones
void init_GPIO(void);
void init_exti(void);


int main(void){
	init_GPIO();
	init_exti();



	while(1){
		if (aumentar_counter){
			counter = counter + 10;
			aumentar_counter = 0;
		}



		if(led_ok){
			led_ok = 0;
			GPIOA->ODR ^= GPIO_ODR_OD5;
		}

		if(cambio){
			cambio = 0;

			switch(color){
			case(0): //Verde
					GPIOA->ODR |= GPIO_ODR_OD8;
			GPIOA->ODR &= ~(GPIO_ODR_OD7);
			GPIOA->ODR &= ~(GPIO_ODR_OD6);
			color ++;
			TIM3->ARR = 1000;  //1s
			break;

			case(1):

					GPIOA->ODR &= ~GPIO_ODR_OD8;
			GPIOA->ODR |= (GPIO_ODR_OD7);
			GPIOA->ODR &= ~(GPIO_ODR_OD6);
			color++;

			break;

			case(2):
				GPIOA->ODR &= ~GPIO_ODR_OD8;
			GPIOA->ODR &= ~(GPIO_ODR_OD7);
			GPIOA->ODR |= (GPIO_ODR_OD6);
			color = 0;
			TIM3->ARR = 4000;  //4s
			break;


			}

		}


	}

	return 0;
}



//Funciones
void init_GPIO(void){
	/*
	 * Señal de reloj
	 */
	RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOAEN; // Limpiando el registro
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;  // Encendiendo el Bus

	/*
	 * PA5 -> PA8
	 */

	GPIOA->MODER &= ~ (GPIO_MODER_MODE5 | GPIO_MODER_MODE6 | GPIO_MODER_MODE7 | GPIO_MODER_MODE8); //limpiando completamente el registro de modo de GPIO
	GPIOA->MODER |= (GPIO_MODER_MODE5_0 | GPIO_MODER_MODE6_0 | GPIO_MODER_MODE7_0 | GPIO_MODER_MODE8_0);  //Configurando modo output

	GPIOA->OTYPER &= ~(GPIO_OTYPER_OT5 | GPIO_OTYPER_OT6| GPIO_OTYPER_OT7 | GPIO_OTYPER_OT8); // Configurando el modo salida - push-pull (0)

	GPIOA->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR5 | GPIO_OSPEEDER_OSPEEDR6 | GPIO_OSPEEDER_OSPEEDR7 | GPIO_OSPEEDER_OSPEEDR8); //Limpiando el registro de velocidad
	GPIOA->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR5_1 | GPIO_OSPEEDER_OSPEEDR6_1 | GPIO_OSPEEDER_OSPEEDR7_1 | GPIO_OSPEEDER_OSPEEDR8_1); // Poniendo 10 (fast)

	GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPD5 | GPIO_PUPDR_PUPD6 | GPIO_PUPDR_PUPD7 | GPIO_PUPDR_PUPD8); // limpiando posiciones del registro Port Up- Pull Down. Como se quiere poner 00, pues ya queda

	GPIOA->ODR |= (GPIO_ODR_OD5 | GPIO_ODR_OD6 | GPIO_ODR_OD7 | GPIO_ODR_OD8); //Encendiendo pines

	/*
	 * TIM2
	 */

	RCC->APB1ENR &= ~(RCC_APB1ENR_TIM2EN); //Limpiando el Bus del TIM2
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN; //Encendiendo el Bus del TIM2

	TIM2->PSC = 16000-1; //Divisor de frecuencia
	TIM2->ARR = 4000-1; // Cuantas veces quiero que cuente /4s		//1000-1; //1s

	TIM2->CNT = 0; //Contador en 0 (inicio)

	TIM2->DIER &= ~(TIM_DIER_UIE); // Update interrupt enable- limpio
	TIM2->DIER |= TIM_DIER_UIE; // pongo 1 para activarlo

	__NVIC_EnableIRQ(TIM2_IRQn); // Matriculando la interrupcion en el NVIC

	TIM2->CR1 &= ~(TIM_CR1_DIR); // Direccion hacia arriba

	TIM2->CR1 &= ~(TIM_CR1_ARPE); // limpio el buffer
	TIM2->CR1 |= TIM_CR1_ARPE; // Activo buffer

	TIM2->CR1 |= TIM_CR1_CEN; // Activar el timmer


/*
	 * TIM3
	 */

	RCC->APB1ENR &= ~(RCC_APB1ENR_TIM3EN); //Limpiando Bus TIM3
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN; //Encendiendo Bus TIM3

	TIM3->PSC = 16000-1;
	TIM3->ARR = 4000-1; //4s		//1000-1; //1s

	TIM3->CNT = 0; //Contador en 0 (inicio)

	TIM3->DIER &= ~(TIM_DIER_UIE);
	TIM3->DIER |= TIM_DIER_UIE;

	__NVIC_EnableIRQ(TIM3_IRQn);

	TIM3->CR1 &= ~(TIM_CR1_DIR);

	TIM3->CR1 &= ~(TIM_CR1_ARPE);
	TIM3->CR1 |= TIM_CR1_ARPE;

	TIM3->CR1 |= TIM_CR1_CEN;
}


//Configurando el EXTI
void init_exti(void){
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;  //Encendiendo señal de reloj para el EXTI

	SYSCFG->EXTICR[0] &= ~(SYSCFG_EXTICR1_EXTI1); //Configurando canal EXTI
	SYSCFG->EXTICR[0] |= (SYSCFG_EXTICR1_EXTI1_PC); //Configurando el canal 1 del EXTI para el puerto C (pin C1)
	EXTI->RTSR |= EXTI_RTSR_TR1; //Seleccionando flanco de subida para ser detectado por pin C1
	NVIC_EnableIRQ(EXTI1_IRQn); //Matriculando la interrupcion del EXTI en el NVIC (para que sea atendida)
	EXTI->PR |= EXTI_PR_PR1; //Bajando la bandera de la interrupcion
	EXTI->IMR |= EXTI_IMR_IM1; //Activando la interrupcion

}

//ISR para el EXTI con flanco de subida
void EXTI1_IRQHandler(void){
	if (EXTI->PR && EXTI_PR_PR1){ //Verificando que se dio la interrupcion en C1
		EXTI->PR |= EXTI_PR_PR1; //Bajamos la bandera de la interrupcion
		aumentar_counter = 1;
	}
}




void TIM2_IRQHandler(void){
	if (TIM2->SR & TIM_SR_UIF){ // Pregunto si hay algo pendiente
		TIM2->SR &= ~ TIM_SR_UIF; // Bajo la bandera, por que la estoy atendiendo
		led_ok = 1;
	}


}

void TIM3_IRQHandler(void){
	if (TIM3->SR & TIM_SR_UIF){
		TIM3->SR &= ~ TIM_SR_UIF;
		cambio  = 1;
	}


}

