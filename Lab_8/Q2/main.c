/**********************************************************
EE337: ADC IC MCP3008 interfacing with pt-51
(1) Complete spi_init() function from spi.h 

***********************************************************/

#include <at89c5131.h>
#include "lcd.h"																				//Driver for interfacing lcd 
#include "mcp3008.h"																		//Driver for interfacing ADC ic MCP3008


char adc_ip_data_ascii_1[6]={0,0,0,0,0,'\0'};							//string array for saving ascii of input sample
char adc_ip_data_ascii_2[6]={0,0,0,0,0,'\0'};							//string array for saving ascii of input sample
code unsigned char display_msg1[]="Volt.: ";						//Display msg on 1st line of lcd
code unsigned char display_msg2[]=" mV";								//Display msg on 1st line of lcd

code unsigned char display_msg3[]="Temp.: ";						//Display msg on 2nd line of lcd
code unsigned char display_msg4[]=" °C";								//Display msg on 2nd line of lcd


void main(void)
{
	int j=0;
	unsigned int adc_data_1 = 0;
	unsigned int adc_data_2 = 0;
	
	spi_init();																					
	adc_init();
  lcd_init();
	
	while(1)	{
	 	unsigned int x;
		unsigned int y	;
		 
		x = adc(4);																					//Read analog value from 4th channel of ADC Ic MCP3008
		y = adc(3);
		
		adc_data_1 = (unsigned int) (x*3.2258);
		adc_data_2 = (unsigned int) (y*3.2258);							//Converting received 10 bits value to milli volt (3.3*1000*i/p /1023)

		/*
		    Display "Volt: " on first line of lcd
		    Print analog sampled input on lcd using int_to_string function and 
		    Display "XXXXX mV" on second line of LCD
		
		*/	
		int_to_string(adc_data_2, adc_ip_data_ascii_2);
		int_to_string(adc_data_2, adc_ip_data_ascii_1);
		
		lcd_cmd(0x01);
		lcd_cmd(0x80);
		
		lcd_write_string(display_msg1);
		lcd_write_string(adc_ip_data_ascii_1);
		lcd_write_string(display_msg2);
		
		lcd_cmd(0xC0);
		lcd_write_string(display_msg3);
		lcd_write_char(adc_ip_data_ascii_1[2]);
		lcd_write_char(adc_ip_data_ascii_1[3]);
		lcd_write_char('.');
		lcd_write_char(adc_ip_data_ascii_1[4]);
		lcd_write_string(display_msg4);
		
		msdelay(300);
	}
}