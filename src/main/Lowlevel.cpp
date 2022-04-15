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
void lowlevel(void){
  Core::iomux.init();
  Core::gpioa.init();
  Core::gpiob.init();
  Core::gpioc.init();
  Core::gpiod.init();
  Core::gpiof.init();
  Core::iomux.remapSWDIO(CoreIomux::MapSWDIO::JTAGDISABLE);
  
  systemConsole = new Console();
  System::getRegister().setPrintStream(&systemConsole->out());
}  

 
/* ****************************************************************************************
 * End of file
 */ 
