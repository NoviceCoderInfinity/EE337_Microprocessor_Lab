#include <at89c5131.h>
#include "lcd.h"

code unsigned char display_msg1[]="     Input 1:   ";		
code unsigned char display_msg2[]="     Input 2:   ";	
code unsigned char display_msg3[]="   Prediction:  ";	
code unsigned char display_msg4[]="     Class 1    ";	
code unsigned char display_msg5[]="     Class 2    ";	

void main(){
	int w_0 = -36, w_1 = 5, w_2 = 7;
	int x_1 = 0, x_2 = 0; int y = 0;
	int class = 0;
	
	P1 = 0x0F;
	lcd_init();
	lcd_cmd(0x80);													
	msdelay(4);
	lcd_write_string(display_msg1);
	msdelay(10000);
	x_1=P1;
	
	lcd_cmd(0x01);
	
	msdelay(4);
	lcd_cmd(0x02);													
	msdelay(4);
	lcd_write_string(display_msg2);
	msdelay(10000);
	x_2=P1;
	
	lcd_cmd(0x01);
	msdelay(4);
	lcd_write_string(display_msg3);
	
	y = w_0 + (x_1*w_1) + (x_2*w_2);
	if(y<0) {
		class = 1;
		lcd_cmd(0xC0);
		msdelay(4);
		lcd_write_string(display_msg4);
		msdelay(10000);
	} else if(y>=0) {
		class = 2;
		lcd_cmd(0xC0);
		msdelay(4);
		lcd_write_string(display_msg5);
		msdelay(100000);
	}
}