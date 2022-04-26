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
Future futureTrc;
ByteBuffer recCache = ByteBuffer(128);
ByteBuffer trcCache = ByteBuffer(128);
CoreSerialBus* coreSerialBus;
TCS3472 *tcs3472;

/* ****************************************************************************************
 * Method
 */

extern "C" void HardFault_Handler(void){
  return;
}

void setup(Thread* _this){
  core_at32f415_interrupt_priority();
  boardPeriph = new BoardPeriph();
  
  /*
  Core::gpioc.setFunction(12, false);
  testSerialPort.init();
  testSerialPort.baudrate(115200);
  eth01 = new WT32ETH01(testSerialPort, boardPeriph->led[1]);
  
  
  eth01->init();
  _this->delay(1000);
  */
  
  Core::gpiob.setFunction(6, true);
  Core::gpiob.setFunction(7, true);
  coreSerialBus = new CoreSerialBus(CoreSerialBusReg::REG_IIC1);
  coreSerialBus->init();
  tcs3472 = new TCS3472(TCS3472::Type::TCS34725, *coreSerialBus);
  tcs3472->enable();
}

void loop(Thread* _this){
  tcs3472->read();
  _this->delay(1000);
  System::out().format("Red:%4d Green:%4d Blue:%4d\n", tcs3472->mRegister.RED, tcs3472->mRegister.GREEN, tcs3472->mRegister.BLUE);
  boardPeriph->led[0].setToggle();
  /*
  
  future.clear();
  if(eth01->listen(WT32ETH01::ConnectType::TCP, 8888, future) == false){
    System::out().print("wait module standby\n");
    _this->delay(1000);
    return;
  }
  
  
  future.waitDone();
  System::out().println(eth01->getIP().toString());
  
  if(future.isFailed()){
    System::out().print("listern fail\n");
    _this->delay(1000);
    return;
  }
  
  System::out().print("listern completed\n");
  
  while(true){
    if(!eth01->isConnect()){
      System::out().print("disconnect\n");
      break;
    }
    
    if(eth01->avariable() != 0){
      System::out().print("receiver:");
      System::out().println(*eth01);
    }
    
    if(System::in().avariable() > 0){
      Future f = Future();
      eth01->write(System::in(), f);
      f.waitDone();
    }
    
    
    boardPeriph->led[0].setToggle();
    _this->delay(1000);
  }
  
  */
}
 
/* ****************************************************************************************
 * End of file
 */ 
