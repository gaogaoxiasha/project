/*C*****************************************************************************
* NAME:         AVRTypes.h
*-------------------------------------------------------------------------------
* Copyright (c) .
*-------------------------------------------------------------------------------
* RELEASE:            
* REVISION:          
*-------------------------------------------------------------------------------
* PURPOSE:
* ������ƽ̨�޹صı������ͣ��Լ����õĳ��� 
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
typedef unsigned char      INT8U;   //������ƽ̨�޹ص��޷���8 λ��������
typedef   signed char      INT8S;   //������ƽ̨�޹ص��з���8 λ��������
typedef char	 		   INT8;
typedef unsigned short     INT16U;  //������ƽ̨�޹ص��޷���16λ��������
typedef   signed short     INT16S;  //������ƽ̨�޹ص��з���16λ��������
typedef int		 		   INT16;
typedef unsigned long      INT32U;  //������ƽ̨�޹ص��޷���32λ��������
typedef   signed long      INT32S;  //������ƽ̨�޹ص��з���32λ��������
//typedef unsigned long long INT64U;  //������ƽ̨�޹ص��޷���64λ��������
//typedef   signed long long INT64S;  //������ƽ̨�޹ص��з���64λ��������
typedef float	 	  	   S32S;	//
typedef double			   D64S;	//


/*_____ D E C L A R A T I O N ________________________________________________*/

#endif /* AVRTYPES_H */
