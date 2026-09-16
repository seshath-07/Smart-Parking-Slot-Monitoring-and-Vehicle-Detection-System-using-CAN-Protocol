#include<lpc21xx.h>
#include<string.h>
#include<stdio.h>
#include"4bitlcd.h"
#include"i2c.h"

char a[20];
char i2c_rtc_read(char slaveAddr,char wordAddr);
void i2c_rtc_write(char slaveAddr,char wordAddr,char data);

int main()
{
	char mode;
	char sec,min,hour;
	i2c_init();
	LCD_INIT();
	
	i2c_rtc_write(0x68,0x00,0x56);	//seconds
	i2c_rtc_write(0x68,0x01,0x31);  // minutes	// 6th bit 0->24 hour formate1->12 hour formate
	i2c_rtc_write(0x68,0x02,0x73);	//hours with select 5th bit (0->AM/1->PM )
	
while(1){	
	sec=i2c_rtc_read(0x68,0x00);
	min=i2c_rtc_read(0x68,0x01);
	hour=i2c_rtc_read(0x68,0x02);

	mode=hour;
	
	sec=(((sec>>4)*10)+(sec&0x0f));
	min=(((min>>4)*10)+(min&0x0f));
	hour=((((hour>>4)&1)*10)+(hour&0x0f));

	sprintf(a,"%02d:%02d:%02d",hour,min,sec);

	
	LCD_CMD(0x80);
	LCD_STR("                "); // 16 spaces
	LCD_CMD(0x80);
	LCD_STR(a);

	if(((mode>>5)&1)==1){
	LCD_CMD(0x89);
	LCD_STR(" PM") ;
	}
	else
	{
	LCD_CMD(0x89);
	LCD_STR(" AM");
	}
	delay_ms(500);
 }

}
 void i2c_rtc_write(char slaveAddr,char wordAddr,char data)
{
	i2c_start();
	i2c_write(slaveAddr<<1); // slave address + write
	i2c_write(wordAddr);  // word address
	i2c_write(data);   // data
	i2c_stop();
	delay_ms(10);// for eeprom internal operation to store the data
	             // into non volatile memory
}
char i2c_rtc_read(char slaveAddr,char wordAddr)
{
	char data;
	i2c_start();
	i2c_write(slaveAddr<<1);
	i2c_write(wordAddr);
	i2c_restart();
	i2c_write((slaveAddr<<1)|1);
	data=i2c_nack();
	i2c_stop();
	return data;
}
