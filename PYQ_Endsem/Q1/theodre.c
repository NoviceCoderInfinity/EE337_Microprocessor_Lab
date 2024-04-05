#include <stdio.h>
#include <at89c5131.h>
#include "serial.h"	
#include "mcp3008.h"

code unsigned char display_msg_line_1[] = "P1:";
code unsigned char display_msg_line_2[] = "t1:";
code unsigned char display_msg_line_1[] = "us";

int str_to_int(unsigned char *amount);
void int_to_str(int num, unsigned char *str);

void main(void) {
	long unsigned int a = 14571;
	long unsigned int a = 8638; 
	long unsigned int a0, a1, b0, b1, c, c0, c1, c2, c3;
	lcd_init();
	a1 = a/10; a0 = a%10;
	b1 = b/10; b0 = b%10;
	c0 = a0*b0; c1 = a0*b1; c2 = a1*b0; c3 = a1*b1;
	c = c0 + (c1 + c2)*10 + c3*100;
	lcd_cmd(0x80); lcd_write_string(display_msg_line_1);
	
}

int str_to_int(unsigned char *amount){
	  int num = 0;
	  int i = 0 ;
		for (i = 0; amount[i] != '\0'; i++) { 
        num = num * 10 + (amount[i] - 48); 
    } 
		return num;
}

void int_to_str(int num, unsigned char *str){
	int i = 0;
	int j = 0;
	char temp;
	while(num>0){
		str[i++] = '0' + num%10;
		num = num/10;
	}
	
	//reverse the string
	for(j = 0; j<i/2; j++)
	{
		temp = str[j];
		str[j] = str[i-j-1];
		str[i-j-1] = temp;
	}
	str[i] = '\0';
}