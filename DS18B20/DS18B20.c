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

   DDRD|=BIT(DQ); //DQ 为输出状态
   PORTD&=~BIT(DQ); //输出低电平
   Delay_us1(500); //延迟500 微妙
   PORTD|=BIT(DQ); //示范总线
   Delay_us1(60); //延迟60 微妙
   DDRD&=~BIT(DQ); //DQ 位输入状态
   while(PIND&BIT(DQ)); //等待从机DS18B20 应答（低电平有效）
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
    DDRD|=BIT(DQ); //DQ 为输出
   for(i=0;i<8;i++)
   {
    PORTD&=~BIT(DQ); //拉低总线
    Delay_us1(10); //延迟10 微妙（最大15 微妙）
    if(Data&0x01) 
	  PORTD|=BIT(DQ);
    else PORTD&=~BIT(DQ);
      Delay_us(40); //延迟40 微妙（最大45 微妙） 
	PORTD|=BIT(DQ); //释放总线
   Delay_us1(1); //稍微延迟
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
   Temp>>=1; //数据右移
   DDRD|=BIT(DQ); //DQ 为输出状态
   PORTD&=~BIT(DQ); //拉低总线，启动输入
  PORTD|=BIT(DQ); //释放总线
   DDRD&=~BIT(DQ); //DQ 为输入状态
  if(PIND&BIT(DQ)) 
  Temp|=0x80;
  Delay_us1(45); //延迟45 微妙（最大45 微妙）
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
INT32U gettemp(void)  //读取温度值 
{  //约5 ms
     unsigned int temh,teml;  
	 INT16U TEM;
     unsigned int  Temperature=0; //返回Tc,实际的温度T=Tc*0.1,这里用整数运算
	
     DS18B20Init();        //复位18b20  
     write_1820(0xcc);   // 发出转换命令  
     write_1820(0x44); 
     
     DS18B20Init();  
     write_1820(0xcc);  //发出读命令  
     write_1820(0xbe);  
     teml=read_1820();   
     temh=read_1820();  //读数据
	 
	 TEM = ((temh<<8)|teml);
	/* if((1<<15)&(TEM))//等于1，表示为负
	 {
	  TEM = ((1<<12)-(TEM&~(0X1F<<15)));//负数求补码
	 } 
	 else
	 {
	  TEM = ((temh<<8)|teml);
	 }*/	 	 
	 DS18B20Init(); 
	 return TEM;//*6.25;//(((temh<<8)|teml)*6.25);
	// return (((unsigned int)(temh)<<8)+teml);
	 
} 

	 
	/* if(temh&0xFC) //判断符号位是否为1
   {
   
   Temperature = ((temh<<8 ) | teml ); //高八位第八位进行整合
   Temperature= ((~Temperature)+1); //求反，补一
   Temperature*= 0.0625; //求出十进制
      } //Temperature=55;
   else
   {
 

   Temperature = ((temh<<8 ) | teml ) * (0.0625 * 10) ;
  }*/

   
   
    
  

//==============================  End Of File  ===============================//

