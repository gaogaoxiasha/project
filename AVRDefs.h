/*C*****************************************************************************
* NAME:         AVRDefs.h
*-------------------------------------------------------------------------------
* Copyright (c) .
*-------------------------------------------------------------------------------
* RELEASE:            
* REVISION:          
*-------------------------------------------------------------------------------
* PURPOSE:
* AVRÐ¾Æ¬µÄºê¶¨Òå
*
* NOTES:
*******************************************************************************/

#ifndef AVRDEFS_H
#define AVRDEFS_H

/*_____ I N C L U D E S ______________________________________________________*/

/*_____ M A C R O S __________________________________________________________*/

// Code compatibility to new AVR-libc
// outb(), inb(), BV(), sbi(), cbi(), sei(), cli()
#ifndef outb
    #define outb(addr, data)    addr = (data)
#endif
#ifndef inb
    #define inb(addr)           (addr)
#endif
#ifndef BV
    #define BV(bit)             (1<<(bit))
#endif
#ifndef cbi
    #define cbi(reg,bit)        reg &= ~(BV(bit))
#endif
#ifndef sbi
    #define sbi(reg,bit)        reg |= (BV(bit))
#endif
#ifndef cli
    #define cli()               __asm__ __volatile__ ("cli" ::)
#endif
#ifndef sei
    #define sei()               __asm__ __volatile__ ("sei" ::)
#endif
#ifndef nop
    #define	nop()               __asm__ __volatile__ ("nop" ::)
#endif
#ifndef wdr
    #define	wdr()               __asm__ __volatile__ ("wdr" ::)
#endif
#ifndef sleep
    #define	sleep()             __asm__ __volatile__ ("sleep" ::)
#endif

// MIN/MAX/ABS macros
#define MIN(a,b)               ((a<b)?(a):(b))
#define MAX(a,b)               ((a>b)?(a):(b))
#define ABS(x)                 ((x>0)?(x):(-x))


#ifndef GetBitVal

#define GetBitVal(Bus,Pin)  (Bus&(1<<Pin))

#endif



// constants
#define PI      3.14159265359

/*_____ D E F I N I T I O N __________________________________________________*/

/*_____ D E C L A R A T I O N ________________________________________________*/

#endif /* AVRDEFS_H */
