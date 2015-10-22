/*******************************************************************************
**  Copyright (c)   2011       USTB MEI
**                  All Rights Reserved
**  
**  
**-----------------------------------------------------------------------------
**  MCU        : ATmega16 (Atmel)
**  Compiler   : ICCAVR 7.22
**  Module Name: Delay.c
**  Module Date: 2011-03-28
**  Module Auth: ÎâÇÚ±ø
**  Description: Delay functions for ATmega16 at 7.3728MHz
**  Version    : V1.0
**  Notes      : These delay functions are suited for ATmega8 at 7.3728MHz.
**------------------------------------------------------------------------------
**  Version    : 
**  Modified By: 
**  Date       : 
**  Content    : 
**  Notes      : 
*******************************************************************************/

/*----------------------------  I N C L U D E S  -----------------------------*/
#include "Delay.h"

/*--------------------------  D E F I N I T I O N  ---------------------------*/

/*---------------------------  F U N C T I O N S  ----------------------------*/
/*******************************************************************************
Function Name: Delay_us
Author       : ÎâÇÚ±ø
Date         : 2011-03-14
Description  : Delay n us
Inputs       : UINT16 n -- n us
Outputs      : None
Notes        : 
Revision     : 
*******************************************************************************/
void Delay_us(INT32U n)
{          
    unsigned int i = 0;	
    for(i = 0; i < n; i++)
    {
        NOP();
    }
}


void Delay_us1(int n)
{          
    int i = 0;
    int j = 0;
	
    for(i = 0; i < n; i++)
    {
         NOP();
		 NOP();
		 NOP();
		 NOP();
		 NOP();
		 NOP();
		 NOP();
		 NOP();		
    }
}

/*******************************************************************************
Function Name: Delay_ms
Author       : ÎâÇÚ±ø
Date         : 2011-03-14
Description  : Delay n ms
Inputs       : UINT16 n -- n ms
Outputs      : None
Notes        : 
Revision     : 
*******************************************************************************/
void Delay_ms(unsigned int n)
{          
    unsigned int i = 0;
    unsigned int j = 0;
	
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < 2100; j++)
        {
            // Delay n ms
        }
    }
}

void Delay_ms1(int n)
{          
    int i = 0;
    int j = 0;
	
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < 2000; j++)
        {
            // Delay n ms
        }
    }
}

//==============================  End Of File  ===============================//

