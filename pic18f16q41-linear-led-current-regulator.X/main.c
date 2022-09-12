 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
*/

/*
© [2022] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/
#include "mcc_generated_files/system/system.h"

#include <stdbool.h>
#include <stdint.h>

/* 
 * This value sets the maximum current
 * 
 * Vref / Rsense = Imax
 * Imax / 256 = Ires
 * Ires * Value = Ilim
 * 
 * With 1.024V = Vref, 6.8 = Rsense
 * Imax = ~150mA, Ires = 585uA per bit
 * Ilim = ~17.6mA
 */
#define CURRENT_LIMIT 30

void LED_stateMachine(void)
{
    static bool isRising = true;
    static uint8_t dacValue = 0x00;
    
    if (isRising)
    {
        //Brightness level is rising
        
        if (dacValue == CURRENT_LIMIT)
        {
            isRising = false;
        }
        else
        {
            dacValue++;
        }
    }
    else
    {
        //Brightness level is falling
        
        if (dacValue == 0x00)
        {
            isRising = true;
        }
        else
        {
            dacValue--;
        }
    }
    
    DAC2_SetOutput(dacValue);
}

int main(void)
{
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts 
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts 
    // Use the following macros to: 

    Timer2_OverflowCallbackRegister(&LED_stateMachine);
    
    // Enable the Global Interrupts 
    INTERRUPT_GlobalInterruptEnable(); 

    // Disable the Global Interrupts 
    //INTERRUPT_GlobalInterruptDisable(); 


    while(1)
    {
    }    
}