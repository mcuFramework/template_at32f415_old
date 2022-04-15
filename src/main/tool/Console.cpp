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

//-----------------------------------------------------------------------------------------
#include "tool/Console.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using tool::Console;

using arterytek::at32f415::Core;
using arterytek::at32f415::CoreIomux;
using arterytek::at32f415::general::CoreGeneralPin;
using arterytek::at32f415::general::CoreGeneralPort;
using arterytek::at32f415::general::OutputMode;
using arterytek::at32f415::serial::CoreSerialPort;
using arterytek::at32f415::serial::CoreSerialPortReg;
using mcuf::util::Stacker;
using mcuf::lang::Memory;

using mcuf::io::SerialPortOutputStream;
using mcuf::io::OutputStreamBuffer;
using mcuf::io::PrintStream;
using mcuf::io::ByteBuffer;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

/**
 *
 */
Console::Console(void){
  this->mCoreSerialPort = new CoreSerialPort(CoreSerialPortReg::REG_UART4, 256);
  this->mCoreSerialPort->init();
  this->mCoreSerialPort->baudrate(128000);
  
  this->mSerialPortOutputStream = new SerialPortOutputStream(*this->mCoreSerialPort);
  
  this->mOutputStreamBuffer = new OutputStreamBuffer(*this->mSerialPortOutputStream, 1024);
  
  this->mPrintStream = new PrintStream(*this->mOutputStreamBuffer, 256);
  
  Core::gpioc.setFunction(10, false);
  return;
}

/**
 *
 */
Console::~Console(void){
  this->mCoreSerialPort->deinit();
  
  delete this->mPrintStream;
  delete this->mOutputStreamBuffer;
  delete this->mSerialPortOutputStream;
  delete this->mCoreSerialPort;
  
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/* ****************************************************************************************
 * Public Method <Override>
 */

/* ****************************************************************************************
 * Public Method
 */

/* ****************************************************************************************
 * Protected Method <Static>
 */

/* ****************************************************************************************
 * Protected Method <Override>
 */

/* ****************************************************************************************
 * Protected Method
 */

/* ****************************************************************************************
 * Private Method
 */

/* ****************************************************************************************
 * End of file
 */
