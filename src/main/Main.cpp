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
using tool::BoardPeriph;

/* ****************************************************************************************
 * Extern
 */
extern void lowlevel(void);

const char* TEXT = "+CIFSR:ETHIP,\"192.168.11.231\"\r\n+CIFSR:ETHMAC,\"8c:ce:4e:96:0a:2f\"\r\n\0";
const char* FORMAT = "%*[^\"]%s %*[^\"]%s\"";
 
/* ****************************************************************************************
 * Variable
 */
BoardPeriph* boardPeriph;


/* ****************************************************************************************
 * Method
 */

void setup(Thread* _this){
  boardPeriph = new BoardPeriph();
}

void loop(Thread* _this){
  String text = String(TEXT);
	char ip[32];
	char mac[32];
  int result = text.scanFormat(FORMAT, &ip, &mac);
  System::out().format("result = %d\nip = %s\nmac = %s\n", result, ip, mac); 
  //System::out().println(text);
  boardPeriph->led[0].setToggle();
  _this->delay(500);
}
 
/* ****************************************************************************************
 * End of file
 */ 
