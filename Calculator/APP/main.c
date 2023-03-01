/*
 * main.c

 *
 *      Author: esraa
 */
#include"../MCAL/DIO/DIO_Init.h"
#include "../HAL/LCD/LCD_int.h"

int main(){
	Keypad_enuInit();
	LCD_enuinit();
	unsigned char pressed;
	u16 num=0;
	u16 res;
	u8 f_operation=1;
	u8 operation;
	LCD_enusendcmd(0x0E);
	while(1){
		Keypad_enuGetPressedKey(&pressed);
		LCD_enuwritedate(pressed);
		switch(pressed){
		case '+':
			if(f_operation==1)
			{
				res=num;
				num=0;
				f_operation=0;
				operation='+';
				break;
			}
			res+=num;
			num=0;

			break;
		case '-':
			if(f_operation==1)
			{
				res=num;
				num=0;
				f_operation=0;
				operation='-';
				break;
			}
			res-=num;
			num=0;

			break;
		case '*':
			if(f_operation==1)
			{
				res=num;
				num=0;
				f_operation=0;
				operation='*';
				break;
			}
			res*=num;
			num=0;

			break;
		case '/':
			if(f_operation==1)
			{
				res=num;
				num=0;
				f_operation=0;
				operation='/';
				break;
			}
			res/=num;
			num=0;
			break;
		case '=':
		  switch (operation) {
				case '+':
					res+=num;
					break;
				case '-':
					res-=num;
					break;
				case '*':
					res*=num;
					break;
				case '/':
					res/=num;
					break;
			}
		  LCD_voidWriteNumber(res);
			res=0;
			num=0;
			f_operation=1;
			break;
		case 'c':
			LCD_enusendcmd(0x01);
			break;
		default:
			num=num*10+(pressed-'0');
			break;

		}
	}
}
