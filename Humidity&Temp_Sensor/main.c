/*
 * main.c
 *
 *  Created on: Feb 22, 2018
 *      Author: Khalid
 */


#include "DHT11/dht11.h"
#include "LCD/LCD.h"
#include <avr/io.h>
#include <util/delay.h>

int main()
{
	char temp=0;
	char humidity=0;
	char arr_temp[10];
	char arr_humditiy[10];
	LCD_init();
	LCD_Write_CMD(0x01);
	LCD_Send_String_Row_Column(1,1,"Temp = ");
	LCD_Send_String_Row_Column(2,1,"Humidity = ");
	while(1)
	{
		temp=DHT_Temperature();
		humidity=DHT_Humidity();
		_delay_ms(1000);
		LCD_Int_2_String(temp,arr_temp);
		LCD_Int_2_String(humidity,arr_humditiy);
		LCD_Send_String_Row_Column(1,12,arr_temp);
		LCD_Send_String_Row_Column(2,12,arr_temp);
	}
}
