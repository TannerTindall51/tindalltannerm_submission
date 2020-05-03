//
//CPE301 - DA6A Task 1
//Tanner Tindall
//

#define BAUD 9600
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/setbaud.h>
#include <stdlib.h>
#include <stdio.h>
#include <util/delay.h>

#define SLAVE_ADDRESS 0xD0
#define DIVIDER_ADDRESS 0x19
#define POWER_ADDRESS 0x6B
#define CONFIG_ADDRESS 0x1A
#define GYRO_CONFIG_ADDRESS 0x1B
#define INTERRUPT_ADDRESS 0x38
#define ACC_START_ADDRESS 0x3B
#define GYRO_START_ADDRESS 0x43
#define UBBR_VALUE 103
#define BITRATE 3

volatile uint8_t data;
volatile uint8_t value;
volatile float Ax,Ay,Az;
volatile float Gx=0, Gy=0, Gz=0;
float Acc_x,Acc_y,Acc_z,Temperature,Gyro_x,Gyro_y,Gyro_z;


void i2cInit(void)
{
	TWBR0 = BITRATE;						//set bitrate
	TWSR0 |= (0<<TWPS1)|(0<<TWPS0);			//set prescaler to 1
}

unsigned char i2cRead(value)
{
	if (value == 0)									//ack bit & continue
	{
		TWCR0= (1<<TWINT) | (1<<TWEN) | (1<<TWEA);   //enable TWI/ACK and clear flag
	}
	else
	{
		TWCR0= (1<<TWINT) | (1<<TWEN);   	//enable TWI & clear flag
	}
	while ((TWCR0& (1<<TWINT)) == 0);     	//wait until emptied
	return TWDR0;							//return value to TWDR
}

void i2cWrite(data)
{
	TWDR0 = data;                   			//pull data from TWI register
	TWCR0 = (1<<TWINT) | (1<<TWEN);			//enable TWI & clear flag
	while ((TWCR0&(1<<TWINT)) == 0);   		//wait until done
}

void i2cStart(void)
{
	TWCR0= (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);		//enable TWI, clear flag, start condition
	while (TWCR0 & (1<<TWINT) == 0);            	//wait until emptied
}
void i2cStop(void)
{
	TWCR0 = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);	//enable TWI, clear flag, stop condition
	while ((TWCR0&(1<<TWINT)) == 0);				//wait until done
}

void i2cIdle(char slave_write_address)				//taken from Dr. Venkis I2C start wait function in Demo code
{
	uint8_t check;									/* Declare variable */
	while (1)
	{
		TWCR0 = (1<<TWSTA)|(1<<TWEN)|(1<<TWINT);	/* Enable TWI, generate start condition and clear interrupt flag */
		while (!(TWCR0 & (1<<TWINT)));				/* Wait until TWI finish its current job (start condition) */
		check = TWSR0 & 0xF8;						/* Read TWI status register with masking lower three bits */
		if (check != 0x08)							/* Check weather start condition transmitted successfully or not? */
		continue;									/* If no then continue with start loop again */
		TWDR0 = slave_write_address;				/* If yes then write SLA+W in TWI data register */
		TWCR0 = (1<<TWEN)|(1<<TWINT);				/* Enable TWI and clear interrupt flag */
		while (!(TWCR0 & (1<<TWINT)));				/* Wait until TWI finish its current job (Write operation) */
		check = TWSR0 & 0xF8;						/* Read TWI status register with masking lower three bits */
		if (check != 0x18 )							/* Check weather SLA+W transmitted & ack received or not? */
		{
			i2cStop();								/* If not then generate stop condition */
			continue;								/* continue with start loop again */
		}
		break;										/* If yes then break loop */
	}
}

void initializeUART()
{
	DDRD |= 0x02;
	UBRR0 = 103;
	UCSR0C |= (0<<UPM01) | (0<<UPM00) | (1<<UCSZ01) | (1<<UCSZ00);  //disable parity and set to asynchronous
}

void USART_tx_transmit()
{
	UBRR0 = 103;
	UCSR0B |= (1 << TXCIE0) | (1<<TXEN0);		//enable data transmission
	DDRD |= 0x02;								//transmit through PD2
}

void USART_tx(char*data)						//outputs data to terminal
{
	while((*data != '\0'))						//loop until all data is emptied
	{
		while(!(UCSR0A & (1 << UDRE0)));		//wait until data register in emptied
		UDR0 = *data;							//once emptied, import into data register UDR0
		data++;									//increments pointer position for data
	}
}

void gyroInit()
{
	i2cIdle(SLAVE_ADDRESS);			//start condition at slave address
	i2cWrite(DIVIDER_ADDRESS);		//write to sampling rate register
	i2cWrite(0x07);					//set sampling rate to 1kHz
	i2cStop();						//stop condition

	i2cIdle(SLAVE_ADDRESS);			//set power & start condition at slave address
	i2cWrite(POWER_ADDRESS);		//write to that address
	i2cWrite(0x01);					//PLL with X axis gyroscope reference
	i2cStop();						//stop condition

	i2cIdle(SLAVE_ADDRESS);			//start condition at slave address
	i2cWrite(CONFIG_ADDRESS);		//write to that address
	i2cWrite(0x00);					//set sampling rate to 8kHz
	i2cStop();						//stop condition

	i2cIdle(SLAVE_ADDRESS);			//start condition at slave address
	i2cWrite(GYRO_CONFIG_ADDRESS);	//write to that address
	i2cWrite(0x18);					//set range
	i2cStop();						//stop condition

	i2cIdle(SLAVE_ADDRESS);			//start condition at slave address
	i2cWrite(INTERRUPT_ADDRESS);	//write to interrupt register address
	i2cWrite(0x01);					//toggle DATA_RDY_EN
	i2cStop();						//stop condition
}

int main()
{
	i2cInit();                  //initializing functions
	i2cStart();
	USART_tx_transmit();
	initializeUART();
	gyroInit();
	
	while(1)
	{
		Read_RawValue();		//read in data
		sendData();				//output data to UART
		_delay_ms(250);
	}
}

void Read_RawValue()
{
	i2cIdle(SLAVE_ADDRESS);			//start condition
	i2cWrite(ACC_START_ADDRESS);	//set acc address
	
	i2cStart();						//read acc data
	Acc_x = (((int)i2cRead()<<8) | (int)i2cRead());
	Acc_y = (((int)i2cRead()<<8) | (int)i2cRead());
	Acc_z = (((int)i2cRead()<<8) | (int)i2cRead());
	i2cStop();						//stop condition
	
	i2cIdle(SLAVE_ADDRESS);			//start condition
	i2cWrite(GYRO_START_ADDRESS);	//set gyro address
	
	i2cStart();						//read gyro data
	i2cWrite(SLAVE_ADDRESS);
	Gyro_x = (((int)i2cRead()<<8) | (int)i2cRead());
	Gyro_y = (((int)i2cRead()<<8) | (int)i2cRead());
	Gyro_z = (((int)i2cRead()<<8) | (int)i2cRead());
	i2cStop();						//stop condition
}

void sendData()			
{
	char array[50];		//array data is input into
	Ax = Acc_x/16384.0;		//scale collected value
	snprintf(array,sizeof(array), "%f\r\n", Ax);	//send to UART 
	USART_tx(array);
	
	Ay = Acc_y/16384.0;
	snprintf(array,sizeof(array), "%f\r\n", Ay);
	USART_tx(array);
	
	Az = Acc_z/16384.0;
	snprintf(array,sizeof(array), "%f\r\n", Az);
	USART_tx(array);
	
	Gx = Gyro_x/16.4;
	snprintf(array,sizeof(array), "%f\r\n", Gx);
	USART_tx(array);
	
	Gy = Gyro_y/16.4;
	snprintf(array,sizeof(array), "%f\r\n", Gy);
	USART_tx(array);
	
	Gz = Gyro_z/16.4;
	snprintf(array,sizeof(array), "%f\r\n", Gz);
	USART_tx(array);
}
