#include <at89c5131.h>
#include "lcd.h"

code unsigned char display_msg1[]= "RES1:";
code unsigned char display_msg2[]= "TIME1:";
code unsigned char display_msg3[]="us   ";
long unsigned int x=14571;
long unsigned int y=8636;
long unsigned int x0;
long unsigned int x1;
long unsigned int y0;
long unsigned int y1;
long unsigned int z0;
long unsigned int z1;
long unsigned int z2;
long unsigned int z3;
long unsigned int z;
int i;
int count;
unsigned char show[5];
unsigned char res[9];
void main(void)
{
	
	lcd_init();
	TMOD = 0x10;  //Configure TIMER 1 in Mode 1 
	TH1=0x00;					//Initialize the upper and lower counts with 00
	TL1=0x00;
	TR1=1;			//Start the TIMER1
	x1=x/10;     
	x0=x%10;    
	y1=y/10;			
	y0=y%10;
	z0=x0*y0;    
	z1=x0*y1; 		
	z2=x1*y0;
	z3=x1*y1;
	z = z0 +(z1 +z2)*10 + z3*100;

	TR1=0;													//STOP the timer1
	count = (0x0100)*TH1 + TL1;			//Caculating total number of counts
	count = count * 0.5;						//EACH COUNT TAKES 0.5 MICROSECONDS
	for(i=0;i<=4;i++)		
	{
		show[4-i] = (count%10) + 48;			//Storing the count in array 
		count = count /10;
	}
	for(i=0;i<9;i++)
	{
		res[8-i]=(z%10) + 48;					//storing the result in the array 
		z = z/10;
	}
	
	lcd_cmd(0x80);
	lcd_write_string(display_msg1);
	lcd_cmd(0x86);
	lcd_write_string(res);					//Displaying the result 
	lcd_cmd(0xC0);
	lcd_write_string(display_msg2);
	lcd_cmd(0xC7);
	lcd_write_string(show);					//Displaying the time taken
	lcd_cmd(0xCC);
	lcd_write_string(display_msg3);
   msdelay(4000);
}
