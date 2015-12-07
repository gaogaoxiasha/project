/**------------------------------------------------------------------------------
**  MCU        : ATmega16(Atmel)
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

/*----------------------------  I N C L U D E S  -----------------------------*/
#include "DS18B20.h"

/*--------------------------  D E F I N I T I O N  ---------------------------*/

/*---------------------------  F U N C T I O N S  ----------------------------*/
/*******************************************************************************
Function Name: void DS18B20Init(void)
Author       : 
Date         : 
Description  : 
Inputs       : None
Outputs      : None
Notes        : 
Revision     : 
*******************************************************************************/
void DS18B20Init(void)  
{  

   DDRD|=BIT(DQ); //DQ Ϊ���״̬
   PORTD&=~BIT(DQ); //����͵�ƽ
   Delay_us1(500); //�ӳ�500 ΢��
   PORTD|=BIT(DQ); //ʾ������
   Delay_us1(60); //�ӳ�60 ΢��
   DDRD&=~BIT(DQ); //DQ λ����״̬
   while(PIND&BIT(DQ)); //�ȴ��ӻ�DS18B20 Ӧ�𣨵͵�ƽ��Ч��
   while(!(PIND&BIT(DQ)));

}  
/*******************************************************************************
Function Name: void write_1820(unsigned char Data)  
Author       : 
Date         : 
Description  : 
Inputs       : None
Outputs      : None
Notes        : 
Revision     : 
*******************************************************************************/
void write_1820(unsigned char Data)  
{   

    unsigned char i;
    DDRD|=BIT(DQ); //DQ Ϊ���
   for(i=0;i<8;i++)
   {
    PORTD&=~BIT(DQ); //��������
    Delay_us1(10); //�ӳ�10 ΢����15 ΢�
    if(Data&0x01) 
	  PORTD|=BIT(DQ);
    else PORTD&=~BIT(DQ);
      Delay_us(40); //�ӳ�40 ΢����45 ΢� 
	PORTD|=BIT(DQ); //�ͷ�����
   Delay_us1(1); //��΢�ӳ�
    Data>>=1;}

}  
/*******************************************************************************
Function Name: 
Author       : 
Date         : 
Description  : 
Inputs       : None
Outputs      : None
Notes        : 
Revision     : 
*******************************************************************************/
unsigned char read_1820(void)  
{   
   unsigned char i,Temp;
   for(i=0;i<8;i++)
 {
   Temp>>=1; //��������
   DDRD|=BIT(DQ); //DQ Ϊ���״̬
   PORTD&=~BIT(DQ); //�������ߣ���������
  PORTD|=BIT(DQ); //�ͷ�����
   DDRD&=~BIT(DQ); //DQ Ϊ����״̬
  if(PIND&BIT(DQ)) 
  Temp|=0x80;
  Delay_us1(45); //�ӳ�45 ΢����45 ΢�
   }


return Temp; } 




/*******************************************************************************
Function Name: 
Author       : 
Date         : 
Description  : 
Inputs       : None
Outputs      : None
Notes        : 
Revision     : 
*******************************************************************************/
INT32U gettemp(void)  //��ȡ�¶�ֵ 
{  //Լ5 ms
     unsigned int temh,teml;  
	 INT16U TEM;
     unsigned int  Temperature=0; //����Tc,ʵ�ʵ��¶�T=Tc*0.1,��������������
	
     DS18B20Init();        //��λ18b20  
     write_1820(0xcc);   // ����ת������  
     write_1820(0x44); 
     
     DS18B20Init();  
     write_1820(0xcc);  //����������  
     write_1820(0xbe);  
     teml=read_1820();   
     temh=read_1820();  //������
	 
	 TEM = ((temh<<8)|teml);
	/* if((1<<15)&(TEM))//����1����ʾΪ��
	 {
	  TEM = ((1<<12)-(TEM&~(0X1F<<15)));//��������
	 } 
	 else
	 {
	  TEM = ((temh<<8)|teml);
	 }*/	 	 
	 DS18B20Init(); 
	 return TEM;//*6.25;//(((temh<<8)|teml)*6.25);
	// return (((unsigned int)(temh)<<8)+teml);
	 
} 

	 
	/* if(temh&0xFC) //�жϷ���λ�Ƿ�Ϊ1
   {
   
   Temperature = ((temh<<8 ) | teml ); //�߰�λ�ڰ�λ��������
   Temperature= ((~Temperature)+1); //�󷴣���һ
   Temperature*= 0.0625; //���ʮ����
      } //Temperature=55;
   else
   {
 

   Temperature = ((temh<<8 ) | teml ) * (0.0625 * 10) ;
  }*/

   
   
    
  

//==============================  End Of File  ===============================//

