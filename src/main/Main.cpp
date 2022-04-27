/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  
#include <stdio.h>

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
using namespace mcuf::io;
using namespace mcuf::lang;
using namespace mcuf::function;
using namespace arterytek::at32f415::serial;

//-----------------------------------------------------------------------------------------
using mcuf::lang::Thread;
using mcuf::lang::System;
using mcuf::lang::String;
using mcuf::lang::Memory;

using tool::BoardPeriph;
using arterytek::at32f415::Core;
using driver::wirelesstag::WT32ETH01;
using driver::ams::TCS3472;
using mcuf::net::InternetProtocolAddress;


/* ****************************************************************************************
 * Extern
 */
extern void lowlevel(void);
extern "C" void core_at32f415_interrupt_priority(void);

 
/* ****************************************************************************************
 * Variable
 */
BoardPeriph* boardPeriph;


/* ****************************************************************************************
 * Method
 */

extern "C" void HardFault_Handler(void){
  return;
}

void setup(Thread* _this){
  core_at32f415_interrupt_priority();
  boardPeriph = new BoardPeriph();
}

void loop(Thread* _this){
  _this->delay(1000);
  boardPeriph->led[1].setToggle();
}
 
/* ****************************************************************************************
 * End of file
 */ 
