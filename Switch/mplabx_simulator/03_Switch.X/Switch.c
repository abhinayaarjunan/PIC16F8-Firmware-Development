/*
 * File:   Switch.c
 * Author: abhinaya
 *
 */

// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.


#include <xc.h>
#define _XTAL_FREQ 20000000

/* Program: PORTB has switch and PORTC has LEDs
 * RB4 - RC2 (1) and RC1 (0)
 * RB5 - RC2 (0) and RC1 (1)
 * RB6 - RC2 (0) and RC1 (0)
 * RB7 - RC2 (1) and RC1 (1)
 */

unsigned char val;
void main(void) {
    //ADCON1 = 0x06;        // Make all pins digital
    //OPTION_REG = 0x00;    // Enable PORTB pull-ups
    
    TRISB = 0xF0;  // 1111 0000  RB7-RB4 as Input and RB3-RB0 as Output
    TRISC = 0x00;  // 0000 0000  PORTC as Output
    
    PORTB = 0x10;  // 0001 0000
    PORTC = 0x00;  // 0000 0000  all bits as low
    
    while(1)
    {
        val = PORTB;
        switch(val)
        {
            //RB4 - 1110 0000 
            case 0xE0 : PORTC = 0x04;   //0000 0100    RC2 = 1, RC1 = 0  
            break;
            //RB5 - 1101 0000
            case 0xD0 : PORTC = 0x02;   //0000 0010    RC2 = 0, RC1 = 1  
            break;
            //RB6 - 1011 0000
            case 0xB0 : PORTC = 0x00;   //0000 0000    RC2 = 0, RC1 = 0
            break;
            //RB7 - 0111 0000
            case 0x70 : PORTC = 0x06;   //0000 0110    RC2 = 1, RC1 = 1
            break;
            
            default: PORTC = 0x00;      // No or multiple switches
        }
    }
    return;
}
