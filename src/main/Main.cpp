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

//-----------------------------------------------------------------------------------------
using mcuf::lang::Thread;
using mcuf::lang::System;
using mcuf::lang::String;
using mcuf::lang::Memory;
using mcuf::io::ByteBuffer;
using tool::BoardPeriph;
using arterytek::at32f415::Core;
using arterytek::at32f415::serial::CoreSerialPort;
using arterytek::at32f415::serial::CoreSerialPortReg;
using driver::wirelesstag::WT32ETH01;


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
/* ****************************************************************************************
 * Method
 */

extern "C" void HardFault_Handler(void){
  return;
}

void setup(Thread* _this){
  core_at32f415_interrupt_priority();
  boardPeriph = new BoardPeriph();
  Core::gpioc.setFunction(12, false);
  testSerialPort.init();
  testSerialPort.baudrate(115200);
  eth01 = new WT32ETH01(testSerialPort, boardPeriph->led[1]);
  eth01->init();
}

void loop(Thread* _this){
  boardPeriph->led[0].setToggle();
  _this->delay(1000);
}
 
/* ****************************************************************************************
 * End of file
 */ 
