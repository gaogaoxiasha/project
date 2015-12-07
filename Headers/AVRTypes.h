/*C*****************************************************************************
* NAME:         AVRTypes.h
*-------------------------------------------------------------------------------
* Copyright (c) .
*-------------------------------------------------------------------------------
* RELEASE:            
* REVISION:          
*-------------------------------------------------------------------------------
* PURPOSE:
* 定义与平台无关的变量类型，以及常用的常数 
*
* NOTES: Target MCU are Atmel AVR series
*******************************************************************************/

#ifndef AVRTYPES_H
#define AVRTYPES_H

/*_____ I N C L U D E S ______________________________________________________*/

/*_____ M A C R O S __________________________________________________________*/

#ifndef TRUE
#define TRUE	(255)
#endif

#ifndef FALSE
#define FALSE	(0)
#endif

#ifndef ON
#define ON		(25)
#endif

#ifndef OFF
#define OFF		(0)
#endif

#ifndef OK
#define OK		(255)
#endif

#ifndef ERROR
#define ERROR	(0)
#endif

#ifndef CR
#define CR		(0x0D)
#endif


/*_____ D E F I N I T I O N __________________________________________________*/

// datatype definitions macros
typedef unsigned char      INT8U;   //定义与平台无关的无符号8 位数据类型
typedef   signed char      INT8S;   //定义与平台无关的有符号8 位数据类型
typedef char	 		   INT8;
typedef unsigned short     INT16U;  //定义与平台无关的无符号16位数据类型
typedef   signed short     INT16S;  //定义与平台无关的有符号16位数据类型
typedef int		 		   INT16;
typedef unsigned long      INT32U;  //定义与平台无关的无符号32位数据类型
typedef   signed long      INT32S;  //定义与平台无关的有符号32位数据类型
//typedef unsigned long long INT64U;  //定义与平台无关的无符号64位数据类型
//typedef   signed long long INT64S;  //定义与平台无关的有符号64位数据类型
typedef float	 	  	   S32S;	//
typedef double			   D64S;	//


/*_____ D E C L A R A T I O N ________________________________________________*/

#endif /* AVRTYPES_H */
