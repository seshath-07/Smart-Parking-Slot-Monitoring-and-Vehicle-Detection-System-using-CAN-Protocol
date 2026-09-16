#include<lpc21xx.h>
#include"UART_header.h"
// board 33
typedef struct can2
{
	unsigned int id;
	unsigned int rtr;
	unsigned int dlc;
	unsigned int byteA;
  unsigned int byteB;
}can2_msg;
#include"can_driver1.h"

#include"4bitlcd.h"


void title(void);
volatile char slot=6;
char a[9];


int main()
{
	
	can2_msg m1;
	char str[9];
	can2_init();
	LCD_INIT();
	uart0_init(115200);
	uart0_tx_string("nodeB TESTING CAN\r\n");
	
	title();
	
	LCD_CMD(0X80);
	LCD_STR(" ***SMART PARKING*** ");
	LCD_CMD(0XC0);
	LCD_STR("TOTAL SLOT: >-6-< ");
	LCD_CMD(0X94);
	LCD_STR("AVAILABLE SLOT:");

	while(1)
	{

		LCD_CMD(0XA3);
		LCD_DATA(slot+'0');
		uart0_tx_string("waiting for read");
		can2_rx(&m1);
		uart0_tx_string("After read");

		if(m1.rtr==0)
		{
				uart0_tx_string("Enter into m1.rtr");
				uart0_tx_string("nodeB: DATA-FRAME is received\r\n");
				uart0_tx_hex(m1.id);
				uart0_tx(' ');
				uart0_tx_hex(m1.dlc);
				uart0_tx(' ');
				uart0_tx_hex(m1.byteA);
				uart0_tx(' ');
				uart0_tx_hex(m1.byteB);
	
				
	
				str[0] =  m1.byteA        & 0xFF;
				str[1] = (m1.byteA >> 8)  & 0xFF;
				str[2] = (m1.byteA >> 16) & 0xFF;
				str[3] = (m1.byteA >> 24) & 0xFF;
				
				str[4] =  m1.byteB        & 0xFF;
				str[5] = (m1.byteB >> 8)  & 0xFF;
				str[6] = (m1.byteB >> 16) & 0xFF;
				str[7] = (m1.byteB >> 24) & 0xFF;
				
				str[8] = '\0';
				
				uart0_tx_string(str);
				uart0_tx_string("\r\n");
	
				uart0_tx_string("\r\n");

			
			if(m1.id==0x150)
			{
				if(slot>0)
				slot--;
				LCD_CMD(0XD4);
				LCD_STR("GATE OPENED         ");
				LCD_CMD(0Xd4);
				delay_ms(2000);
				LCD_STR("ENTRY TIME:");
				
				LCD_CMD(0Xdf);
				LCD_STR(str);
				delay_ms(2000);
				  LCD_CMD(0XD4);
				LCD_STR("GATE CLOSED         ");
				delay_ms(2000);
			 			
			}
			if(m1.id==0x151)
			{
				if(slot<6)
				slot++;
				LCD_CMD(0XD4);
				LCD_STR("GATE OPENED         ");
				
				delay_ms(2000);
				LCD_CMD(0XD4);
				LCD_STR("EXIT  TIME:");		 
				LCD_CMD(0Xdf);
				LCD_STR(str);
				delay_ms(2000);
				LCD_CMD(0XD4);
				LCD_STR("GATE CLOSED         ");
				delay_ms(2000);
				
			}
			if(slot==0)	
			{
				LCD_CMD(0XD4);
				LCD_STR("    parking full    ");
			}
			delay_ms(2000);
			LCD_CMD(0XD4);
			LCD_STR("                    ");
			
			
		}	
		else
		{
			uart0_tx_string("nodeB: REMOTE-FRAME is received\r\n");
			uart0_tx_hex(m1.id);
			uart0_tx(' ');
			uart0_tx_hex(m1.dlc);
			uart0_tx(' ');
			uart0_tx_string("\r\n");
		}
			
		
	}
	

	
}


void title(void)
{
	 int i, j;

    char p[] ="                    SMART PARKING SLOT MONITORING AND VEHICLE DETECTION SYSTEM USING CAN PROTOCOL                    ";
    for(i = 0; p[i + 19] != '\0'; i++)
    {
        LCD_CMD(0x80);        // First line
        for(j = 0; j < 20; j++)
        {
        LCD_DATA(p[i + j]);   // Print only 20 characters
        }
	      delay_ms(250);
				
		}
				LCD_CMD(0x01);
        delay_ms(2);

        /* Display on all 4 rows */
        LCD_CMD(0x80);
        LCD_STR(" SMART PARKING SLOT ");

        LCD_CMD(0xC0);
        LCD_STR(" MONITORING and ");

        LCD_CMD(0x94);
        LCD_STR(" VEHICLE DETECTION ");

        LCD_CMD(0xD4);
        LCD_STR(" USING CAN PROTOCOL ");

        delay_ms(2000);

        // Clear and repeat 
        LCD_CMD(0x01);
        delay_ms(2);
}
