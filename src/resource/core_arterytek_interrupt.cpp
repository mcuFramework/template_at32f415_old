/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */
#include "core/arterytek/at32f415/Core.h" 
#include "core/arterytek/at32f415/CoreInterrupt.h" 

#include "bsp_arterytek_at32f415/at32f415.h"
#include "bsp_arterytek_at32f415/core_cm4.h"
#include "bsp_arterytek_at32f415/at32f415_exint.h"

/* ****************************************************************************************
 * Using
 */  
using core::arterytek::at32f415::Core;
using core::arterytek::at32f415::CoreInterrupt;

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Extern
 */

/* ****************************************************************************************
 * Struct
 */

/* ****************************************************************************************
 * Static Variable
 */
 
/* ****************************************************************************************
 * Variable
 */

/* ****************************************************************************************
 * List
 */
 
/**
 * Inline function list
 */
 
/**
 * Static function list
 */

/* ****************************************************************************************
 * Inline Function
 */

/* ****************************************************************************************
 * Static Function
 */

/* ****************************************************************************************
 * Function
 */
/* ****************************************************************************************
 * Function - I2C
 */

/**
 *
 */
extern "C" void I2C1_EVT_IRQHandler(void){
  Core::interrupt.mHandle[CoreInterrupt::IRQ_I2C1_EVT]->interruptEvent();
}

/**
 *
 */
extern "C" void I2C1_ERR_IRQHandler(void){
  Core::interrupt.mHandle[CoreInterrupt::IRQ_I2C1_ERR]->interruptEvent();
}
/**
 *
 */
extern "C" void I2C2_EVT_IRQHandler(void){
  Core::interrupt.mHandle[CoreInterrupt::IRQ_I2C2_EVT]->interruptEvent();
}
/**
 *
 */
extern "C" void I2C2_ERR_IRQHandler(void){
  Core::interrupt.mHandle[CoreInterrupt::IRQ_I2C2_ERR]->interruptEvent();
}
 
/* ****************************************************************************************
 * Function - SPI/I2S
 */

/**
 *
 */
extern "C" void SPI1_IRQHandler(void){
  Core::interrupt.mHandle[CoreInterrupt::IRQ_SPI1]->interruptEvent();
}

/**
 *
 */
extern "C" void SPI2_IRQHandler(void){
  Core::interrupt.mHandle[CoreInterrupt::IRQ_SPI2]->interruptEvent();
}

/* ****************************************************************************************
 * Function - USART
 */

/**
 *
 */
extern "C" void USART1_IRQHandler(void){
  Core::interrupt.mHandle[CoreInterrupt::IRQ_USART1]->interruptEvent();
}

/**
 *
 */
extern "C" void USART2_IRQHandler(void){
  Core::interrupt.mHandle[CoreInterrupt::IRQ_USART2]->interruptEvent();
}

/**
 *
 */
extern "C" void USART3_IRQHandler(void){
  Core::interrupt.mHandle[CoreInterrupt::IRQ_USART3]->interruptEvent();
}

/**
 *
 */
extern "C" void UART4_IRQHandler(void){
  Core::interrupt.mHandle[CoreInterrupt::IRQ_UART4]->interruptEvent();
}

/**
 *
 */
extern "C" void UART5_IRQHandler(void){
  Core::interrupt.mHandle[CoreInterrupt::IRQ_UART5]->interruptEvent();
}

/* ****************************************************************************************
 * Function - TMR
 */

/**
 *
 */
extern "C" void TMR1_CH_IRQHandler(void){
  Core::interrupt.mHandle[CoreInterrupt::IRQ_TMR1_CC]->interruptEvent();
}

/**
 *
 */
extern "C" void TMR1_BRK_TMR9_IRQHandler(void){
  if(TMR1->ists_bit.brkif)
    Core::interrupt.mHandle[CoreInterrupt::IRQ_TMR1_BRK]->interruptEvent();
  
  if(TMR9->ists)
    Core::interrupt.mHandle[CoreInterrupt::IRQ_TMR9]->interruptEvent();

}

/**
 *
 */
extern "C" void TMR1_OVF_TMR10_IRQHandler(void){
  if(TMR1->ists_bit.ovfif)
    Core::interrupt.mHandle[CoreInterrupt::IRQ_TMR1]->interruptEvent();
    
  
  if(TMR10->ists)
     Core::interrupt.mHandle[CoreInterrupt::IRQ_TMR10]->interruptEvent();
}

/**
 *
 */
extern "C" void TMR1_TRG_HALL_TMR11_IRQHandler(void){
  if(TMR1->ists_bit.trgif)
    Core::interrupt.mHandle[CoreInterrupt::IRQ_TMR1_TRG_COM]->interruptEvent();
  
  if(TMR11->ists)
    Core::interrupt.mHandle[CoreInterrupt::IRQ_TMR11]->interruptEvent();
}

/**
 *
 */
extern "C" void TMR2_GLOBAL_IRQHandler(void){
  Core::interrupt.mHandle[CoreInterrupt::IRQ_TMR2]->interruptEvent();
}

/**
 *
 */
extern "C" void TMR3_GLOBAL_IRQHandler(void){
  Core::interrupt.mHandle[CoreInterrupt::IRQ_TMR3]->interruptEvent();
}

/**
 *
 */
extern "C" void TMR4_GLOBAL_IRQHandler(void){
  Core::interrupt.mHandle[CoreInterrupt::IRQ_TMR4]->interruptEvent();
}

/**
 *
 */
extern "C" void TMR5_GLOBAL_IRQHandler(void){
  Core::interrupt.mHandle[CoreInterrupt::IRQ_TMR5]->interruptEvent();
}



/* ****************************************************************************************
 * Function - EXINT
 */

/**
 *
 */
extern "C" void EXINT0_IRQHandler(void){
  Core::interrupt.mHandle[CoreInterrupt::IRQ_EXINT0]->interruptEvent();
}

/**
 *
 */
extern "C" void EXINT1_IRQHandler(void){
  Core::interrupt.mHandle[CoreInterrupt::IRQ_EXINT1]->interruptEvent();
}

/**
 *
 */
extern "C" void EXINT2_IRQHandler(void){
  Core::interrupt.mHandle[CoreInterrupt::IRQ_EXINT2]->interruptEvent();
}

/**
 *
 */
extern "C" void EXINT3_IRQHandler(void){
  Core::interrupt.mHandle[CoreInterrupt::IRQ_EXINT3]->interruptEvent();
}

/**
 *
 */
extern "C" void EXINT4_IRQHandler(void){
  Core::interrupt.mHandle[CoreInterrupt::IRQ_EXINT4]->interruptEvent();
}

/**
 *
 */
extern "C" void EXINT9_5_IRQHandler(void){
  for(;;){
		if(EXINT->intsts & 0x00000020)
      Core::interrupt.mHandle[CoreInterrupt::IRQ_EXINT5]->interruptEvent();
		
		else if(EXINT->intsts & 0x00000040)
			Core::interrupt.mHandle[CoreInterrupt::IRQ_EXINT6]->interruptEvent();
		
		else if(EXINT->intsts & 0x00000080)
			Core::interrupt.mHandle[CoreInterrupt::IRQ_EXINT7]->interruptEvent();
		
		else if(EXINT->intsts & 0x00000100)
			Core::interrupt.mHandle[CoreInterrupt::IRQ_EXINT8]->interruptEvent();
		
		else if(EXINT->intsts & 0x00000200)
			Core::interrupt.mHandle[CoreInterrupt::IRQ_EXINT9]->interruptEvent();
		
		else
			break;
	}
}

/**
 *
 */
extern "C" void EXINT15_10_IRQHandler(void){
	for(;;){
		if(EXINT->intsts & 0x00000400)
			Core::interrupt.mHandle[CoreInterrupt::IRQ_EXINT10]->interruptEvent();
		
		else if(EXINT->intsts & 0x00000800)
			Core::interrupt.mHandle[CoreInterrupt::IRQ_EXINT11]->interruptEvent();
		
		else if(EXINT->intsts & 0x00001000)
			Core::interrupt.mHandle[CoreInterrupt::IRQ_EXINT12]->interruptEvent();
		
		else if(EXINT->intsts & 0x00002000)
			Core::interrupt.mHandle[CoreInterrupt::IRQ_EXINT13]->interruptEvent();
		
		else if(EXINT->intsts & 0x00004000)
			Core::interrupt.mHandle[CoreInterrupt::IRQ_EXINT14]->interruptEvent();
		
		else if(EXINT->intsts & 0x00008000)
			Core::interrupt.mHandle[CoreInterrupt::IRQ_EXINT15]->interruptEvent();
		
		else
			break;
	}  
}



/* *****************************************************************************************
 *    End of file
 */
