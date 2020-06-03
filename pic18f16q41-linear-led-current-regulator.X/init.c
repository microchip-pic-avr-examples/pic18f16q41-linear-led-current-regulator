#include "init.h"

#include <xc.h>

void initDAC(void)
{
    FVRCON = 0x00;
    FVRCONbits.CDAFVR = 0b01;   //1.024V for DACs
    
    FVRCONbits.EN = 1;
    
    //Wait for the FVR to be stable
    while (!FVRCONbits.RDY) { ; }
    
    DAC2CON = 0x20;
    DAC2CONbits.PSS = 0b10;     //FVR
    
    DAC2DATL = 0;
    
    DAC2CONbits.EN = 1;
}

void initCMP(void)
{
    CM1CON0 = 0x00;

    CM1CON1 = 0x00;
    
    //RC2 (C1IN2-)
    CM1NCH = 0x02;
    TRISC2 = 1;
    ANSELC2 = 1;
    
    //DAC2 OUT
    CM1PCH = 0x05;
    
    TRISB6 = 0;
    RB6PPS = 0x19;                 //C1OUT (Comparator Output)
    CM1CON0bits.C1EN = 1;
}

void initOPA(void)
{
    OPA1CON0 = 0x00;
    
    OPA1CON1 = 0x00;
    OPA1CON1bits.RESON = 1;     //Enable Resistor Ladder
    OPA1CON1bits.GSEL = 0b110;  //Gain of 8
    OPA1CON1bits.NSS = 0b111;   //Ground bottom of resistor ladder
    
    OPA1CON2 = 0x00;
    OPA1CON2bits.NCH = 0b001;   //Resistor Ladder
    OPA1CON2bits.PCH = 0b010;   //Pin Input
    
    OPA1CON3 = 0x00;
    OPA1CON3bits.FMS = 0b10;    //OPAxOUT Feedback
    OPA1CON3bits.PSS = 0b00;    //Select In0+
    
    OPA1HWC =  0x00;
    OPA1ORS =  0x00;
    
    //Enable the Module
    OPA1CON0bits.EN = 1;
}

void initTMR2(void)
{
    T2CON = 0x00;       //1:1 pre and post scaler
    T2HLT = 0x00;       //No Sync, rising edge, Free running mode
    T2CLKCON = 0x04;    //LFINTOSC 
    
    T2PR = 124;         //Period of 4ms
        
    //Enable Interrupt
    PIR3bits.TMR2IF = 0;
    PIE3bits.TMR2IE = 1;

    T2CONbits.ON = 1;   //Turn on the Timer
}