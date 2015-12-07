#ifndef HD7279_H
#define HD7279_H

/*****************************readme.txt*****************************************
    Module Name: HD7279.h
	Module Date: 11/14/2013                         
	Module Auth: lvzhen
	
	Description:
	HD7279.C是AVR系列单片机的配置文件，键盘调试程序
	使用前必须先进行宏定义的“管脚配置”、”键值转换配置“

	外部调用常用有三个函数
	#：init_7279()为7279初始化函数，在使用HD7279前必须先调用此文件
	#：void dis_data ( unsigned char dig_start,unsigned char dig_end,signed long num);
			键盘显示数据的函数
			利用从dig_start到dig_end这些位显示数字
			num为显示的值
    #：signed long get_data ( signed char dig_start,signed char dig_end );
			从键盘获取数字的函数
			在从dig_start到dig_end这些位显示“_”并等待输入
	同样是外部调用有四个不常用函数		
	#：void write7279(unsigned char cmd,unsigned char dta);
			前一个cmd为指令，可直接调用宏义中“HD7279指令集”
			后一个dat为数据，输入0x80+i,i为显示的数字
	#：unsigned char read7279(void)：数据读取函数
			返回是键盘的原始值，没有进行任何转换
	#：unsigned char get_key7279(void)：读取一个键值
			调用函数后，等待按键，直到有按键按下并松开，
			返回一个与键值对应的键值，经过数值转换	
	#：void test_7279(void); //	测试函数
			
	内部函数，不对用户开发
	
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
/********************************管脚配置*****************************/
//管脚需要根据实际情况进行配置，此处以PA5、PA4、PA3、PA2为例
#define WR7279 PORTA												   
#define RD7279 PINA     
//任意时刻可以得到管脚电平值
#define DR7279 DDRA

#define cs7279  BIT(5)	
//cs7279定义为PA^3
#define clk7279 BIT(4) 	
//clk7279定义为PA^2
#define dat7279 BIT(3)	
//dat7279定义为PA^1
#define key7279 BIT(2)	
//key7279定义为PA^0

/******************************键值转换配置********************************/

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
/********************************HD7279指令集***************************/
#define CMD_RESET 0xa4		//复位（清除）指令
#define CMD_TEST 0xbf		//测试指令
#define DECODE0 0x80		//方式0译码
#define DECODE1 0xc8		//方式1译码
#define CMD_READ 0x15		//读取键盘数据指令
#define UNDECODE 0x90		//不带小数点显示
#define RTL_CYCLE 0xa3		//循环左移指令
#define RTR_CYCLE 0xa2		//循环右移指令
#define RTL_UNCYL 0xa1		//左移指令
#define RTR_UNCYL 0xa0		//右移指令
#define ACTCTL 0x98		    //消隐控制
#define SEGON 0xe0		    //段点亮指令	
#define SEGOFF 0xc0		    //段关闭指令
#define BLINKCTL 0x88		//闪烁控制

/*-----External Function Prototypes------*/
/***********外部调用函数申明**************/
extern void init_7279(void);	  	 
extern void write7279(unsigned char cmd,unsigned char dta);	//写入到HD7279
extern unsigned char read7279(void);
extern unsigned char get_key7279(void);
extern void test_7279(void);

/********* HD7279输入输出函数 ************/
extern void dis_data ( unsigned char dig_start,unsigned char dig_end,signed long num);
extern void dis_data_RP ( unsigned char dig_start,unsigned char dig_end,signed long num,int rp);
extern signed long get_data ( signed char dig_start,signed char dig_end );

/*********** HD7279测试函数***************/
extern void test_7279(void); //	测试函数

/************内部函数申明*****************/
extern void long_delay(void);	//长时延函数
extern void short_delay(void);	//短时延函数					
extern void delay10ms(unsigned int);	//10ms时延函数		
extern void send_byte(unsigned char);	
extern unsigned char receive_byte(void);			
extern unsigned char  num_change7279 (unsigned char X);

#endif