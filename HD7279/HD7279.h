#ifndef HD7279_H
#define HD7279_H

/*****************************readme.txt*****************************************
    Module Name: HD7279.h
	Module Date: 11/14/2013                         
	Module Auth: lvzhen
	
	Description:
	HD7279.C��AVRϵ�е�Ƭ���������ļ������̵��Գ���
	ʹ��ǰ�����Ƚ��к궨��ġ��ܽ����á�������ֵת�����á�

	�ⲿ���ó�������������
	#��init_7279()Ϊ7279��ʼ����������ʹ��HD7279ǰ�����ȵ��ô��ļ�
	#��void dis_data ( unsigned char dig_start,unsigned char dig_end,signed long num);
			������ʾ���ݵĺ���
			���ô�dig_start��dig_end��Щλ��ʾ����
			numΪ��ʾ��ֵ
    #��signed long get_data ( signed char dig_start,signed char dig_end );
			�Ӽ��̻�ȡ���ֵĺ���
			�ڴ�dig_start��dig_end��Щλ��ʾ��_�����ȴ�����
	ͬ�����ⲿ�������ĸ������ú���		
	#��void write7279(unsigned char cmd,unsigned char dta);
			ǰһ��cmdΪָ���ֱ�ӵ��ú����С�HD7279ָ���
			��һ��datΪ���ݣ�����0x80+i,iΪ��ʾ������
	#��unsigned char read7279(void)�����ݶ�ȡ����
			�����Ǽ��̵�ԭʼֵ��û�н����κ�ת��
	#��unsigned char get_key7279(void)����ȡһ����ֵ
			���ú����󣬵ȴ�������ֱ���а������²��ɿ���
			����һ�����ֵ��Ӧ�ļ�ֵ��������ֵת��	
	#��void test_7279(void); //	���Ժ���
			
	�ڲ������������û�����
	
    Revision History:
    Date        Rel Ver.    	Notes
    11/15/2007		1.0			Module created

*********************************************************************************/

/*----------------Includes---------------*/
#include "../Headers/Includes.h"
/*------------Local Variables----------- */

/*---------Structures and Typedefs-------*/					

/*-----------Extern Variables -----------*/

/*---------------Defines-----------------*/
/********************************�ܽ�����*****************************/
//�ܽ���Ҫ����ʵ������������ã��˴���PA5��PA4��PA3��PA2Ϊ��
#define WR7279 PORTA												   
#define RD7279 PINA     
//����ʱ�̿��Եõ��ܽŵ�ƽֵ
#define DR7279 DDRA

#define cs7279  BIT(5)	
//cs7279����ΪPA^3
#define clk7279 BIT(4) 	
//clk7279����ΪPA^2
#define dat7279 BIT(3)	
//dat7279����ΪPA^1
#define key7279 BIT(2)	
//key7279����ΪPA^0

/******************************��ֵת������********************************/

#define ONE 0X03
#define TWO 0X02
#define THREE 0X01
#define FOUR 0X00
#define FIVE 0X0B
#define SIX 0X0A
#define SEVEN 0x09
#define EIGHT 0X08
#define NINE 0X13
#define ZERO 0X12
#define AAAA 0X11     
#define BBBB 0x10     
#define CCCC 0X1B       
#define DDDD 0X1A		
#define EEEE 0X19    
#define FFFF 0X18    

/*
#define ONE    0X18 
#define TWO    0x10 
#define THREE  0X08 
#define FOUR   0X19   
#define FIVE   0X11 
#define SIX    0x09 
#define SEVEN  0X1A  
#define EIGHT  0X12 
#define NINE   0X0A 
#define ZERO   0X13 
#define AAAA   0X00      
#define BBBB   0X01      
#define CCCC   0X02        
#define DDDD   0x03 		
#define EEEE   0X0b     
#define FFFF   0X1b 
*/
/********************************HD7279ָ�***************************/
#define CMD_RESET 0xa4		//��λ�������ָ��
#define CMD_TEST 0xbf		//����ָ��
#define DECODE0 0x80		//��ʽ0����
#define DECODE1 0xc8		//��ʽ1����
#define CMD_READ 0x15		//��ȡ��������ָ��
#define UNDECODE 0x90		//����С������ʾ
#define RTL_CYCLE 0xa3		//ѭ������ָ��
#define RTR_CYCLE 0xa2		//ѭ������ָ��
#define RTL_UNCYL 0xa1		//����ָ��
#define RTR_UNCYL 0xa0		//����ָ��
#define ACTCTL 0x98		    //��������
#define SEGON 0xe0		    //�ε���ָ��	
#define SEGOFF 0xc0		    //�ιر�ָ��
#define BLINKCTL 0x88		//��˸����

/*-----External Function Prototypes------*/
/***********�ⲿ���ú�������**************/
extern void init_7279(void);	  	 
extern void write7279(unsigned char cmd,unsigned char dta);	//д�뵽HD7279
extern unsigned char read7279(void);
extern unsigned char get_key7279(void);
extern void test_7279(void);

/********* HD7279����������� ************/
extern void dis_data ( unsigned char dig_start,unsigned char dig_end,signed long num);
extern void dis_data_RP ( unsigned char dig_start,unsigned char dig_end,signed long num,int rp);
extern signed long get_data ( signed char dig_start,signed char dig_end );

/*********** HD7279���Ժ���***************/
extern void test_7279(void); //	���Ժ���

/************�ڲ���������*****************/
extern void long_delay(void);	//��ʱ�Ӻ���
extern void short_delay(void);	//��ʱ�Ӻ���					
extern void delay10ms(unsigned int);	//10msʱ�Ӻ���		
extern void send_byte(unsigned char);	
extern unsigned char receive_byte(void);			
extern unsigned char  num_change7279 (unsigned char X);

#endif