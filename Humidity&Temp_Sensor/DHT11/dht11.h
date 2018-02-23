/*
 * dht11.h
 *
 *  Created on: Feb 21, 2018
 *      Author: Khalid
 */

#ifndef DHT11_DHT11_H_
#define DHT11_DHT11_H_

#define set_bit(reg,pin) reg|=(1<<pin)
#define clear_bit(reg,pin) reg&=~(1<<pin)
#define read_bit(reg,pin) (reg&(1<<pin))

#define DHT_DDR DDRC
#define DHT_PORT PORTC
#define DHT_INPUTPIN PINC
#define DHT_PIN PC0

unsigned char DHT_Read(unsigned char select);
unsigned char DHT_Temperature();
unsigned char DHT_Humidity();


#endif /* DHT11_DHT11_H_ */
