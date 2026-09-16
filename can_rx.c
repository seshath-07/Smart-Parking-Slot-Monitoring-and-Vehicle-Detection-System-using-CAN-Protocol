#include<lpc21xx.h>

// board 07
typedef struct can2
{
	unsigned int id;
	unsigned int rtr;
	unsigned int dlc;
	unsigned int byteA;
  unsigned int byteB;
}can2_msg;
#include"candriver2.h"
#include"UART_header.h"
int main()
{
	
	can2_msg m1;
	char str[9];
	can2_init();
	uart0_init(115200);
	uart0_tx_string("nodeB TESTING CAN\r\n");
	while(1)
	{
		can2_rx(&m1);
	

		if(m1.rtr==0){
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
		}	
		else{
			uart0_tx_string("nodeB: REMOTE-FRAME is received\r\n");
			uart0_tx_hex(m1.id);
			uart0_tx(' ');
			uart0_tx_hex(m1.dlc);
			uart0_tx(' ');
			uart0_tx_string("\r\n");
		}
			
		
	}
	

	
}
