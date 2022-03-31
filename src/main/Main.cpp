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
using namespace mcuf::util;
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
TimerTask* t[4];

class Temp extends TimerTask{
  private:
    uint8_t ch;
  
  public:
    Temp(uint8_t numb){
      ch = numb;
    }
  
    void run(void) override{
      board->led[ch].setToggle();
    }
};

/* ****************************************************************************************
 * Method
 */

/**
 *
 */
void setup(start::Entry& entry){  
  board = new(entry.mStacker) BoardPeriph();
  t[0] = new(entry.mStacker) Temp(1);
  t[1] = new(entry.mStacker) Temp(2);
  t[2] = new(entry.mStacker) Temp(3);
  t[3] = new(entry.mStacker) Temp(4);
  Timer::scheduleAtFixedRate(*t[0], 500);
  Timer::scheduleAtFixedRate(*t[1], 250);
  Timer::scheduleAtFixedRate(*t[2], 750);
  Timer::scheduleAtFixedRate(*t[3], 1000);
  //console = new(entry.mStacker) Console();
}

/**
 *
 */
void loop(start::Entry& entry){
  while(board->wakeup.value());
  entry.delay(50);
  while(!board->wakeup.value());
  
  board->led[0].setToggle();
  entry.delay(500);
}


 
/* ****************************************************************************************
 * End of file
 */ 
