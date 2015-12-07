/**------------------------------------------------------------------------------
**  MCU        : ATmega16 (Atmel)
**  Compiler   : ICCAVR 7.22
**  Module Name: 
**  Module Date: 
**  Module Auth: 
**  Description: 
**  Version    : V1.0
**  Notes      : 
**------------------------------------------------------------------------------
**  Version    : 
**  Modified By: 
**  Date       : 
**  Content    : 
**  Notes      : 
*******************************************************************************/

#ifndef __DS18B20_H__
#define __DS18B20_H__

/*----------------------------  I N C L U D E S  -----------------------------*/
#include "../Headers/Includes.h"

/*------------------------------  M A C R O S  -------------------------------*/
#define DQ PD5


/*-------------------------  D E C L A R A T I O N  --------------------------*/
/* Internal Variable */

/* External Variable */

/* Internal Function */
void write_1820(unsigned char Data); 
unsigned char read_1820(void); 
/* External Function */
extern void DS18B20Init(void);
extern INT32U gettemp(void);

#endif

//==============================  End Of File  ===============================//

