#include"UART_header.h"
void delay_mills(unsigned int ms)
{
    T0PR = 60000 - 1;
    T0TCR =0x01;
    while(T0TC < ms);
    T0TCR =0x03;
	T0TCR=0x00;
}
int x = (1000 * 60) - 1;
int flag=0;

void pwm_init(void)
{
   	PINSEL1 |= 1 << 10;  
	VPBDIV=1;           // P0.21 -> PWM5
	PWMMR0 = (20000 * 60) - 1;     // 20 ms period
    PWMMR5 = x;
	PWMMCR = 2;
    PWMPCR = 1 << 13;
    PWMTCR = 0x09;
    PWMLER = (1<<0)|(1<<5);
}
void gate(void)
{
uart0_tx_string("inside gate  ");

   			while(1)
            {
                PWMMR5 = x;
                PWMLER = 1<<5;

                delay_mills(100);

                x = x + (56 * 60);      // Step for 15 MHz

                if(flag)
                {
                    flag = 0;
                    return ;
                }

                if(x > ((2100 * 60) - 1))
                {
                    x = (1000 * 60) - 1;
                    flag = 1;
                    delay_mills(3000);
                }
            }

}
	
