/*******************************************************************************
**  MCU        : ATmega16 (Atmel)
**  Compiler   : ICCAVR 7.22
**  Module Name: HC_SR04.c
**  Module Date: 2015-10-22
**  Module Auth: �̺�Ʈ
**  Description: ������������
**  Version    : V1.0
**  Notes      : 
**------------------------------------------------------------------------------
/*----------------------------  I N C L U D E S  -----------------------------*/
#include "HC_SR04.h"
#include "AVRTypes.h"
/*--------------------------  D E F I N I T I O N  ---------------------------*/
//#define basic_Frequency 7.3728*10^6


unsigned char TimerOut_Flag = 0;
/*---------------------------  F U N C T I O N S  ----------------------------*/
void HC_SR04_Init(void)
{
 	 DDRD |= (0x01<<3);//TRIG output
	 DDRD &= ~(0x01<<4);//ECHO input
	 PORTD &=~(0X01<<3);//TRIG output LOW
}  

//TIMER1 initialize - prescale:1
// WGM: 0) Normal, TOP=0xFFFF
// desired value: 1KHz
// actual value:  1.000KHz (0.0%)
void timer1_init(void)
{
 TCCR1B = 0x00; //stop
 TCNT1H = 0x00; //setup
 TCNT1L = 0x00;
 OCR1AH = 0xE0;
 OCR1AL = 0xFF;
 OCR1BH = 0xE0;
 OCR1BL = 0xFF;
 ICR1H  = 0xE0;
 ICR1L  = 0xFF;
 TCCR1A = 0x00;
 TCCR1B = 0x00; //start Timer
}

#pragma interrupt_handler timer1_ovf_isr:iv_TIM1_OVF
void timer1_ovf_isr(void)
{
 //TIMER1 has overflowed
 TCNT1H = 0x00; //reload counter high value
 TCNT1L = 0x00; //reload counter low value
 //PORTC ^= (0X01<<6);
 TimerOut_Flag = 1;
 TCCR1B = 0x00; //stop
 
}

float GetDistance(void)
{
    float distance = 0;
	INT16U Time = 0;
	TimerOut_Flag = 0;
	TRIG_High;
	Delay_us(10);
	TRIG_Low;
	while(!ECHO_Read);//wait ECHO output high
	TCNT1H = 0x0; //reload counter high value
    TCNT1L = 0x0; //reload counter low value
	TCCR1B = 0x01; //start Timer}
	while(ECHO_Read&&!TimerOut_Flag);//  wait ECHO output low or time out
	TCCR1B = 0x00; //stop
	if(TimerOut_Flag)                                  
	{
	   Time = 0xffff;
	   PORTC |= (0X01<<6);   
	}
	else
	{
	   Time = TCNT1;
	   PORTC &= ~(0X01<<6);
	}   
	   
	distance = ((float)Time)*170*1000/7372800;
	return distance;
}
//==============================  End Of File  ===============================//

