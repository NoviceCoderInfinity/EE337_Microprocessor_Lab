#include <at89c5131.h>
#include "lcd.h"

code unsigned char display_msg1[]="InstiKaBaap    ";						//Display msg on 1st line of lcd
code unsigned char display_msg2[]="Kaun__H5__H5   ";						//Display msg on 1st line of lcd

void main()
{
	lcd_init();
	lcd_cmd(0x80);													//Move cursor to first line
	msdelay(4);
	lcd_write_string(display_msg1);
	lcd_cmd(0xC0);													//Move cursor to 2nd line of LCD
	msdelay(4);
	lcd_write_string(display_msg2);
	while(1);
		
}