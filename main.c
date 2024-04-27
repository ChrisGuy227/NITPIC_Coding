/*
 * File:   main.c
 * Author: Chris
 *
 * Created on April 24, 2024, 2:08 PM
 */

// CONFIG3L
#pragma config WDTCPS = WDTCPS_31// WDT Period selection bits (Divider ratio 1:65536; software control of WDTPS)
#pragma config WDTE = OFF       // WDT operating mode (WDT Disabled; SWDTEN is ignored)

#define _XTAL_FREQ 4000000                 // Fosc  frequency for _delay()  library
#define FCY    _XTAL_FREQ/4

#include <xc.h>
#include "C:\Program Files\Microchip\xc8\v2.46\pic\include\proc\pic18f46k42.h"

//phase shifter LEs
#define P_LE1 LATAbits.LATA1
#define P_LE2 LATAbits.LATA2
#define P_LE3 LATAbits.LATA3
#define P_LE4 LATAbits.LATA4

//phase shifter bits
#define PS180 LATAbits.LATA5
#define PS90 LATEbits.LATE0
#define PS45 LATEbits.LATE1
#define PS22 LATEbits.LATE2
#define PS11 LATAbits.LATA7
#define PS5 LATAbits.LATA6
#define PS2 LATCbits.LATC0
#define PS1 LATCbits.LATC1
#define OPT LATCbits.LATC2

//other stuff
#define ButtonIn LATDbits.LATD0
#define ButtonOut LATDbits.LATD1
#define R_LED LATDbits.LATD2
#define G_LED LATDbits.LATD3

void Phase_init() 
{
    PORTA = 0; LATA = 0; ANSELA = 0;  TRISA = 0b00000001; // PORTA 0 input / 1-7 outputs
    PORTB = 0; LATB = 0; ANSELB = 0;  TRISB = 0b00000000; // PORTB outputs
    PORTC = 0; LATC = 0; ANSELC = 0;  TRISC = 0b00000000; // PORTC outputs
    PORTD = 0; LATD = 0; ANSELD = 0;  TRISD = 0b00000001; // PORTD 0 input / 1-7 outputs 
    PORTE = 0; LATE = 0; ANSELE = 0;  TRISE = 0b1000; // PORTE 0-2 outputs
}

void Beam_1 () //106.8, 267.1, 160.3, 194
{
    // phase shifter 1
    PS90 = 1; PS11 = 1; PS5 = 1; __delay_ms(100);
    P_LE1 = 1; __delay_ms(100); 
    P_LE1 = 0; __delay_ms(100);
    PS90 = 0; PS11 = 0; PS5 = 0; __delay_ms(100);
    
    // phase shifter 2
    PS180 = 1; PS45 = 1; PS22 = 1; PS11 = 1; PS5 = 1; PS2 = 1; __delay_ms(100);
    P_LE2 = 1; __delay_ms(100); 
    P_LE2 = 0; __delay_ms(100);
    PS180 = 0; PS45 = 0; PS22 = 0; PS11 = 0; PS5 = 0; PS2 = 0; __delay_ms(100);
    
    // phase shifter 3
    PS90 = 1; PS45 = 1; PS22 = 1; PS2 = 1; __delay_ms(100);
    P_LE3 = 1; __delay_ms(100); 
    P_LE3 = 0; __delay_ms(100);
    PS90 = 0; PS45 = 0; PS22 = 0; PS2 = 0; __delay_ms(100);
    
    // phase shifter 4
    PS180 = 1; PS11 = 1; PS2 = 1; __delay_ms(100);
    P_LE4 = 1; __delay_ms(100); 
    P_LE4 = 0; __delay_ms(100);
    PS180 = 0; PS11 = 0; PS2 = 0; __delay_ms(100);
}

void Beam_2 () //194, 160.3, 267.1, 106.8
{
    // phase shifter 1
    PS180 = 1; PS11 = 1; PS2 = 1; __delay_ms(100);
    P_LE1 = 1; __delay_ms(100); 
    P_LE1 = 0; __delay_ms(100);
    PS180 = 0; PS11 = 0; PS2 = 0; __delay_ms(100);
    
    // phase shifter 2
    PS90 = 1; PS45 = 1; PS22 = 1; PS2 = 1; __delay_ms(100);
    P_LE2 = 1; __delay_ms(100); 
    P_LE2 = 0; __delay_ms(100);
    PS90 = 0; PS45 = 0; PS22 = 0; PS2 = 0; __delay_ms(100);
    
    // phase shifter 3
    PS180 = 1; PS45 = 1; PS22 = 1; PS11 = 1; PS5 = 1; PS2 = 1; __delay_ms(100);
    P_LE3 = 1; __delay_ms(100); 
    P_LE3 = 0; __delay_ms(100);
    PS180 = 0; PS45 = 0; PS22 = 0; PS11 = 0; PS5 = 0; PS2 = 0; __delay_ms(100);
    
    // phase shifter 4
    PS90 = 1; PS11 = 1; PS5 = 1; __delay_ms(100);
    P_LE4 = 1; __delay_ms(100); 
    P_LE4 = 0; __delay_ms(100);
    PS90 = 0; PS11 = 0; PS5 = 0; __delay_ms(100);
}

void Beam_3 () //182.8, 61.8, 334.6, 262.9
{
    // phase shifter 1
    PS180 = 1; PS2 = 1; __delay_ms(100);
    P_LE1 = 1; __delay_ms(100); 
    P_LE1 = 0; __delay_ms(100);
    PS180 = 0; PS2 = 0; __delay_ms(100);
    
    // phase shifter 2
    PS45 = 1; PS11 = 1; PS5 = 1; __delay_ms(100);
    P_LE2 = 1; __delay_ms(100); 
    P_LE2 = 0; __delay_ms(100);
    PS45 = 0; PS11 = 0; PS5 = 0; __delay_ms(100);
    
    // phase shifter 3
    PS180 = 1; PS90 = 1; PS45 = 1; PS11 = 1; PS5 = 1; PS2 = 1; __delay_ms(100);
    P_LE3 = 1; __delay_ms(100); 
    P_LE3 = 0; __delay_ms(100);
    PS180 = 0; PS90 = 0; PS45 = 0; PS11 = 0; PS5 = 0; PS2 = 0; __delay_ms(100);
    
    // phase shifter 4
    PS180 = 1; PS45 = 1; PS22 = 1; PS11 = 1; PS2 = 1; PS1 = 1; __delay_ms(100);
    P_LE4 = 1; __delay_ms(100); 
    P_LE4 = 0; __delay_ms(100);
    PS180 = 0; PS45 = 0; PS22 = 0; PS11 = 0; PS2 = 0; PS1 = 0; __delay_ms(100);
}

void Beam_4 () //246.0, 243.2, 201.0, 209.5
{
    // phase shifter 1
    PS180 = 1; PS45 = 1; PS11 = 1; PS5 = 1; PS2 = 1; PS1 = 1; __delay_ms(100);
    P_LE1 = 1; __delay_ms(100); 
    P_LE1 = 0; __delay_ms(100);
    PS180 = 0; PS45 = 0; PS11 = 0; PS5 = 0; PS2 = 0; PS1 = 0; __delay_ms(100);
    
    // phase shifter 2
    PS180 = 1; PS45 = 1; PS11 = 1; PS5 = 1; PS1 = 1; __delay_ms(100);
    P_LE2 = 1; __delay_ms(100); 
    P_LE2 = 0; __delay_ms(100);
    PS180 = 0; PS45 = 0; PS11 = 0; PS5 = 0; PS1 = 0; __delay_ms(100);
    
    // phase shifter 3
    PS180 = 1; PS11 = 1; PS5 = 1; PS2 = 1; PS1 = 1; __delay_ms(100);
    P_LE3 = 1; __delay_ms(100); 
    P_LE3 = 0; __delay_ms(100);
    PS180 = 0; PS11 = 0; PS5 = 0; PS2 = 0; PS1 = 0; __delay_ms(100);
    
    // phase shifter 4
    PS180 = 1; PS22 = 1; PS5 = 1; PS1 = 1; __delay_ms(100);
    P_LE4 = 1; __delay_ms(100); 
    P_LE4 = 0; __delay_ms(100);
    PS180 = 0; PS22 = 0; PS5 = 0; PS1 = 0; __delay_ms(100);
}

void Beam_5 () //209.5, 201.0, 243.2, 246.0
{
    // phase shifter 1
    PS180 = 1; PS22 = 1; PS5 = 1; PS1 = 1; __delay_ms(100);
    P_LE1 = 1; __delay_ms(100); 
    P_LE1 = 0; __delay_ms(100);
    PS180 = 0; PS22 = 0; PS5 = 0; PS1 = 0; __delay_ms(100);
    
    // phase shifter 2
    PS180 = 1; PS11 = 1; PS5 = 1; PS2 = 1; PS1 = 1; __delay_ms(100);
    P_LE2 = 1; __delay_ms(100); 
    P_LE2 = 0; __delay_ms(100);
    PS180 = 0; PS11 = 0; PS5 = 0; PS2 = 0; PS1 = 0; __delay_ms(100);
    
    // phase shifter 3
    PS180 = 1; PS45 = 1; PS11 = 1; PS5 = 1; PS1 = 1; __delay_ms(100);
    P_LE3 = 1; __delay_ms(100); 
    P_LE3 = 0; __delay_ms(100);
    PS180 = 0; PS45 = 0; PS11 = 0; PS5 = 0; PS1 = 0; __delay_ms(100);
    
    // phase shifter 4
    PS180 = 1; PS45 = 1; PS11 = 1; PS5 = 1; PS2 = 1; PS1 = 1; __delay_ms(100);
    P_LE4 = 1; __delay_ms(100); 
    P_LE4 = 0; __delay_ms(100);
    PS180 = 0; PS45 = 0; PS11 = 0; PS5 = 0; PS2 = 0; PS1 = 0; __delay_ms(100);
}

void Beam_6 () //262.9, 334.6, 61.8, 182.8
{
    // phase shifter 1
    PS180 = 1; PS45 = 1; PS22 = 1; PS11 = 1; PS2 = 1; PS1 = 1; __delay_ms(100);
    P_LE1 = 1; __delay_ms(100); 
    P_LE1 = 0; __delay_ms(100);
    PS180 = 0; PS45 = 0; PS22 = 0; PS11 = 0; PS2 = 0; PS1 = 0; __delay_ms(100);
    
    // phase shifter 2
    PS180 = 1; PS90 = 1; PS45 = 1; PS11 = 1; PS5 = 1; PS2 = 1; __delay_ms(100);
    P_LE2 = 1; __delay_ms(100); 
    P_LE2 = 0; __delay_ms(100);
    PS180 = 0; PS90 = 0; PS45 = 0; PS11 = 0; PS5 = 0; PS2 = 0; __delay_ms(100);
    
    // phase shifter 3
    PS45 = 1; PS11 = 1; PS5 = 1; __delay_ms(100);
    P_LE3 = 1; __delay_ms(100); 
    P_LE3 = 0; __delay_ms(100);
    PS45 = 0; PS11 = 0; PS5 = 0; __delay_ms(100);
    
    // phase shifter 4
    PS180 = 1; PS2 = 1; __delay_ms(100);
    P_LE4 = 1; __delay_ms(100); 
    P_LE4 = 0; __delay_ms(100);
    PS180 = 0; PS2 = 0; __delay_ms(100);
}

void ADC_init()
{
    TRISAbits.TRISA0 = 1;
    ANSELAbits.ANSELA0 = 1;
    
    ADCON0bits.FM = 1;
    ADCON0bits.CS = 1;
    
    ADCLK = 0x00;
    ADPCH = 0x00;
    
    ADCAP = 0x00;
    ADREF = 0x0;
    
    ADACQL = 0x00;
    ADACQH = 0x00;
    
    ADCON0bits.ON = 1;    
}

void Green_LED()
{
    G_LED = 1;
    __delay_ms(1000);
    G_LED = 0;
}

void Red_LED()
{
    R_LED = 1;
    __delay_ms(1000);
    R_LED = 0;
}

void Rapid_Red_LED()
{
    R_LED = 1;
    __delay_ms(100);
    R_LED = 0;
    __delay_ms(100);
    R_LED = 1;
    __delay_ms(100);
    R_LED = 0;
    __delay_ms(100);
    R_LED = 1;
    __delay_ms(100);
    R_LED = 0;
    __delay_ms(100);
}

void Error_LED()
{
    G_LED = 1;
    R_LED = 1;
    __delay_ms(500);
    G_LED = 0;
    R_LED = 0;
}

void Right_Pattern()
{
    G_LED = 1;
    R_LED = 1;
    __delay_ms(500);
    R_LED = 0;
    __delay_ms(500);
    R_LED = 1;
    __delay_ms(500);
    G_LED = 0;
    R_LED = 0;
}

void Left_Pattern()
{
    G_LED = 1;
    R_LED = 1;
    __delay_ms(500);
    G_LED = 0;
    __delay_ms(500);
    G_LED = 1;
    __delay_ms(500);
    G_LED = 0;
    R_LED = 0;
}

void main(void) {
    
    Phase_init();
    ADC_init();
    const float Vref = 5;
    float digital, voltage_1, voltage_2; 
    const float threshold = 0.1; // This will be the equivalent voltage for our passable signal
    
    int range_1; // Signal range from 0 - 180
    int range_2; // Signal range from 0 - 120
    int range_3; // Signal range from 60 - 180
    
    //Starting the code with the widest range (range_1))
    range_1 = 1;
    range_2 = 0;
    range_3 = 0;
    
    while(1){
        
        if (range_1 == 1){
            Error_LED();
            /////////////////////////////////////////
            __delay_ms(1000);//FOR TESTING PURPOSES//
            /////////////////////////////////////////
            
            Beam_1();
            //This is the ADC taking measurement
            ADCON0bits.GO = 1;
            while (ADCON0bits.GO);
            digital = (ADRESH*256) | (ADRESL);
            voltage_1 = digital*((float)Vref/(float)(4096));
            
            Error_LED();
            /////////////////////////////////////////
            __delay_ms(1000);//FOR TESTING PURPOSES//
            /////////////////////////////////////////
            
            Beam_2();
            //This is the ADC taking measurement
            ADCON0bits.GO = 1;
            while (ADCON0bits.GO);
            digital = (ADRESH*256) | (ADRESL);
            voltage_2 = digital*((float)Vref/(float)(4096));
            
            if ((voltage_1 < threshold) && (voltage_2 < threshold)){
                Red_LED();
                return;
            }
            // This compares the 2 values and enables the relevant range_x
            else if (voltage_1 > voltage_2){
                range_1 = 0;
                range_2 = 1; // due to Beam_1 having higher voltage
                range_3 = 0;
            }
            else if (voltage_1 < voltage_2){
                range_1 = 0;
                range_2 = 0;
                range_3 = 1; // due to Beam_2 having higher voltage
            }
        }
        else if (range_2 == 1){
            
            Right_Pattern();
            Error_LED();
            /////////////////////////////////////////
            __delay_ms(1000);//FOR TESTING PURPOSES//
            /////////////////////////////////////////
            
            Beam_3();
            //This is the ADC taking measurement
            ADCON0bits.GO = 1;
            while (ADCON0bits.GO);
            digital = (ADRESH*256) | (ADRESL);
            voltage_1 = digital*((float)Vref/(float)(4096));
            
            Error_LED();
            /////////////////////////////////////////
            __delay_ms(1000);//FOR TESTING PURPOSES//
            /////////////////////////////////////////
            
            Beam_4();
            //This is the ADC taking measurement
            ADCON0bits.GO = 1;
            while (ADCON0bits.GO);
            digital = (ADRESH*256) | (ADRESL);
            voltage_2 = digital*((float)Vref/(float)(4096));
            
            // This compares the 2 values and enables the relevant range_x
            if (voltage_1 > voltage_2){
                if (voltage_1 > threshold){
                    Beam_3();
                    Green_LED();
                    G_LED = 1;
                    __delay_ms(1000);
                    G_LED = 0;
                }
                
                else if (voltage_1 < threshold) {
                    range_1 = 1; //The signal is too low and returns to search
                    range_2 = 0;
                    range_3 = 0;
                    Rapid_Red_LED();
                }
            }
            else if (voltage_1 < voltage_2){
                if (voltage_2 > threshold){
                    Beam_4();
                    Green_LED();
                    G_LED = 1;
                    __delay_ms(1000);
                    G_LED = 0;
                }
                
                else if (voltage_2 < threshold) {
                    range_1 = 1; //The signal is too low and returns to search
                    range_2 = 0;
                    range_3 = 0;
                    Rapid_Red_LED();
                }
            }
        }
        else if (range_3 == 1){
            
            Left_Pattern();
            Error_LED();
            /////////////////////////////////////////
            __delay_ms(2500);//FOR TESTING PURPOSES//
            /////////////////////////////////////////
            
            Beam_5();
            //This is the ADC taking measurement
            ADCON0bits.GO = 1;
            while (ADCON0bits.GO);
            digital = (ADRESH*256) | (ADRESL);
            voltage_1 = digital*((float)Vref/(float)(4096));
            
            Error_LED();
            /////////////////////////////////////////
            __delay_ms(2500);//FOR TESTING PURPOSES//
            /////////////////////////////////////////
            
            Beam_6();
            //This is the ADC taking measurement
            ADCON0bits.GO = 1;
            while (ADCON0bits.GO);
            digital = (ADRESH*256) | (ADRESL);
            voltage_2 = digital*((float)Vref/(float)(4096));
            
            // This compares the 2 values and enables the relevant range_x
            if (voltage_1 > voltage_2){
                Beam_5();
                if (voltage_1 > threshold){
                    Green_LED();
                    G_LED = 1;
                    __delay_ms(2500);
                    G_LED = 0;
                }
                
                else {
                    range_1 = 1; //The signal is too low and returns to search
                    range_2 = 0;
                    range_3 = 0;
                    Rapid_Red_LED();
                }
            }
            else if (voltage_1 < voltage_2){
                Beam_6();
                if (voltage_2 > threshold){
                    Green_LED();
                    G_LED = 1;
                    __delay_ms(2500);
                    G_LED = 0;
                }
                
                else {
                    range_1 = 1; //The signal is too low and returns to search
                    range_2 = 0;
                    range_3 = 0;
                    Rapid_Red_LED();
                }
            }
        }
    }
}
