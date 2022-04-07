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
using arterytek::at32f415::Core;
using arterytek::at32f415::CoreIomux;
using arterytek::at32f415::general::CoreGeneralPin;
using arterytek::at32f415::serial::CoreSerialBus;
using arterytek::at32f415::serial::CoreSerialBusReg;

using hal::general::GeneralPin;
using tool::BoardPeriph;
using tool::Console;

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
  board = new BoardPeriph();
  t[0] = new Temp(1);
  t[1] = new Temp(2);
  t[2] = new Temp(3);
  t[3] = new Temp(4);
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
