void i2c_init(void)
{
	PINSEL0|=0x00000050;
	I2SCLL=75;
	I2SCLH=75;
	I2CONSET=1<<6;
}
void i2c_start(void)
{
   I2CONSET=1<<5;
   while(((I2CONSET>>3)&1)==0);
   I2CONCLR=1<<5;
}
void i2c_stop(void)
{
   I2CONSET=1<<4;
   I2CONCLR=1<<3;
}
void i2c_write(char data)
{
	I2DAT=data;
	I2CONCLR=1<<3;
	while(((I2CONSET>>3)&1)==0);
}
void i2c_restart(void)
{
 	I2CONSET=1<<5;
	I2CONCLR=1<<3;
	while(((I2CONSET>>3)&1)==0);
	I2CONCLR=1<<5;
}
char i2c_nack(void)
{
	I2CONCLR=1<<3;
	while(((I2CONSET>>3)&1)==0);
	return I2DAT;
}
char i2c_masterack(void)
{
 	  I2CONSET=1<<2;
	  I2CONCLR=1<<3;
	  while(((I2CONSET>>3)&1)==0);
	  I2CONCLR=1<<2;
	  return I2DAT;
}
