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
#include "start\Entry.h"
#include "tool\package-info.h"

/* ****************************************************************************************
 * Using
 */  
 
//-----------------------------------------------------------------------------------------
using namespace mcuf::lang;
using namespace mcuf::io;
 
//-----------------------------------------------------------------------------------------
using core::arterytek::at32f415::Core;
using core::arterytek::at32f415::CoreIomux;
using core::arterytek::at32f415::general::pin::CoreGeneralPin;
using core::arterytek::at32f415::serial::bus::CoreSerialBus;
using core::arterytek::at32f415::serial::bus::CoreSerialBusReg;

using mcuf::hal::general::pin::GeneralPin;
using tool::BoardPeriph;
using tool::Console;
using driver::ams::TCS3472;

/* ****************************************************************************************
 * Extern
 */
 
 
/* ****************************************************************************************
 * Variable
 */
BoardPeriph* board;
Console* console;

/* ****************************************************************************************
 * Method
 */

/**
 *
 */
void setup(start::Entry& entry){  
  board = new(entry.mStacker) BoardPeriph();
  console = new(entry.mStacker) Console();
}

/**
 *
 */
void loop(start::Entry& entry){
  while(board->wakeup.value());
  entry.delay(50);
  while(!board->wakeup.value());
  
  console->out().println("hello");
  board->led[0].setToggle();
  entry.delay(500);
}


 
/* ****************************************************************************************
 * End of file
 */ 
