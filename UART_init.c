#include "C:/Users/Youssef/Downloads/tm4c123gh6pm.h"
#include "stdint.h"
#include "math.h"
#define SPACE	  0x20
#define COMMA	  0x2C
#define MAXSIZE    100		/* GPS at most, sends 80 or so chars per message string.  So set maximum to 100 */
#include <stdio.h >
#include <ctype.h >  		/* required for the isalnum function */
#include <stdlib.h >
#include <string.h >
#define CR         0x0d




// Declaring Functions
int distance_Inc(void);
void delay_milli(int n);
void delay_micro(int n);
void LCD_PORT_A_B(void);
void LCD_Cmd(unsigned char command);
void LCD_Data(unsigned char data);
void Display_at_100(void);
double calc_Distance(double lat_init, double lon_init, double lat_final, double lon_final);
void UART2_PortD_Init(void);
uint8_t Data_Avilable (void);
void PortF_Init(void);
unsigned char com_rx(void);
void DelayMin(void);
void Delay(void);
double ParsingLong(void);
double ParsingLat(void);


	
	void UART2_PortD_Init(void){
SYSCTL_RCGCUART_R |= 0x04; // Uart 2 init
SYSCTL_RCGCGPIO_R |= 0x08; // port D clock init	

//UART CONFIG
UART2_CTL_R &= ~0x01; //Uart disable
UART2_IBRD_R = 104;
UART2_FBRD_R = 11;
UART2_LCRH_R = 0x70; //	D4 = 1 for 16 bit FIFO , D5,D6= 1 for 8 bits word lenght
UART2_CTL_R |= 0x301; // ENABLE AGAIN

// GPIO CONFIG 
GPIO_PORTD_LOCK_R = 0x4C4F434B;   // 2) unlock Port PD7
GPIO_PORTD_CR_R = 0xC0;           // allow changes to PD6-PD7       
GPIO_PORTD_AMSEL_R = 0x00;        // 3) disable analog function	
GPIO_PORTD_AFSEL_R |= 0xC0; // AFSEL FOR D6 AND D7
GPIO_PORTD_PCTL_R = 0x11000000; //ENABLE UART 2 FOR PORT D6 AND D7
GPIO_PORTD_DEN_R |= 0xC0; // DIGITAL ENABLE FOR PORT D6 AND D7	
GPIO_PORTD_DIR_R = 0x00;

}
