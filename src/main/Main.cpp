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
uint8_t recBuf[256];
BoardPeriph* boardPeriph;
CoreSerialPort testSerialPort = CoreSerialPort(CoreSerialPortReg::REG_UART5, Memory(recBuf, sizeof(recBuf)));
WT32ETH01* eth01;
Future future;


/* ****************************************************************************************
 * Method
 */

extern "C" void HardFault_Handler(void){
  while(true){
  }
}

void clearAllLed(void){
  for(int i=0; i<7; ++i){
    boardPeriph->led[i].setLow();
  }
}

void setup(Thread* _this){
  core_at32f415_interrupt_priority();
  boardPeriph = new BoardPeriph();
  Core::gpioc.setFunction(12, false);
  testSerialPort.init();
  testSerialPort.baudrate(115200);
  eth01 = new WT32ETH01(testSerialPort, boardPeriph->led[7]);
  /*
  eth01->setStaticIPAddress(InternetProtocolAddress("192.168.0.229"), 
                            InternetProtocolAddress("192.168.0.1"), 
                            InternetProtocolAddress("255.255.0.0"));
  */
  eth01->init();
  _this->delay(1000);
}

void loop(Thread* _this){
  clearAllLed();
  boardPeriph->led[0].setHigh();
  future.clear();
  if(eth01->listen(WT32ETH01::ConnectType::TCP, 8888, future) == false){
    boardPeriph->led[2].setHigh();
    _this->delay(1000);
    return;
  }
  future.waitDone();
  
  if(future.isFailed()){
    boardPeriph->led[1].setHigh();
    _this->delay(1000);
    return;
  }
  
  boardPeriph->led[3].setHigh();
  
  while(true){
    if(!eth01->isConnect()){
      break;
      
    }else if(eth01->avariable() != 0){
      boardPeriph->led[5].setToggle();
      System::out().print(*eth01);
      
    }else if(System::in().avariable() != 0){
      boardPeriph->led[4].setToggle();
      future.clear();
      eth01->write(System::in(), future);
      future.waitDone();
      
    }else{
      boardPeriph->led[6].setToggle();
      _this->delay(1000);
    }
  }
}
 
/* ****************************************************************************************
 * End of file
 */ 
