#include <at89c5131.h>
#include "lcd.h"

code unsigned char display_msg1[]="    Sa (low)    ";		
code unsigned char display_msg2[]="       Re       ";	
code unsigned char display_msg3[]="       Ga       ";	
code unsigned char display_msg4[]="       Ma       ";
code unsigned char display_msg5[]="       Pa       ";
code unsigned char display_msg6[]="       Dha      ";
code unsigned char display_msg7[]="       Ni       ";
code unsigned char display_msg8[]="    Sa (high)   ";
code unsigned char display_msg9[]="     Silence    ";

code unsigned char welcome_msg1[]=" Anupam's Music ";

sbit ROW0 = P3^4;		sbit COL0 = P3^3;
sbit ROW1 = P3^5;		sbit COL1 = P3^2;
sbit ROW2 = P3^6;		sbit COL2 = P3^1;
sbit ROW3 = P3^7;		sbit COL3 = P3^0;
sbit LED=P0^7;

int mask = 0x0F;

void sa_l();	void re();	void ga();
void ma();	void pa();	void dha();
void ni() ;	void sa_h();

void prev_key_release() ;
void check_key_press() ;
int read_key();
void debounce() ;
int row_detection() ;
void play_sound(int key) ;
void display_on_led(int key);

		
void main () {
		int key;
		lcd_init();
		TMOD = 0x11;
		P3 = 0x0F;
		
		lcd_write_string(welcome_msg1);
		while(1) {
				prev_key_release();
				check_key_press();
				key = read_key();								
				display_on_led(key);
				play_sound(key);	
		}
}

void prev_key_release() {
		ROW0 = 0; ROW1 = 0; ROW2 = 0; ROW3 = 0;
		while (!(COL0 & COL1 & COL2 & COL3)); }

void check_key_press() {
		while (COL0 & COL1 & COL2 & COL3);
		debounce();
		if (COL0 & COL1 & COL2 & COL3) {prev_key_release();}}

int read_key() {
		//int P3_data;
		//Reading from ROW0
		ROW0 = 0; ROW1 = 1; ROW2 = 1; ROW3 = 1;
		//P3_data = P3; if (P3_data & mask != mask) 
		if (!(COL0 & COL1 & COL2 & COL3)) {
				if (COL0 == 0)		  { return 1; }
				else if (COL1 == 0) { return 2; }
				else if (COL2 == 0) { return 3; }
				else if (COL3 == 0) { return 0; }		}
		
		//Reading from ROW1
		ROW0 = 1; ROW1 = 0; ROW2 = 1; ROW3 = 1;
		if (!(COL0 & COL1 & COL2 & COL3)) {
				if (COL0 == 0)		  { return 4; }
				else if (COL1 == 0) { return 5; }
				else if (COL2 == 0) { return 6; }
				else if (COL3 == 0) { return 0; }		}
		
		//Reading from ROW2
		ROW0 = 1; ROW1 = 1; ROW2 = 0; ROW3 = 1;
		if (!(COL0 & COL1 & COL2 & COL3)) {
				if (COL0 == 0)		  { return 7; }
				else if (COL1 == 0) { return 8; }
				else if (COL2 == 0) { return 9; }
				else if (COL3 == 0) { return 0; }		}
		
		//Reading from ROW3
		ROW0 = 1; ROW1 = 1; ROW2 = 1; ROW3 = 0;
		if (!(COL0 & COL1 & COL2 & COL3)) {
				if (COL0 == 0)		  { return 0; }
				else if (COL1 == 0) { return 0; }
				else if (COL2 == 0) { return 0; }
				else if (COL3 == 0) { return 0; }		}
}

void debounce() {
		TF1 = 0;
		TL1 = 0xEC;	TH1 = 0x00;
		TR1 = 1;
		while(!TF1);
		TR1  = 0;	}
		
void play_sound(int key) {
		switch(key) {
//				case 1:	{sa_l(); }	lcd_cmd(0x01);		break;
//				case 2:	{re();		}	lcd_cmd(0x01);		break;
//				case 3:	{ga();		}	lcd_cmd(0x01);		break;
//				case 4:	{ma();		}	lcd_cmd(0x01);		break;
//				case 5: {pa();		}	lcd_cmd(0x01);		break;
//				case 6:	{dha();	}	lcd_cmd(0x01);		break;
//				case 7:	{ni();		}	lcd_cmd(0x01);		break;
//				case 8: {sa_h();	}	lcd_cmd(0x01);		break;
//				case 9: {      	}	lcd_cmd(0x01);		break;
//				default:{      	}	lcd_cmd(0x01);		break;
					case 1:	while (!(COL0 & COL1 & COL2 & COL3)) {sa_l(); }	lcd_cmd(0x01);		break;
					case 2:	while (!(COL0 & COL1 & COL2 & COL3)) {re();		}	lcd_cmd(0x01);		break;
					case 3:	while (!(COL0 & COL1 & COL2 & COL3)) {ga();		}	lcd_cmd(0x01);		break;
					case 4:	while (!(COL0 & COL1 & COL2 & COL3)) {ma();		}	lcd_cmd(0x01);		break;
					case 5:	while (!(COL0 & COL1 & COL2 & COL3)) {pa();		}	lcd_cmd(0x01);		break;
					case 6:	while (!(COL0 & COL1 & COL2 & COL3)) {dha();	}	lcd_cmd(0x01);		break;
					case 7:	while (!(COL0 & COL1 & COL2 & COL3)) {ni();		}	lcd_cmd(0x01);		break;
					case 8: while (!(COL0 & COL1 & COL2 & COL3)) {sa_h();	}	lcd_cmd(0x01);		break;
					case 9: while (!(COL0 & COL1 & COL2 & COL3)) {      	}	lcd_cmd(0x01);		break;
					default:while (!(COL0 & COL1 & COL2 & COL3)) {      	}	lcd_cmd(0x01);		break;
			}
}

void display_on_led(int key) {
			lcd_cmd(0x01);				
			lcd_cmd(0x80);
			msdelay(4);
			switch (key) {
				case 1:	lcd_write_string(display_msg1); break;
				case 2:	lcd_write_string(display_msg2); break;
				case 3:	lcd_write_string(display_msg3); break;
				case 4:	lcd_write_string(display_msg4);	break;
				case 5:	lcd_write_string(display_msg5); break;
				case 6:	lcd_write_string(display_msg6); break;
				case 7:	lcd_write_string(display_msg7); break;
				case 8:	lcd_write_string(display_msg8); break;
				case 9: lcd_write_string(display_msg9); break;
				default:lcd_write_string(welcome_msg1); break;
			}
}

void sa_l() {		
		LED=1;TF0 = 0;
		TH0 = 0xef;	TL0 = 0xb9;
		TR0 = 1;	while(!TF0);
		LED=0;TF0 = 0;
		TH0 = 0xef; TL0 = 0xb9;
		TR0 = 1;	while(!TF0)	;	}

void re() {
		LED = 1;	TF0 = 0;
		TH0 = 0xf1; TL0 = 0x88;
		TR0 = 1; while(!TF0);
		LED = 0;	TF0 = 0;
		TH0 = 0xf1; TL0 = 0x88;
		TR0 = 1; while(!TF0); 	}

void ga() {
		LED = 1;TF0 = 0;
		TH0 = 0xf2; TL0 = 0xfa;
		TR0 = 1; while(!TF0);
		LED = 0; TF0 = 0;
		TH0 = 0xf2; TL0 = 0xfa;
		TR0 = 1; while(!TF0); 	}

void ma() {
		LED = 1;TF0 = 0;
		TH0 = 0xf3; TL0 = 0xcb;
		TR0 = 1;	while(!TF0);
		LED = 0;	TF0 = 0;
		TH0 = 0xf3;	TL0 = 0xcb;
		TR0 = 1;	while(!TF0); 	}

void pa() {
		LED = 1;TF0 = 0;
		TH0 = 0xf5;	TL0 = 0x26;
		TR0 = 1;	while(!TF0);
		LED = 0;TF0 = 0;
		TH0 = 0xf5;	TL0 = 0x26;
		TR0 = 1;	while(!TF0);		}

void dha() {		
		LED = 1;	TF0 = 0;
		TH0 = 0xf6;	TL0 = 0x3c;
		TR0 = 1;	while(!TF0);
		LED = 0;TF0 = 0;
		TH0 = 0xf6;	TL0 = 0x3c;
		TR0 = 1;	while(!TF0);		}

void ni() {
		LED = 1;TF0 = 0;
		TH0 = 0xf7;	TL0 = 0x51;
		TR0 = 1;	while(!TF0);
		LED = 0;	TF0 = 0;
		TH0 = 0xf7;	TL0 = 0x51;
		TR0 = 1;	while(!TF0);		}

void sa_h() {		
		LED = 1;	TF0 = 0;
		TH0 = 0xf7;	TL0 = 0xdc;
		TR0 = 1;	while(!TF0);
		LED = 0;	TF0 = 0;
		TH0 = 0xf7;	TL0 = 0xdc;
		TR0 = 1;	while(!TF0); 	}