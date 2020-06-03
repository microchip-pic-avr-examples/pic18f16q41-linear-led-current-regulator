/**
  OPA1 Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    opa1.h

  @Summary
    This is the generated header file for the OPA1 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for OPA1.
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

#ifndef OPA1_H
#define OPA1_H

/**
  Section: Included Files
*/
#include <stdint.h>
#include <stdbool.h>

// Enumeration of R2/R1 resistor ratio
typedef enum
{
    OPA1_R2byR1_is_0dp07,
    OPA1_R2byR1_is_0dp14,
    OPA1_R2byR1_is_0dp33,
    OPA1_R2byR1_is_1,
    OPA1_R2byR1_is_1dp67,
    OPA1_R2byR1_is_3,
    OPA1_R2byR1_is_7,
    OPA1_R2byR1_is_15   
} OPA1_resistor_select;

// Enumeration of available Positive Channels
typedef enum
{
    OPA1_posChannel_Vss,
    OPA1_posChannel_GSEL,
    OPA1_posChannel_OPA1IN,
    OPA1_posChannel_Vdd_by_2,
    OPA1_posChannel_DAC1,
    OPA1_posChannel_DAC2
} OPA1_posChannel_select;

// Enumeration of available Positive Sources
typedef enum
{
    OPA1_RB5_OPA1IN0_plus = 0x0,   
    OPA1_RC3_OPA1IN1_plus = 0x1,   
    OPA1_RA2_OPA1IN2_plus = 0x2,   
    OPA1_RA0_OPA1IN3_plus = 0x3   
} OPA1_posSource_select;

// Enumeration of available Negative Channels
typedef enum
{
    OPA1_negChannel_No_Connection = 0x0,
    OPA1_negChannel_GSEL = 0x1,
    OPA1_negChannel_OPA1IN = 0x2,
    OPA1_negChannel_DAC1 = 0x4,
    OPA1_negChannel_DAC2 = 0x5
} OPA1_negChannel_select;

// Enumeration of available Negative Sources
typedef enum
{
    OPA1_RB4_OPA1IN0_minus = 0x0,   
    OPA1_RC3_OPA1IN1_minus = 0x1,   
    OPA1_RA2_OPA1IN2_minus = 0x2,   
    OPA1_RA0_OPA1IN3_minus = 0x3,   
    OPA1_Vss = 0x7   
} OPA1_negSource_select;

/**
 * @brief Initializes the OPA1 module
 *        This routine must be called before any other OPA1 routine
 * @return None
 * @param None
 */
void OPA1_Initialize(void);

/**
 * @brief Enables OPA1 to operate with unity gain 
 * @return None
 * @param None
 */
inline void OPA1_EnableSoftwareUnityGain(void);

/**
 * @brief Sets the positive channel as per user selection
 * @return None 
 * @param [in] Desired positive channel
          For available positive channels refer OPA1_posChannel_select enum from opa1.h file
 */
inline void OPA1_SetPositiveChannel(OPA1_posChannel_select posChannel);

/**
 * @brief Sets the positive source as per user selection
 * @return None 
 * @param [in] Desired positive source
          For available positive sources refer OPA1_posSource_select enum from opa1.h file
 */
inline void OPA1_SetPositiveSource(OPA1_posSource_select posSource);

/**
 * @brief Sets the negative channel as per user selection
 * @return None 
 * @param [in] Desired negative channel
          For available negative channels refer OPA1_negChannel_select enum from opa1.h file
 */
inline void OPA1_SetNegativeChannel(OPA1_negChannel_select negChannel);

/**
 * @brief Sets the negative source as per user selection
 * @return None 
 * @param [in] Desired negative source
          For available negative sources refer OPA1_negSource_select enum from opa1.h file
 */
inline void OPA1_SetNegativeSource(OPA1_negSource_select negSource);

/**
 * @brief Sets the R1 and R2 values of internal resistor ladder as per user selection
 * @return None 
 * @param [in] Desired resistor selection
               For available resistor values refer OPA1_resistor_sel enum from opa1.h file
 */
void OPA1_SetResistorLadder(OPA1_resistor_select resistorSelection);

/**
 * @brief Enables hardware override by setting the override enable bit
 * @return None 
 * @param None
 */
inline void OPA1_EnableHardwareOverride(void);

/**
 * @brief Selects the Hardware Override Source and polarity
          The OPA1_EnableHardwareOverride() routine must be called before this routine
 * @return None 
 * @param [in] Desired hardware override source and source polarity
 */
void OPA1_SetHardwareOverrideSource(uint8_t overrideSource, uint8_t polarity);

/**
 * @brief Disables the hardware override by clearing the override enable bit
 * @return None 
 * @param None
 */
inline void OPA1_DisableHardwareOverride(void);

/**
 * @brief Selects the Software Override Mode
          The OPA1_DisableHardwareOverride() routine must be called before this routine
 * @return None 
 * @param [in] Desired software override mode
 */
inline void OPA1_SetSoftwareOverride(uint8_t softwareControl);

/**
 * @brief Sets the input offset calibration 
 * @return None 
 * @param [in] Desired input offset
 */
inline void OPA1_SetInputOffset(uint8_t offset);

#endif //OPA1_H  