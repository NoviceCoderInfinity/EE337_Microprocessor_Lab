#include <at89c5131.h>
#include <math.h>
#include "lcd.h"

code unsigned char display_msg1[]="     Input 1:   ";		
code unsigned char display_msg2[]="     Input 2:   ";	
code unsigned char display_msg3[]="   Prediction:  ";	
code unsigned char display_msg4[]="     Class 1    ";	
code unsigned char display_msg5[]="     Class 2    ";	

code unsigned char display_msg6[]="P(Class 1)=";
code unsigned char display_msg7[]="P(Class 2)=";

void main(){
	int w_0 = -36, w_1 = 5, w_2 = 7;
	int x_1 = 0, x_2 = 0; int y = 0;
	int class = 0;
	float z = 0;
	
	P1 = 0x0F;
	lcd_init();
	lcd_cmd(0x80);													
	msdelay(4);
	lcd_write_string(display_msg1);
	msdelay(10000);
	x_1=P1 &0x0f;
	
	lcd_cmd(0x01);
	
	msdelay(4);
	lcd_cmd(0x02);													
	msdelay(4);
	lcd_write_string(display_msg2);
	msdelay(10000);
	x_2=P1 & 0x0f;
	
	
	y = w_0 + (x_1*w_1) + (x_2*w_2);
	
	z = exp(-y);
	z = z + 1;
	z = 1/z;
	lcd_cmd(0x01);
	msdelay(4);
	lcd_cmd(0x80);
	msdelay(4);
	lcd_write_string(display_msg6);
	msdelay(4);
	lcd_float(z);
	
	
	lcd_cmd(0xC0);
	msdelay(4);
	lcd_write_string(display_msg7);
	msdelay(4);
	lcd_float(1-z);
	msdelay(10000);
}