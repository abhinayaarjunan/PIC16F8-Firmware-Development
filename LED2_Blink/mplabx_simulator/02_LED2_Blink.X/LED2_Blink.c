/*
 * File:   LED2_Blink.c
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
#define _XTAL_FREQ 6000000


void main(void)
{
    TRISC = 0x00; // 0000 0000 = 0x00 set PORTC as output
    while(1){
        PORTC =0x02; // 0000 0010 = 0x02; RC1 - ON and RC6 - OFF
        //__delay_ms(3000);
        PORTC =0x42; // 0100 0010 = 0x42; RC1 - ON and RC6 - ON
        //__delay_ms(3000);
        PORTC =0x40; // 0100 0000 = 0x40; RC1 - OFF and RC6 - ON
        //__delay_ms(3000);
        PORTC =0x00; // 0000 0000 = 0x02; RC1 - OFF and RC6 - OFF
        //__delay_ms(3000);
    }
    return;
}
