/********************************************************

���Ӽ���ʵϰ����

************************************************************/
/************************ MEI *******************************
	Module Name: HD7279.c
	Module Date: 11/14/2013
	Module Auth: ����
	
	Description: 7279���̵�ʹ��
************************* MEI *****************************/
/*------------------------Includes------------------------*/
#include "HD7279.h"

/***************�ⲿ���ú���*******************************/

/**********************************************************
��������HD7279��ʼ������	
��  �ܣ���ʼ��HD7279���ܽ����á�HD7279��λ��
��  �룺��
��  �أ���
��  ע��ʹ���ȣ�ѡ���ùܽŵĺ궨��
*********************************************************/		
void init_7279(void)	
{
	unsigned int tmr;
	
	DR7279 |= cs7279;		         //cs7279����Ϊ���
	DR7279 |= clk7279;		         //clk7279����Ϊ���
	DR7279 |= dat7279;		         //dat7279����Ϊ���
	DR7279 &= ~(key7279);		     //key7279����Ϊ����
	
	WR7279 |= cs7279;		         //cs7279��ʼ��Ϊ1
 	WR7279 |= clk7279;		         //clk7279��ʼ��Ϊ1
 	WR7279 |= dat7279;		         //dat7279��ʼ��Ϊ1
 	WR7279 |= key7279;		         //key7279��ʼ��Ϊ�������� 
 	
 	for(tmr=0;tmr<0xf000;tmr++);	 //�ϵ���ʱ
 		
	send_byte(CMD_RESET);		     //��λHD7279
 		 	 		
}  	 

/****************** **********************
��������HD7279д�뺯��	
��  �ܣ���HD7279д����
��  �룺cmdΪָ������;	dtaΪ��������
��  �أ���
��  ע��HD7279�Ŀ��ƺ���
******************************************/
void write7279(unsigned char cmd,unsigned char dta)	//д�뵽HD7279
{	
	send_byte(cmd);		//дָ��
	send_byte(dta);		//������
}

/****************** **********************
��������HD7279��ȡ����	
��  �ܣ���HD7279��ȡԭʼ��ֵ
��  �룺��
��  �أ�����ԭʼ��ֵ
��  ע��HD7279�Ŀ��ƺ���
******************************************/
unsigned char read7279(void)
{
	send_byte(0x15);	        //���Ͷ�ȡָ��
	return(receive_byte());	    //���ؼ�ֵ
	
}

/****************** **********************
��������HD7279�����ȴ����պ���	
��  �ܣ������һ�ΰ��������ؼ�ֵ
��  �룺��
��  �أ����̼�ֵ
��  ע��HD7279�Ŀ��ƺ���
******************************************/
unsigned char get_key7279(void)
{
	unsigned char KeyNum;
	while( (RD7279&key7279) );		//�ȴ��м�����,��ʱΪ�ߵ�ƽ
	
	delay10ms(1);				    //ʱ��100ms
	
	KeyNum=read7279();			    //��������	
	
	KeyNum=num_change7279(KeyNum);  //����תΪʮ����
	
	delay10ms(1);				    //ʱ��100ms
	
	while( !(RD7279&key7279) );		//�ȴ������ɿ�
	
	return KeyNum;				    //���ؼ�ֵ
}

/******************************�ڲ�����************************************/
void long_delay(void)               //��ʱ�Ӻ���
{
	unsigned char i;
	for(i=0;i<80;i++);
}	

void short_delay(void)            //��ʱ�Ӻ���					

{
	unsigned char i;
	for(i=0;i<46;i++);
}
				
void delay10ms(unsigned int count)//10msʱ�Ӻ���
{
	unsigned char i,j,k;
 	for (i=0;i<count;i++)
      		for(j=0;j<100;j++)
      			for(k=0;k<100;k++);
}	
	
/****************** **********************
��������HD7279�ֽڷ��ͺ���	
��  �ܣ�HD7279����һ���ֽ�
��  �룺һ���ֽ�
��  �أ���
��  ע��HD7279Ӳ������
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
��������HD7279�ֽڽ��պ���	
��  �ܣ���HD7279����һ���ֽ�
��  �룺��
��  �أ�һ���ֽ�
��  ע��HD7279Ӳ������
******************************************/
unsigned char receive_byte(void)
{
	unsigned char i,in_byte;
	
	WR7279|=clk7279;		    //clk7279=1;
	
	DR7279&=~dat7279;			//��dat7279Ϊ����
	
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
	DR7279|=dat7279;			//dat7279��ԭΪ�����
	return(in_byte);
}

/****************** **********************
��������HD7279�����ȴ����պ���	
��  �ܣ������һ�ΰ��������ؼ�ֵ
��  �룺��
��  �أ����̼�ֵ
��  ע��HD7279�Ŀ��ƺ���
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


		


/****************** HD7279���Ժ���*************************/
void test_7279(void)
{
	unsigned long wait_cnter;
	unsigned long tmr,j,k;
	unsigned char key7279_number;
	init_7279();
	while(1)
	{
		for(tmr=0;tmr<0xf000;tmr++);	//�ϵ���ʱ
		send_byte(CMD_RESET);		    //��λHD7279

		//����ָ����ʾ

		send_byte(CMD_TEST);
		for(j=0;j<3;j++)		        //��ʱԼ3��
		{	
			delay10ms(100);
		}
		send_byte(CMD_RESET);		    //�����ʾ
		
	
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

		//��˸ָ����̽ӿڲ��ԣ�
		//���û������ļ�����ʾ������
		//���10�����ް�����S0����������һ����ʾ
		wait_cnter=0;
		key7279_number=0xff;
		write7279(BLINKCTL,0xfc);			//��1?2��λ��Ϊ��˸��ʾ 1111��1100
		write7279(UNDECODE,0x08);           //0x08 is '_'
		write7279(UNDECODE+1,0x08);			//�ڵ�1?2λ��ʾ�»���'_'
		do
		{
			if(!(RD7279&key7279))			//����м�����
			{   
			 write7279(DECODE0+7,0x88);
			 key7279_number=read7279();     //��������
			 write7279(BLINKCTL,0xff);
			 write7279(DECODE1+1,key7279_number/16);	//�ڵ�2 λ��ʾ�����8λ
			 write7279(DECODE1,key7279_number&0x0f);	//�ڵ�1λ��ʾ�����8λ
			 while(!(RD7279&key7279));			        //�ȴ������ſ�
			 wait_cnter=0;
			 delay10ms(10); 
			}	
		}
		while(wait_cnter<1000);	
		
		//�������Ϊ'0'�ͳ�ʱ�������һ����ʾ
		write7279(BLINKCTL,0xff);			//�����˸���� ��λ��ʾ��˸1111,1111
		send_byte(CMD_RESET);				//�����ʾ
	
		//�������ݵ�������ָ�����
		write7279(UNDECODE+7,0x49);		//�ڵ�8λ�������뷽ʽ��ʾһ���ַ���������
		delay10ms(80);
	
		//ѭ�������Ʋ��ԣ���������������3�Σ���������3�Ρ�
		for(j=0;j<23;j++)
		{
			send_byte(RTR_CYCLE);			//ѭ������23��
			delay10ms(12);
		}
		
		for(j=0;j<23;j++)
		{
			send_byte(RTL_CYCLE);			//ѭ������23��
			delay10ms(12);
		}
	
		//���뷽ʽ0������ָ�����
		for(j=0;j<16;j++)
		{
			send_byte(RTL_UNCYL);			//��ѭ������ָ��
			write7279(DECODE0,j);			//���뷽ʽ0����ʾ�ڵ�1λ
			delay10ms(50);
		}
			delay10ms(150);
			send_byte(CMD_RESET);
	
		//���뷽ʽ1������ָ�����
		for(j=0;j<16;j++)
		{
			send_byte(RTR_UNCYL);			//��ѭ������ָ��
			write7279(DECODE1+7,j);			//���뷽ʽ1����ʾ�ڵ�8λ
			delay10ms(50);
		}
		delay10ms(150);
	
		//����ָ�����
	
		for(j=0;j<6;j++)
		{
			k=k>>1;
			write7279(ACTCTL,k);			//ÿ��һ��������һ������λ
			delay10ms(100);
		}
		write7279(ACTCTL,0xff);				//�ָ�8λ��ʾ
		delay10ms(100);
		send_byte(CMD_RESET);				//�����ʾ
	
		//�ε���ָ��Ͷιر�ָ��
		for(j=0;j<64;j++)
		{
			write7279(SEGON,j);			//��64����ʾ���������
			write7279(SEGOFF,j-1);			//ͬʱ��ǰһ����ʾ�ιر�
			delay10ms(20);
		}
	}
}




/********************************** HD7279����������� *******************************************/

void dis_data ( unsigned char dig_start,unsigned char dig_end,signed long num)
{
	unsigned char i,temp_char;
	
	for( i = dig_start; i <= dig_end; i++ )
	{
		temp_char = num % 10;
		num -= temp_char;
		num /= 10;	
		write7279 ( DECODE0 + i , 0x00 +  temp_char );//0x00Ϊ���ӵ���ʾ��0x80Ϊ�ӵ���ʾ

	}
}


//��С������ʾ��������rpλ��ʾС����
void dis_data_RP ( unsigned char dig_start,unsigned char dig_end,signed long num,int rp)
{
	unsigned char i,temp_char;
	
	for( i = dig_start; i <= dig_end; i++ )
	{
		temp_char = num % 10;
		num -= temp_char;
		num /= 10;
		if(i!=rp)
		write7279 ( DECODE0 + i , 0x00 +  temp_char );//0x00Ϊ���ӵ���ʾ��0x80Ϊ�ӵ���ʾ
		else
		write7279 ( DECODE0 + i , 0X80 +  temp_char );
	}
}/**/

signed long get_data ( signed char dig_start,signed char dig_end )
{
	signed long temp_long = 0;
	signed char i,temp_char;	
	
	for( i = dig_start; i <= dig_end; i++ )
		write7279(UNDECODE + i,0x08);  //��ʾΪ'_'
		
	for( i = dig_end; i >= dig_start ; i-- )
	{
		temp_char = get_key7279();
		
		temp_long *= 10;
		temp_long += temp_char;
		
		write7279 ( DECODE1 + i , 0x80 +  temp_char); //1���������ʾ��ĸ
	}
	delay10ms(5);
	send_byte(CMD_RESET);
		
	return temp_long;		
}
