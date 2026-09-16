void can2_init(void)
{
	PINSEL1=0X00014000;//(1<<14)->RD0 | (1<<16)->TD0
	VPBDIV=1;
	C2MOD=0X1;// To Select Reset Mode
	AFMR=0x2;// Accept all receive message
	C2BTR=0X001C001D;// 125kbps Speed data transmissioncclk->60MHZ=30-1
	C2MOD=0X00;// NORMAL MODE
	
}
void can2_tx(can2_msg m1)
{
	
	//Copy the data to buffer 1
	C2TID1=m1.id; // msg id
	C2TFI1=m1.dlc<<16;// dlc 8 bytes
	if(m1.rtr==0)
	{
		C2TFI1&=~(1<<30);// rtr=0 data frame
		C2TDA1=m1.byteA;//lower four byte of data
		C2TDB1=m1.byteB;// upper four byte of data
	}
	else
	{
		C2TFI1|=(1<<30);// remote frame
	}
	C2CMR=(1<<0)|(1<<5);//start tramsmission & slect txbuffer 1
	while(((C2GSR>>3)&1)==0);// wait for transmission complete
}
void can2_rx(can2_msg *m1)
{
	
		while((C2GSR&1)==0);
	m1->id=C2RID;
	m1->dlc=((C2RFS>>16)&0XF);
	m1->rtr=(C2RFS>>30)&0x1;
	if(m1->rtr==0){ //if data frame
		m1->byteA=C2RDA;
		m1->byteB=C2RDB;
	}
	C2CMR=(1<<2);//free receiver buffer(imp)
	
}
