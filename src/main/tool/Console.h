/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef TOOL_4207A82C_790E_486E_A2E7_0D66F63DC3DA
#define TOOL_4207A82C_790E_486E_A2E7_0D66F63DC3DA

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf.h"
#include "core_arterytek_at32f415.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */  
namespace tool{
  class Console;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class tool::Console extends mcuf::lang::Object{

  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */
  public:
    arterytek::at32f415::serial::CoreSerialPort mCoreSerialPort;
    mcuf::io::SerialPortOutputStream mSerialPortOutputStream;
    mcuf::io::SerialPortInputStream mSerialPortInputStream;
    mcuf::io::OutputStreamBuffer mOutputStreamBuffer;
    mcuf::io::PrintStream mPrintStream;
    uint8_t mCoreSerialPortMemory[256];
    uint8_t mPrintStreamMemory[256];
    uint8_t mOutputStreamBufferMemory[1024];


  /* **************************************************************************************
   * Abstract method <Public>
   */

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */
  public:

    /**
     * @brief Construct a new Console object
     * 
     */
    Console(void);

    /**
     * @brief Destroy the Console object
     * 
     */
    virtual ~Console(void);

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override>
   */

  /* **************************************************************************************
   * Public Method <Inline>
   */
  public:

    /**
     * @brief 
     * 
     * @return mcuf::io::PrintStream& 
     */
    inline mcuf::io::PrintStream& out(void){
      return this->mPrintStream;
    }
    
    /**
     * @brief 
     * 
     * @return mcuf::io::InputStream& 
     */
    inline mcuf::io::InputStream& in(void){
      return this->mSerialPortInputStream;
    }

  /* **************************************************************************************
   * Public Method
   */

  /* **************************************************************************************
   * Protected Method <Static>
   */

  /* **************************************************************************************
   * Protected Method <Override>
   */

  /* **************************************************************************************
   * Protected Method
   */

  /* **************************************************************************************
   * Private Method <Static>
   */

  /* **************************************************************************************
   * Private Method <Override>
   */

  /* **************************************************************************************
   * Private Method
   */

};

/* ****************************************************************************************
 * End of file
 */ 

#endif /* TOOL_4207A82C_790E_486E_A2E7_0D66F63DC3DA */
