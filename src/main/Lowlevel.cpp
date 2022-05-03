/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf.h"
#include "driver.h"
#include "core_arterytek_at32f415.h"
//-----------------------------------------------------------------------------------------
#include "tool\package-info.h"

/* ****************************************************************************************
 * Using
 */  
 
//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using arterytek::at32f415::Core;
using arterytek::at32f415::CoreIomux;

using tool::Console;

using mcuf::lang::System;
using mcuf::lang::ErrorCode;

/* ****************************************************************************************
 * Extern
 */
 
/* ****************************************************************************************
 * Variable
 */
static Console* systemConsole;
//UART4_TX    - PC10 / PF4
//UART4_RX    - PC11 / PF5

/* ****************************************************************************************
 * Method
 */

/**
 *
 */
bool errorCodeHandler(const void* address, ErrorCode code){
  System::out().print("System Error:");
  
  switch(code){
    case ErrorCode::NONE:
      System::out().format("NONE\n");
      break;
    
    case ErrorCode::HARD_FAULT:
      System::out().format("HARD_FAULT\n");
      break;
    
    case ErrorCode::SYSTEM_ERROR:
      System::out().format("SYSTEM_ERROR\n");
      break;
    
    case ErrorCode::OUT_OF_MEMORY:
      System::out().format("OUT_OF_MEMORY\n");
      break;
    
    case ErrorCode::OUT_OF_THREAD_STACK_MEMORY:
      System::out().format("OUT_OF_THREAD_STACK_MEMORY\n");
      break;
    
    case ErrorCode::NULL_POINTER:
      System::out().format("NULL_POINTER\n");
      break;
    
    case ErrorCode::ILLEGAL_ARGUMENT:
      System::out().format("ILLEGAL_ARGUMENT\n");
      break;
    
    case ErrorCode::INSUFFICIENT_MEMORY:
      System::out().format("INSUFFICIENT_MEMORY\n");
      break;
    
    case ErrorCode::WRITE_TO_READONLY_MEMORY:
      System::out().format("WRITE_TO_READONLY_MEMORY\n");
      break;
    
    case ErrorCode::MEMORY_NOT_ALIGNMENT_32BIT:
      System::out().format("MEMORY_NOT_ALIGNMENT_32BIT\n");
      break;
    
    case ErrorCode::MEMORY_NOT_ALIGNMENT_64BIT:
      System::out().format("MEMORY_NOT_ALIGNMENT_64BIT\n");
      break;
    
    case ErrorCode::RTX_STACK_UNDERFLOW:
      System::out().format("RTX_STACK_UNDERFLOW\n");
      break;
    
    case ErrorCode::RTX_ISR_QUEUE_OVERFLOW:
      System::out().format("RTX_ISR_QUEUE_OVERFLOW\n");
      break;
    
    case ErrorCode::RTX_TIMER_QUEUE_OVERFLOW:
      System::out().format("RTX_TIMER_QUEUE_OVERFLOW\n");
      break;
    
    case ErrorCode::RTX_CLIB_SPACE:
      System::out().format("RTX_CLIB_SPACE\n");
      break;
    
    case ErrorCode::RTX_CLIB_MUTEX:
      System::out().format("RTX_CLIB_MUTEX\n");
      break;
  
    case ErrorCode::RESERVED:
      System::out().format("RESERVED\n");
      break;
  }
  
  return true;
}

/**
 *
 */
void lowlevel(void){
  arterytek::at32f415::Core::setSystemCoreClock(144);
  System::initialize();
  
  Core::iomux.init();
  Core::gpioa.init();
  Core::gpiob.init();
  Core::gpioc.init();
  Core::gpiod.init();
  Core::gpiof.init();
  Core::iomux.remapSWDIO(CoreIomux::MapSWDIO::JTAGDISABLE);
  
  systemConsole = new Console();
  System::getRegister().setPrintStream(&systemConsole->out());
  System::getRegister().setInputStreamBuffer(&systemConsole->in());
  System::getRegister().setErrorCodeHandler(errorCodeHandler);
}  

 
/* ****************************************************************************************
 * End of file
 */ 
