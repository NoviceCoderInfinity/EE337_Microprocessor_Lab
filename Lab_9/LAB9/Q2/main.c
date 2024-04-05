#include <at89c5131.h>
#include "lcd.h"		// Header file with LCD interfacing functions
#include "serial.h"	// Header file with UART interfacing functions

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
		
	

void min_notes(int amount,int* fiveh,int* oneh){
		while(amount>=500){
				*fiveh = *fiveh + 1;
				amount = amount-500;
		
		}
		while(amount>0){
				*oneh = *oneh + 1;
			  amount = amount-100;
		}	
}

void initial_state(){
	transmit_string("************************\r\n");
	transmit_string("Press A for Account display and W for withdrawing cash\r\n");
	transmit_string("************************\r\n");
	
}

void account_display(int *balance1, int *balance2){

	unsigned char acc;
	
	char bal_1[7];
	char bal_2[7];
	int_to_str(*balance1,bal_1);
	int_to_str(*balance2,bal_2);
	
		
	
	transmit_string("Hello, Please enter Account Number\r\n");
	acc = receive_char();
	
	switch(acc)
			{
				case '1':
	        transmit_string("Account Holder: Steven\r\n");
				  transmit_string("Account Balance: ");
				  transmit_string(bal_1);
				  transmit_string("\r\n");
				  
					break;
				
				case '2':
	        transmit_string("Account Holder: Gordon\r\n");
				  transmit_string("Account Balance: ");
				  transmit_string(bal_2);
				  transmit_string("\r\n");
					break;
							
				default:
					transmit_string("No such account, please enter valid details\r\n");
					break;
			}
			// Go back to initial state
	initial_state();
}

void withdraw_sub(int* balance){
	  unsigned char amount[7];
	  int amount1;
		int fiveh = 0;
	  int oneh = 0;
	  unsigned char five[7];
		unsigned char one[7];
	  unsigned char bal[7];
	
	  transmit_string("Enter Amount, in hundreds");
		amount[0] = receive_char();
		amount[1] = receive_char();
		amount1 = 100*str_to_int(amount);
	
	  min_notes(amount1,&fiveh,&oneh);
	
		int_to_str(fiveh,five);
		int_to_str(oneh,one);
	  if(amount1 > *balance){
			 transmit_string("Insufficient Balance");
			 
		} 
		else{
		*balance = *balance - amount1;		
		int_to_str(*balance,bal);
	
		transmit_string("Remaining Balance : ");
		transmit_string(bal);
		transmit_string("\r\n");
		//transmit_string(bal);
		
		transmit_string("500 Notes : ");
		transmit_string(five);
		transmit_string("  100 Notes : ");
		transmit_string(one);	
		}
}
void withdraw(int* balance1,int* balance2){
	unsigned char acc;
	transmit_string("Withdraw state, enter account number\r\n");
	acc = receive_char();
	if(acc == '1'){
		withdraw_sub(balance1);		
	}
	else if(acc == '2'){
		withdraw_sub(balance2);
	}
	else{
		transmit_string("No such account exist, please enter valid details\r\n");
	}

	// Go back to initial state
	initial_state();
}

// Main function
void main(void)
{
	int balance1 = 10000;
	int balance2 = 10000;
			// Receive a character
	unsigned char ch=0;
	// Call initialization functions
	uart_init();
	initial_state();

	while(1)
	{
			
			ch = receive_char();
	
			switch(ch)
			{
				case 'A':
					account_display(&balance1,&balance2);
					break;
				
				case 'a':
					account_display(&balance1,&balance2);
					break;
				
				case 'W':
					withdraw(&balance1,&balance2);
					break;
				
				case 'w':
					withdraw(&balance1,&balance2);
					break;
							
							
				default:
					transmit_string("Incorrect key pressed\r\n");
				  initial_state();
					break;
	
			}
			ch = receive_char();
	}
}
