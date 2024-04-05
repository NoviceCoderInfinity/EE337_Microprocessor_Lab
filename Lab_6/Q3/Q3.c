#include <at89c5131.h>

/*

Two frequency simultaneously with timers in interrupts mode.

First LED1 time period is 2ms.
Second LED2 time period is 3ms.

*/
sbit LED=P0^7;
int count =0;

void timer1_isr () interrupt 3
{
	TH1 =  0x9e;
	TL1 =  0x58;
	count++;
   //Reload values for TH0 and TL0. Start timer 0.

}


void sa_l()
{		LED=1;TF0 = 0;
		TH0 = 0xef;
		TL0 = 0xb9;
		TR0 = 1;
		while(!TF0);
	LED=0;TF0 = 0;
		TH0 = 0xef;
		TL0 = 0xb9;
		TR0 = 1;
		while(!TF0);
}
void re()
{	LED = 1;	TF0 = 0;
		TH0 = 0xf1;
		TL0 = 0x88;
		TR0 = 1;
		while(!TF0);
LED = 0;	TF0 = 0;
		TH0 = 0xf1;
		TL0 = 0x88;
		TR0 = 1;
		while(!TF0);
}
void ga()
{		LED = 1;TF0 = 0;
		TH0 = 0xf2;
		TL0 = 0xfa;
		TR0 = 1;
		while(!TF0);
LED = 0;TF0 = 0;
		TH0 = 0xf2;
		TL0 = 0xfa;
		TR0 = 1;
		while(!TF0);
}
void ma()
{		LED = 1;TF0 = 0;
		TH0 = 0xf3;
		TL0 = 0xcb;
		TR0 = 1;
		while(!TF0);
LED = 0;TF0 = 0;
		TH0 = 0xf3;
		TL0 = 0xcb;
		TR0 = 1;
		while(!TF0);
}
void pa()
{		LED = 1;TF0 = 0;
		TH0 = 0xf5;
		TL0 = 0x26;
		TR0 = 1;
		while(!TF0);
LED = 0;TF0 = 0;
		TH0 = 0xf5;
		TL0 = 0x26;
		TR0 = 1;
		while(!TF0);
}
void dha()
{		
LED = 1;
TF0 = 0;
		TH0 = 0xf6;
		TL0 = 0x3c;
		TR0 = 1;
		while(!TF0);
LED = 0;
TF0 = 0;
		TH0 = 0xf6;
		TL0 = 0x3c;
		TR0 = 1;
		while(!TF0);
}
void ni()
{
LED = 1;		
TF0 = 0;
		TH0 = 0xf7;
		TL0 = 0x51;
		TR0 = 1;
		while(!TF0);
LED = 0;		
TF0 = 0;
		TH0 = 0xf7;
		TL0 = 0x51;
		TR0 = 1;
		while(!TF0);
}
void sa_h()
{		
		LED = 1;
		TF0 = 0;
		TH0 = 0xf7;
		TL0 = 0xdc;
		TR0 = 1;
		while(!TF0);
		
		LED = 0;
		TF0 = 0;
		TH0 = 0xf7;
		TL0 = 0xdc;
		TR0 = 1;
		while(!TF0);

}	

//Main function
void main(void)
{
	TMOD = 0x11; //mode 1 timer 0 and timer 1
	ET1 = 1;
	EA = 1;  //activate global interrupts
	TR1 = 1; //start timer 1
	while(1)
	{
		while(count < 40){sa_l();}
		
		while(count <100){re();}
		
		while( count<180){ga();}
	
		while( count<220){ma();}
		
		while( count<300){pa();}
		
		while( count<360){dha();}

		while( count<440){ni();}

		while( count<480){sa_h();}
		count = 0;
	}
	
	
	while(1);
}
