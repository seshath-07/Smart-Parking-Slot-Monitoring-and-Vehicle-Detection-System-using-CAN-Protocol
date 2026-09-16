/*******DELAY FOR SECONDS*******/
void delay_sec(unsigned int i)
{
	T0PR=60000000-1;
	T0TCR=0X01;
	while(T0TC<i);
	T0TCR=0X03;
	T0TCR=0X00;
}
/*******DELAY FOR MILLI SECONDS*******/
void delay_ms( int i)
{
	T0PR=60000-1;
	T0TCR=0X01;
	while(T0TC<i);
	T0TCR=0X03;
	T0TCR=0X00;
}
/*******DELAY FOR MICRO SECONDS*******/
void delay_Msec(unsigned int i)
{
	T0PR=60-1;
	T0TCR=0X01;
	while(T0TC<i);
	T0TCR=0X03;
	T0TCR=0X00;
}
