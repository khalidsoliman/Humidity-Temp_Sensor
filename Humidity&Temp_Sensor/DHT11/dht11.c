/*
 * dht11.c
 *
 *  Created on: Feb 21, 2018
 *      Author: Khalid
 */


#include <avr/io.h>
#include <util/delay.h>
#include "dht11.h"
#include <string.h>

unsigned char DHT_Read(unsigned char select)
{
	// Valuables Declaration
	unsigned char i,y,byte;

	// Initialize Buffer & Zeroing it
	unsigned char data[5];
	memset(data,0,sizeof(data));

	// Initialization
	set_bit(DHT_DDR,DHT_PIN);
	set_bit(DHT_PORT,DHT_PIN);
	_delay_ms(1000); // To Prevent Error Reads

	// Enable
	clear_bit(DHT_PORT,DHT_PIN);
	_delay_ms(18);
	set_bit(DHT_PORT,DHT_PIN);
	_delay_us(1);

	// Input Pin to Receive
	clear_bit(DHT_DDR,DHT_PIN);
	_delay_us(10);

	// Make Sure that MC received LOW Signal
	if(read_bit(DHT_INPUTPIN,DHT_PIN)) return 255;
	_delay_us(80);

	// Make Sure that MC received HIGH Signal
	if(!read_bit(DHT_INPUTPIN,DHT_PIN)) return 255;
	_delay_us(80);

	//Read Data Request
	for(i=0;i<5;i++)
	{
		byte =0;
		for(y=0;y<8;y++)
		{
			while(!read_bit(DHT_INPUTPIN,DHT_PIN)); // it will be about 50 Micro-Sec for High
			_delay_us(35);
			if(read_bit(DHT_INPUTPIN,DHT_PIN)) byte|=(1<<(7-y));
			while(read_bit(DHT_INPUTPIN,DHT_PIN)); //wait until input get low
		}
		data[i]=byte;
	}

	// Reset
	set_bit(DHT_DDR,DHT_PIN);
	set_bit(DHT_PORT,DHT_PIN);
	_delay_ms(1000); // To Prevent Error Reads

	//check checksum
	if (data[0] + data[1] + data[2] + data[3] == data[4])
	{
		if (select == 0) return(data[2]); //return temperature
		else if(select == 1)	return(data[0]); //return humidity
	}
	return 255;
}

// get temperature (0..50C)
unsigned char DHT_Temperature()
{
	unsigned char ret = DHT_Read(0);
	if(ret == 255)
		return -1;
	else
		return ret;
}

// get humidity (20..90%)
unsigned char DHT_Humidity()
{
	unsigned char ret = DHT_Read(1);
	if(ret == 255)
		return -1;
	else
		return ret;
}
