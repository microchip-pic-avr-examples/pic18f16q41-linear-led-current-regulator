/**
  OPA1 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    opa1.c

  @Summary
    This is the generated driver implementation file for the OPA1 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides implementations for driver APIs for OPA1.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.0
        Device            :  PIC18F16Q41
        Driver Version    :  1.0.0
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.10 and above or later
        MPLAB             :  MPLAB X 5.35
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

/**
  Section: Included Files
*/

#include <xc.h>
#include "opa1.h"


void OPA1_Initialize(void)
{
    //GSEL R1 = 15R and R2 = 1R, R2/R1 = 0.07; RESON Disabled; NSS OPA1IN0-; 
    OPA1CON1 = 0x00;

    //NCH OPA1IN-; PCH DAC2_OUT; 
    OPA1CON2 = 0x25;

    //FMS No Connection; PSS OPA1IN0+; 
    OPA1CON3 = 0x00;

    //OREN Software Override; HWCH User Defined Feedback; ORPOL Non Inverted; HWCL User Defined Feedback; 
    OPA1HWC = 0x00;

    //ORS LFINTOSC; 
    OPA1ORS = 0x00;    

    //EN Enabled; UG OPAIN- pin; SOC User Defined Feedback; 
    OPA1CON0 = 0x80;
}

inline void OPA1_EnableSoftwareUnityGain(void)
{
    OPA1CON0bits.UG = 1;
}

inline void OPA1_SetPositiveChannel(OPA1_posChannel_select posChannel)
{
    OPA1CON2bits.PCH = posChannel;
}

inline void OPA1_SetPositiveSource(OPA1_posSource_select posSource)
{
    OPA1CON3bits.PSS = posSource;
}

inline void OPA1_SetNegativeChannel(OPA1_negChannel_select negChannel)
{
    OPA1CON2bits.NCH = negChannel;
}

inline void OPA1_SetNegativeSource(OPA1_negSource_select negSource)
{
    OPA1CON1bits.NSS = negSource;
}

void OPA1_SetResistorLadder(OPA1_resistor_select resistorSelection)
{
    OPA1CON1bits.RESON = 1;
    OPA1CON1bits.GSEL = resistorSelection;
}

inline void OPA1_EnableHardwareOverride(void)
{
   OPA1HWCbits.OREN = 1;
}

void OPA1_SetHardwareOverrideSource(uint8_t overrideSource, uint8_t polarity)
{
    OPA1ORS = overrideSource;
    OPA1HWCbits.ORPOL = polarity;
}

inline void OPA1_DisableHardwareOverride(void)
{
    OPA1HWCbits.OREN = 0;
}

inline void OPA1_SetSoftwareOverride(uint8_t softwareControl)
{
    OPA1CON0bits.SOC = softwareControl;
}

inline void OPA1_SetInputOffset(uint8_t offset)
{
    OPA1OFFSET = offset;
}

