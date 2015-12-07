/*******************************************************************************
**  Copyright (c)   2011       USTB MEI
**                  All Rights Reserved
**  
**  Email:ustbyf@126.com   QQ:316969230
**------------------------------------------------------------------------------
**  MCU        : ATmega8 (Atmel)
**  Compiler   : ICCAVR 7.22
**  Module Name: Delay.h
**  Module Date: 2011-03-14
**  Module Auth: ÎâÇÚ±ø
**  Description: Delay functions for ATmega8 at 7.3728MHz
**  Version    : V1.0
**  Notes      : These delay functions are suited for ATmega8 at 7.3728MHz.
**------------------------------------------------------------------------------
**  Version    : 
**  Modified By: 
**  Date       : 
**  Content    : 
**  Notes      : 
*******************************************************************************/

#ifndef __DELAY_H__
#define __DELAY_H__

/*----------------------------  I N C L U D E S  -----------------------------*/
#include "../Headers/Includes.h"

/*------------------------------  M A C R O S  -------------------------------*/

/*-------------------------  D E C L A R A T I O N  --------------------------*/
/* Internal Variable */

/* External Variable */

/* Internal Function */

/* External Function*/ 
//extern void long_delay(void);	//³¤Ê±ÑÓº¯Êý
extern void Delay_us(INT32U n);
extern void Delay_ms(unsigned int n);
extern void Delay_us1(int n);
extern void Delay_ms1(int n);



#endif

//==============================  End Of File  ===============================//

