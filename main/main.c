//ICC-AVR application builder : 2014/7/22 19:16:57
// Target : M16
// Crystal: 7.3728Mhz

#include "../Headers/Includes.h"

#define Max_note      100
#define Max_note_1    126     
#define Max_note_2    338
#define Max_note_3    120
#define Max_note_4    112

unsigned int note_n = 0;
unsigned int int_n = 0;
INT16U distance_mm = 0;//距离
unsigned char play_on = 0;
int LED_N = 0;

int song=0;
int song_note = 0;
unsigned char *song_music;

void LEDOnBoardInit(void)
{
    DDRC |= (0x01<<6)|(0x01<<7);
	//PORTC |= (0x01<<6)|(0x01<<7);
	PORTC &= ~((0x01<<6)|(0x01<<7));
}
void SET_LED_D10(unsigned char state)
{
 	PORTC = PORTC&(~(0X01<<6))|(state<<6);
}
void SET_LED_D11(unsigned char state)
{
 	PORTC = PORTC&(~(0X01<<7))|(state<<7);
}
unsigned int t[28] = {0,3824,3460,3036,2864,2552,2272,2024,0,0,0,     //中音0-7
                        1880,1702,1517,1431,1275,1136,1012,0,0,0,     //高音11-17   频率
						7633,6802,6060,5730,5102,4545,4048};          //低音21-27
						
unsigned int d[28] = {0, 105, 116, 132, 140, 157, 176, 198,0,0,0,     //中音0-7
                         209, 234, 263, 279, 313, 352, 395,0,0,0,     //高音11-17   节拍
						  52,  58,  66,  70,  78,  88,  98};          //低音21-27

unsigned char music[Max_note] = { 5,4, 5,4, 6,8, 5,8,11,8, 7,16,
                                  5,4, 5,4, 6,8, 5,8,12,8,11,16,
								  5,4, 5,4,15,8,13,8,11,8, 7,8, 6,16,
								 14,4,14,4,13,8,11,8,12,8,11,16,
								 5,4, 5,4, 6,8, 5,8,11,8, 7,16,
                                  5,4, 5,4, 6,8, 5,8,12,8,11,16,
								  5,4, 5,4,15,8,13,8,11,8, 7,8, 6,16,
								 14,4,14,4,13,8,11,8,12,8,11,16};//祝你生日快乐100
unsigned char music_1[Max_note_1] = { 3,4, 3,4, 4,4, 5,4, 5,4, 4,4, 3,4, 2,4, 1,4, 1,4, 2,4, 3,4, 3,6, 2,2, 2,8,  
                                     3,4, 3,4, 4,4, 5,4, 5,4, 4,4, 3,4, 2,4, 1,4, 1,4, 2,4, 3,4, 2,6 ,1,2, 1,8,
								     2,4, 2,4, 3,4, 1,4, 2,4, 3,2, 4,2, 3,4, 1,4, 2,4, 3,2, 4,2, 3,4, 2,4, 1,4,
								     2,4,25,4, 3,8, 3,4, 4,4, 5,4, 5,4, 4,4, 3,4, 4,2, 2,2, 1,4, 1,4, 2,4, 3,4,
								     2,6, 1,2, 1,4};//欢乐颂126

unsigned char music_2[Max_note_2] = {15,4, 13,2, 14,2, 15,4, 13,2, 14,2, 15,2,  5,2,  6,2,  7,2, 11,2, 12,2, 13,2, 14,2,
                                     13,4, 11,2, 12,2, 13,4,  3,2,  4,2,  5,2,  6,2,  5,2,  4,2,  5,2,  3,2,  4,2,  5,2,
								      4,4,  6,2,  5,2,  4,4,  3,2,  2,2,  3,2,  2,2,  1,2,  2,2,  3,2,  4,2,  5,2,  6,2,
								      4,4,  6,2,  5,2,  6,4,  7,2, 11,2,  5,2,  6,2,  7,2, 11,2, 12,2, 13,2, 14,2, 15,2,
								  
								     15,4, 13,2, 14,2, 15,4, 13,2, 14,2, 15,2,  5,2,  6,2,  7,2, 11,2, 12,2, 13,2, 14,2,
                                     13,4, 11,2, 12,2, 13,4,  3,2,  4,2,  5,2,  6,2,  5,2,  4,2,  5,2, 11,2,  7,2, 11,2,
								      6,4, 11,2,  7,2,  6,4,  5,2,  4,2,  5,2,  4,2,  3,2,  4,2,  5,2,  6,2,  7,2, 11,2,
								      6,4, 11,2,  7,2, 11,4,  7,2, 11,2,  7,2,  6,2,  7,2, 11,2, 12,2, 13,2, 14,2, 15,2,
								  
								     13,4, 11,2, 12,2, 13,4, 12,2, 11,2, 12,2,  7,2, 11,2, 12,2, 13,2, 12,2, 11,2,  7,2,
								     11,4,  6,2,  7,2, 11,4,  1,2,  2,2,  3,2,  4,2,  3,2,  2,2,  3,2, 11,2,  7,2, 11,2,
								      6,4, 11,2,  7,2,  6,4,  5,2,  4,2,  5,2,  4,2,  3,2,  4,2,  5,2,  6,2,  7,2, 11,2,
								      6,4, 11,2,  7,2, 11,4,  7,2,  6,2,  7,2, 11,2, 12,2, 11,2,  7,2, 11,2,  6,2,  7,2, 
								     11,8};//卡农338 


unsigned char music_3[Max_note_3] = { 5,8,  3,4,  5,4, 11,16,  6,8, 11,8,  5,16, 5,8,  1,4, 2,4, 3,8,   2,4,   1,4,  2,32, 5,8,
                                      3,4,  5,4, 11,12, 7,4,   6,8, 11,8,  5,16, 5,8,  2,4, 3,4, 4,12, 27,4,   1,16, 1,16, 6,8,
								     11,8, 11,16, 7,8,  6,4,   7,4, 11,16, 6,4,  7,4, 11,4, 6,4, 6,4,   5,4,   3,4,  1,4,  2,32, 
								      5,8,  3,4,  5,4, 11,12,  7,4,  6,8, 11,8,  5,16, 5,8, 2,4, 3,4,   4,12, 27,4,  1,16, 1,16,};
								     //送别120

unsigned char music_4[Max_note_4] = {25,6, 1,9, 1,3, 1,6, 3,6, 2,9, 1,3, 2,6, 3,6, 1,9,  1,3,  3,6,  5,6, 6,18,
                                      6,6, 5,9, 3,3, 3,6, 1,6, 2,9, 1,3, 2,6, 3,6, 1,9, 26,3, 26,6, 25,6, 1,18,
									  6,6, 5,9, 3,3, 3,6, 1,6, 2,9, 1,3, 2,6, 6,6, 5,9,  3,3,  3,6,  5,6, 6,18,
									 11,6, 5,9, 3,3, 3,6, 1,6, 2,9, 1,3, 2,6, 3,6, 1,9, 26,3, 26,6, 25,6, 1,18};
								     //友谊地久天长112


void port_init(void)
{
 PORTA = 0x00;
 DDRA  = 0x00;
 PORTB = 0x00;
 DDRB  = 0x00;
 PORTC = 0x00; //m103 output only
 DDRC  = 0x00;
 PORTD = 0x00;
 DDRD  = 0x00;
 }
 
/**/
//TIMER2 initialize - prescale:Stop
// WGM: CTC
// desired value: 1Hz
// actual value: Out of range
void timer2_init(void)
{
 TCCR2 = 0x00; //stop
 ASSR  = 0x00; //set async mode
 TCNT2 = 0x00 ; //setup
 OCR2  = 0x00 ;
 TCCR2 = 0x18; //start
}

//32分频的情况下调试成功，晶振为7.3728MHz
#pragma interrupt_handler timer2_comp_isr:iv_TIM2_COMP
void timer2_comp_isr(void)
{
 //compare occured TCNT2=OCR2
 if (!play_on)
 {
  note_n = 0;
  int_n = 1;
  play_on = 1;
  DDRD  |= (1<<7);
 }
else
 {    
  if (--int_n == 0)
  {
   TCCR2 = 0x18;
   if (note_n < song_note)                        //祝你生日快乐
      {
       OCR2 = (t[song_music[note_n]]/30);	    //2KHz频率，在1M内部晶振下。OCR2为8位寄存器
       int_n = d[song_music[note_n]]/1.25;        //时间长短，主频越高，乘以越大的系数
       note_n++;
       int_n = int_n * song_music[note_n];
       note_n++;         
	   
	   //设置LED随着音乐进行变化
	   LED_N = note_n/16;
	   switch(LED_N%2)
	   {
	    case 0:
		{
		 PORTB |= 0xFF;
		 PORTB &= ~(1<<((note_n-16*LED_N)/2));
		 PORTD |= 0XFF;
		};break;
		case 1:
		{
		 PORTB |= 0xFF;
		 PORTD |= 0XFF;
		 PORTD &= ~(1<<((note_n-16*LED_N)/2));
		};break;		
		default: break;
	   }
	   
	  // TCCR2 = 0x1B;//32分频
	   TCCR2 = 0x1C;//128分频 
      }
    else
      {
       play_on = 0;
       DDRD  &= ~(1<<7);
      }		   
  }
 }  
}

//call this routine to initialize all peripherals
void init_devices(void)
{
 //stop errant interrupts until set up
 CLI(); //disable all interrupts
 port_init(); 
 LEDOnBoardInit();
 init_7279(); 
 timer2_init();
  
 MCUCR = 0x00;
 GICR  = 0x00;
 TIMSK = 0x80; //timer interrupt sources
 SEI(); //re-enable interrupts
 //all peripherals are now initialized
}

void main(void)
{
  int temp,temp_yz;
  int CH;
  int led=0; 
  init_devices();
  Delay_ms(20);      
  

  /*
  */
  CH = get_data(0,0);
 // CH = 7;
  switch (CH)
  {
   case 0://LED模式
     {	  
	  DDRB = 0xFF;
      PORTB = 0XFF;
      DDRD = 0XFF;
	  PORTD = 0XFF;
      
	  while(1)
	  {
	   if(led<8)
	   {
	    PORTD = 0XFF;
		PORTB = ~(1<<led);
		Delay_ms(200);
		led++;
	   }
	   else if((led>=8)&&(led<16))
	   {
	    PORTB = 0XFF;
		PORTD = ~(1<<(led-8));
		Delay_ms(200);
		led++;
	   }
	   else
	   {
	    led=0;
	   } 
	  }	   
	 };
	 break;
	 
   case 2://蜂鸣器模式
   
   
	 
   case 4://温度传感器模式，显示温度值
     {
	  dis_data(7,7,4);
	  DS18B20Init();
	  while(1)
	  {
	   temp=gettemp();//读取到的温度数据
       Delay_ms(100);
   
       if(temp >= 0xf800)//如果为零下，求补码
       {
        temp = temp - 0XF800;   //去掉5个符号位
	    temp = 0x800 - temp;    //求出补码
	    temp = (temp*6.25)/10;  //计算温度值，应该乘0.0625，现在乘0.625可以显示一位小数位
	    temp = (1000*16)+temp;	//在最高位显示负号
	   }
       else
       {
        temp = (temp*6.25)/10;//如果为正，补码为它本身，直接转换为温度值进行显示		
       }    
	   dis_data_RP(0,3,temp,1);//显示温度值	   
	  }	   
	 };
	 break;
	 
	 case 5://温度传感器模式，显示温度值
     {
	     HC_SR04_Init();
		 CLI();
		 timer1_init();
		 MCUCR = 0x00;
 		 GICR  = 0x00;
 		 TIMSK |= (0x01<<2); //溢出中断使能
		 SEI();
		 while(1)
		 {
		     
		     distance_mm = (INT16U)GetDistance();//单位mm
			 dis_data(0,3,distance_mm);
			 Delay_ms(100);
		 }
	 }
	 
	 case 6:
	 {
 		 MH_B_Init();
		 SET_LED_D11(1);
		 Delay_ms(100);
	     while(1)
  		 {
      	    if(!Read_MH_B())
	  		{
          	   SET_LED_D11(1);
		   	   Delay_ms(20);
	  		}
	  		SET_LED_D11(0);
  	     }
	 };
	 case 7:
	 {	  	  
	     FC04Init();
		 SET_LED_D10(1);
		 Delay_ms(100);
	     while(1)
  		 {
      	   if(!Read_FC04())
	  	   {
             SET_LED_D10(1);
		  	 Delay_ms(20);
	       }
	  	   SET_LED_D10(0);
  		 }
	 };
	 break;
	 
	 case 8:
	 {	  	  
	     MQ2_Init();
		 Delay_ms(100);
	     while(1)
  		 {
      	   if(!Read_MQ2_DO())
	  	   {
             SET_LED_D10(1);
		  	 Delay_ms(20);
	       }
		   dis_data(0,3,Read_MQ2_AO());
	  	   SET_LED_D10(0);
  		 }
	 };
	 break;
	 
	 case 13://d 温度报警模式，设置阈值温度，超过温度进行报警
     {
	  DS18B20Init();
	  temp_yz = get_data(0,2);//温度阈值
	  temp_yz = temp_yz*10;	  
	  
	  while(1)
	  {
	   temp=gettemp();//读取到的温度数据
       Delay_ms(100);
	   
       if(temp >= 0xf800)//如果为零下，求补码
       {
        temp = temp - 0XF800;   //去掉5个符号位
	    temp = 0x800 - temp;    //求出补码
	    temp = (temp*6.25)/10;  //计算温度值，应该乘0.0625，现在乘0.625可以显示一位小数位
	    temp = (1000*16)+temp;	//在最高位显示负号
	   }
       else
       {
        temp = (temp*6.25)/10;//如果为正，补码为它本身，直接转换为温度值进行显示		
       }/**/   	   
  
       if(temp > temp_yz)
	   {
	    PORTC |= (1<<6);PORTC |= (1<<7);	   
	   }
	   else if(temp <= temp_yz)
	   {
	    PORTC &= ~(1<<7);PORTC &= ~(1<<6);
	   }	   
	    
	   dis_data_RP(0,3,temp,1);//显示温度值	  
	   dis_data_RP(4,7,temp_yz,5);	   
	  }	   
	 };
	 break;
	 default: break;
  }
  
}
