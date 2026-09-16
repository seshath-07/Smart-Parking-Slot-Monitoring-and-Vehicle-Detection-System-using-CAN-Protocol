#include<lpc21xx.h>
#include"rtcmain.h"
// board no :20
#define sw1 8
#define sw2 9
 

typedef struct can2
{
	unsigned int id;
	unsigned int rtr;
	unsigned int dlc;
	unsigned int byteA;
  	unsigned int byteB;
}can2_msg;
#include"can_driver1.h"
#include"UART_header.h"

int main()
{ 										 

	char a[9];
	char i=0;
	can2_msg m1,m2;
	IODIR0=1<<0;
	
	can2_init();
	LCD_INIT();
	i2c_init();

	while(1)
	{		//sending data frame
		IOSET0=1<<0;
		
		LCD_CMD(0x80);
		LCD_STR("waiting...");
		if(((IOPIN0>>sw1)&1)==0)
		{	
			uart0_tx_string("sw1");
			LCD_CMD(0x01);
			delay_ms(2);
			delay_ms(250);
			IOCLR0=1<<0;
			realtime(a);
			
			LCD_CMD(0x94);
			LCD_STR(a);
			
			LCD_CMD(0xc0);
			LCD_STR("  CAR ENTERED  ");
			uart0_tx_string("before tramsnit");
			m1.id=0x150;
			m1.rtr=0;//data frame
			m1.dlc=8;// 8 byte
			i=0;
			m1.byteA=a[i]|a[i+1]<<8|a[i+2]<<16|a[i+3]<<24;
			m1.byteB=a[i+4]|a[i+5]<<8|a[i+6]<<16|a[i+7]<<24;
			can2_tx(m1);
			delay_ms(250);
			uart0_tx_string("after tramsmit");
		//while(((IOPIN0>>sw1)&1)==0);
			uart0_tx_string(" tramsnit");
			uart0_tx_string("sw1");
				delay_ms(3000);
			 LCD_CMD(0x01);
				
		}
	
		
		if(((IOPIN0>>sw2)&1)==0)
		{	
			uart0_tx_string("sw2");
			
			delay_ms(250);
			LCD_CMD(0x01);
			delay_ms(2);
			IOCLR0=1<<0;
			realtime(a);
			LCD_CMD(0x94);
			LCD_STR(a);
			LCD_CMD(0xc0);
			LCD_STR(" CAR EXITED");
			uart0_tx_string("before tramsnit");
			m2.id=0x151;
			m2.rtr=0;//data frame
			m2.dlc=8;// 8 byte
			i=0;
			m2.byteA=a[i]|a[i+1]<<8|a[i+2]<<16|a[i+3]<<24;
			m2.byteB=a[i+4]|a[i+5]<<8|a[i+6]<<16|a[i+7]<<24;
			can2_tx(m2);
			delay_ms(250);
			uart0_tx_string("After tramsnit");
		//	while(((IOPIN0>>sw2)&1)==0);	
			uart0_tx_string(" tramsnit");
			uart0_tx_string("sw2");
				delay_ms(3000);
				LCD_CMD(0x01);
		}
	
	}
	
}
