/********************************************************

电子技术实习基地

************************************************************/
/************************ MEI *******************************
	Module Name: HD7279.c
	Module Date: 11/14/2013
	Module Auth: 吕振
	
	Description: 7279键盘的使用
************************* MEI *****************************/
/*------------------------Includes------------------------*/
#include "HD7279.h"

/***************外部调用函数*******************************/

/**********************************************************
函数名：HD7279初始化函数	
功  能：初始化HD7279（管脚配置、HD7279复位）
输  入：无
返  回：无
备  注：使用先，选配置管脚的宏定义
*********************************************************/		
void init_7279(void)	
{
	unsigned int tmr;
	
	DR7279 |= cs7279;		         //cs7279定义为输出
	DR7279 |= clk7279;		         //clk7279定义为输出
	DR7279 |= dat7279;		         //dat7279定义为输出
	DR7279 &= ~(key7279);		     //key7279定义为输入
	
	WR7279 |= cs7279;		         //cs7279初始化为1
 	WR7279 |= clk7279;		         //clk7279初始化为1
 	WR7279 |= dat7279;		         //dat7279初始化为1
 	WR7279 |= key7279;		         //key7279初始化为有弱上拉 
 	
 	for(tmr=0;tmr<0xf000;tmr++);	 //上电延时
 		
	send_byte(CMD_RESET);		     //复位HD7279
 		 	 		
}  	 

/****************** **********************
函数名：HD7279写入函数	
功  能：对HD7279写数据
输  入：cmd为指令数据;	dta为数据数据
返  回：无
备  注：HD7279的控制函数
******************************************/
void write7279(unsigned char cmd,unsigned char dta)	//写入到HD7279
{	
	send_byte(cmd);		//写指令
	send_byte(dta);		//定数据
}

/****************** **********************
函数名：HD7279读取函数	
功  能：对HD7279读取原始键值
输  入：无
返  回：键盘原始键值
备  注：HD7279的控制函数
******************************************/
unsigned char read7279(void)
{
	send_byte(0x15);	        //发送读取指令
	return(receive_byte());	    //返回键值
	
}

/****************** **********************
函数名：HD7279按键等待接收函数	
功  能：当完成一次按键，返回键值
输  入：无
返  回：键盘键值
备  注：HD7279的控制函数
******************************************/
unsigned char get_key7279(void)
{
	unsigned char KeyNum;
	while( (RD7279&key7279) );		//等待有键按下,无时为高电平
	
	delay10ms(1);				    //时延100ms
	
	KeyNum=read7279();			    //读出键码	
	
	KeyNum=num_change7279(KeyNum);  //键码转为十进制
	
	delay10ms(1);				    //时延100ms
	
	while( !(RD7279&key7279) );		//等待按键松开
	
	return KeyNum;				    //返回键值
}

/******************************内部函数************************************/
void long_delay(void)               //长时延函数
{
	unsigned char i;
	for(i=0;i<80;i++);
}	

void short_delay(void)            //短时延函数					

{
	unsigned char i;
	for(i=0;i<46;i++);
}
				
void delay10ms(unsigned int count)//10ms时延函数
{
	unsigned char i,j,k;
 	for (i=0;i<count;i++)
      		for(j=0;j<100;j++)
      			for(k=0;k<100;k++);
}	
	
/****************** **********************
函数名：HD7279字节发送函数	
功  能：HD7279发送一个字节
输  入：一个字节
返  回：无
备  注：HD7279硬件函数
******************************************/
void send_byte(unsigned char out_byte)
{	
	unsigned char i;
	
	WR7279&=~clk7279;		    //clk7279=0;
	WR7279&=~cs7279;		    //cs7279=0
	long_delay();
	
	for(i=0;i<8;i++)
	{
		if(out_byte&0x80)
		{
			WR7279|=dat7279;	//dat7279=1;
		 }
		 else
		 {
		 	WR7279&=~dat7279;	//dat7279=0;
		 }
		 WR7279|=clk7279;		//clk7279=1;
		 short_delay();
		 WR7279&=~clk7279;		//clk7279=0;
		 short_delay();
		 out_byte=out_byte<<1;
	 }
	 WR7279|=dat7279;			//dat7279=1; 	 
}
	
/****************** **********************
函数名：HD7279字节接收函数	
功  能：从HD7279接收一个字节
输  入：无
返  回：一个字节
备  注：HD7279硬件函数
******************************************/
unsigned char receive_byte(void)
{
	unsigned char i,in_byte;
	
	WR7279|=clk7279;		    //clk7279=1;
	
	DR7279&=~dat7279;			//改dat7279为输入
	
	long_delay();
	
	for(i=0;i<8;i++)
	{	
		WR7279|=clk7279;		//clk7279=1;
		short_delay();
		in_byte=in_byte<<1;
		if(RD7279&dat7279)
		{
			in_byte=in_byte|0x01;
		}
		WR7279&=~clk7279;		//clk7279=0;
		short_delay();
	
	}
	DR7279|=dat7279;			//dat7279还原为输出口
	return(in_byte);
}

/****************** **********************
函数名：HD7279按键等待接收函数	
功  能：当完成一次按键，返回键值
输  入：无
返  回：键盘键值
备  注：HD7279的控制函数
******************************************/
unsigned char  num_change7279 (unsigned char X)
 {
   	switch (X)
	{
		case  ONE 	: return 0X01;
		case  TWO 	: return 0X02;
		case  THREE 	: return 0X03;
		case  FOUR 	: return 0X04;
		case  FIVE 	: return 0X05;
		case  SIX  	: return 0X06;
		case  SEVEN 	: return 0X07;
		case  EIGHT 	: return 0X08;
		case  NINE 	: return 0X09;
		case  ZERO 	: return 0X00;
		case  AAAA  	: return 0x0A;
		case  BBBB 	: return 0x0B;
		case  CCCC 	: return 0x0C;
		case  DDDD 	: return 0x0D;
		case  EEEE 	: return 0x0E;
		case  FFFF 	: return 0x0F;
		default 	: return 0xFF;
	}
}


		


/****************** HD7279测试函数*************************/
void test_7279(void)
{
	unsigned long wait_cnter;
	unsigned long tmr,j,k;
	unsigned char key7279_number;
	init_7279();
	while(1)
	{
		for(tmr=0;tmr<0xf000;tmr++);	//上电延时
		send_byte(CMD_RESET);		    //复位HD7279

		//测试指令演示

		send_byte(CMD_TEST);
		for(j=0;j<3;j++)		        //延时约3秒
		{	
			delay10ms(100);
		}
		send_byte(CMD_RESET);		    //清除显示
		
	
		{	
		 write7279(DECODE0+0,0x80);
		 write7279(DECODE0+1,0x81);
		 write7279(DECODE0+2,0x82);
		 write7279(DECODE0+3,0x83);
		 write7279(DECODE0+4,0x84);
		 write7279(DECODE0+5,0x85);
		 write7279(DECODE0+6,0x86);
		 write7279(DECODE0+7,0x87);
		 }
		 
		delay10ms(200);

		//闪烁指令及键盘接口测试，
		//将用户按键的键码显示出来，
		//如果10秒内无按键或按S0键即进入下一步演示
		wait_cnter=0;
		key7279_number=0xff;
		write7279(BLINKCTL,0xfc);			//第1?2两位设为闪烁显示 1111，1100
		write7279(UNDECODE,0x08);           //0x08 is '_'
		write7279(UNDECODE+1,0x08);			//在第1?2位显示下划线'_'
		do
		{
			if(!(RD7279&key7279))			//如果有键按下
			{   
			 write7279(DECODE0+7,0x88);
			 key7279_number=read7279();     //读出键码
			 write7279(BLINKCTL,0xff);
			 write7279(DECODE1+1,key7279_number/16);	//在第2 位显示键码高8位
			 write7279(DECODE1,key7279_number&0x0f);	//在第1位显示键码低8位
			 while(!(RD7279&key7279));			        //等待按键放开
			 wait_cnter=0;
			 delay10ms(10); 
			}	
		}
		while(wait_cnter<1000);	
		
		//如果按键为'0'和超时则进入下一步演示
		write7279(BLINKCTL,0xff);			//清除闪烁设置 无位显示闪烁1111,1111
		send_byte(CMD_RESET);				//清除显示
	
		//下载数据但不译码指令测试
		write7279(UNDECODE+7,0x49);		//在第8位按不译码方式显示一个字符‘三’。
		delay10ms(80);
	
		//循环左右移测试，‘三’字向右移3次，再向左移3次。
		for(j=0;j<23;j++)
		{
			send_byte(RTR_CYCLE);			//循环右移23次
			delay10ms(12);
		}
		
		for(j=0;j<23;j++)
		{
			send_byte(RTL_CYCLE);			//循环左移23次
			delay10ms(12);
		}
	
		//译码方式0及左移指令测试
		for(j=0;j<16;j++)
		{
			send_byte(RTL_UNCYL);			//不循环左移指令
			write7279(DECODE0,j);			//译码方式0，显示在第1位
			delay10ms(50);
		}
			delay10ms(150);
			send_byte(CMD_RESET);
	
		//译码方式1及右移指令测试
		for(j=0;j<16;j++)
		{
			send_byte(RTR_UNCYL);			//不循环左移指令
			write7279(DECODE1+7,j);			//译码方式1，显示在第8位
			delay10ms(50);
		}
		delay10ms(150);
	
		//消隐指令测试
	
		for(j=0;j<6;j++)
		{
			k=k>>1;
			write7279(ACTCTL,k);			//每隔一秒钟增加一个消隐位
			delay10ms(100);
		}
		write7279(ACTCTL,0xff);				//恢复8位显示
		delay10ms(100);
		send_byte(CMD_RESET);				//清除显示
	
		//段点亮指令和段关闭指令
		for(j=0;j<64;j++)
		{
			write7279(SEGON,j);			//将64个显示段逐个点亮
			write7279(SEGOFF,j-1);			//同时将前一个显示段关闭
			delay10ms(20);
		}
	}
}




/********************************** HD7279输入输出函数 *******************************************/

void dis_data ( unsigned char dig_start,unsigned char dig_end,signed long num)
{
	unsigned char i,temp_char;
	
	for( i = dig_start; i <= dig_end; i++ )
	{
		temp_char = num % 10;
		num -= temp_char;
		num /= 10;	
		write7279 ( DECODE0 + i , 0x00 +  temp_char );//0x00为不加点显示，0x80为加点显示

	}
}


//带小数点显示，可以在rp位显示小数点
void dis_data_RP ( unsigned char dig_start,unsigned char dig_end,signed long num,int rp)
{
	unsigned char i,temp_char;
	
	for( i = dig_start; i <= dig_end; i++ )
	{
		temp_char = num % 10;
		num -= temp_char;
		num /= 10;
		if(i!=rp)
		write7279 ( DECODE0 + i , 0x00 +  temp_char );//0x00为不加点显示，0x80为加点显示
		else
		write7279 ( DECODE0 + i , 0X80 +  temp_char );
	}
}/**/

signed long get_data ( signed char dig_start,signed char dig_end )
{
	signed long temp_long = 0;
	signed char i,temp_char;	
	
	for( i = dig_start; i <= dig_end; i++ )
		write7279(UNDECODE + i,0x08);  //显示为'_'
		
	for( i = dig_end; i >= dig_start ; i-- )
	{
		temp_char = get_key7279();
		
		temp_long *= 10;
		temp_long += temp_char;
		
		write7279 ( DECODE1 + i , 0x80 +  temp_char); //1译码可以显示字母
	}
	delay10ms(5);
	send_byte(CMD_RESET);
		
	return temp_long;		
}

