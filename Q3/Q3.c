#include <at89c5131.h>
#include "lcd.h"
#include <math.h>

code unsigned char display_msg1[]="     Input 1:   ";						//Display msg on 1st line of lcd
code unsigned char display_msg2[]="     Input 2:   ";	
code unsigned char display_msg3[]="P(Class 1):";	
code unsigned char display_msg4[]="P(Class 2):";	
code unsigned char display_msg5[]="     Class 2    ";	



void main()
{
	int a_=0;
	int b_=0;
	int c_=0;
	int w0= -36;
	int w1= 5;
	int w2=7;
	int x1=0;
	int x2=0;
	int y=0;
	float z=0;
	int class=0;
	int t=0;
	P1=0x0F;
	lcd_init();
	lcd_cmd(0x80);													//Move cursor to first line
	msdelay(4);
	lcd_write_string(display_msg1);
	msdelay(10000);
	x1=P1;
	lcd_cmd(0x01);//clear screen
	msdelay(4);
	lcd_cmd(0x02);//move cursor to first position
	msdelay(4);
	lcd_write_string(display_msg2);
	msdelay(10000);
	x2=P1;
	y=w0+(x1*w1)+(x2*w2);
	z=(1/(1+exp(-y)));
	t=(1-z)*1000;
	a_=t/100;
	b_=((t%100)/10);
	c_=t%10;
	lcd_cmd(0x01);//clear screen
	msdelay(4);
	lcd_cmd(0x02);//move cursor to first position
	msdelay(4);
	lcd_write_string(display_msg3);
	msdelay(4);
	lcd_float(a_+48,b_+48,c_+48);
	msdelay(4);
	lcd_cmd(0xC0);													//Move cursor to 2nd line of LCD
	msdelay(4);
	lcd_write_string(display_msg4);
	msdelay(4);
	t=(z)*1000;
	a_=t/100;
	b_=((t%100)/10);
	c_=t%10;
	lcd_float(a_+48,b_+48,c_+48);
	msdelay(10000);

	
}
