# Humidity-Temp_Sensor 

# DHT11

### DHT11 is a digital temperature and humidity sensor

## Product parameters

### Relative humidity
### Resolution: 16Bit
### Repeatability: ±1% RH
### Accuracy: At 25℃ ±5% RH
### Interchangeability: fully interchangeable
### Response time: 1 / e (63%) of 25℃ 6s
### 1m / s air 6s
### Hysteresis: <± 0.3% RH
### Long-term stability: <± 0.5% RH / yr in
### Temperature
### Resolution: 16Bit
### Repeatability: ±0.2℃
### Range: At 25℃ ±2℃
### Response time: 1 / e (63%) 10S
### Electrical Characteristics
### Power supply: DC 3.5～5.5V
### Supply Current: measurement 0.3mA standby 60μA
### Sampling period: more than 2 seconds
### Pin Description
### 1, the VDD power supply 3.5～5.5V DC
### 2 DATA serial data, a single bus
### 3, NC, empty pin
### 4, GND ground, the negative power

## APIs

### unsigned char DHT_Read(unsigned char select);
### unsigned char DHT_Temperature();
### unsigned char DHT_Humidity();

## Macros 
### #define set_bit(reg,pin) reg|=(1<<pin)
### #define clear_bit(reg,pin) reg&=~(1<<pin)
### #define read_bit(reg,pin) (reg&(1<<pin))

### #define DHT_DDR DDRC
### #define DHT_PORT PORTC
### #define DHT_INPUTPIN PINC
### #define DHT_PIN PC0
