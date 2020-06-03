//
//// PIC18F16Q41 Configuration Bit Settings
//
//// 'C' source line config statements
//
//// CONFIG1
//#pragma config FEXTOSC = OFF    // External Oscillator Selection (Oscillator not enabled)
//#pragma config RSTOSC = HFINTOSC_64MHZ// Reset Oscillator Selection (HFINTOSC with HFFRQ = 64 MHz and CDIV = 1:1)
//
//// CONFIG2
//#pragma config CLKOUTEN = OFF   // Clock out Enable bit (CLKOUT function is disabled)
//#pragma config PR1WAY = ON      // PRLOCKED One-Way Set Enable bit (PRLOCKED bit can be cleared and set only once)
//#pragma config CSWEN = ON       // Clock Switch Enable bit (Writing to NOSC and NDIV is allowed)
//#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor enabled)
//#pragma config FCMENP = ON      // Fail-Safe Clock Monitor - Primary XTAL Enable bit (Fail-Safe Clock Monitor enabled; timer will flag FSCMP bit and OSFIF interrupt on EXTOSC failure.)
//#pragma config FCMENS = ON      // Fail-Safe Clock Monitor - Secondary XTAL Enable bit (Fail-Safe Clock Monitor enabled; timer will flag FSCMP bit and OSFIF interrupt on SOSC failure.)
//
//// CONFIG3
//#pragma config MCLRE = EXTMCLR  // MCLR Enable bit (If LVP = 0, MCLR pin is MCLR; If LVP = 1, RE3 pin function is MCLR )
//#pragma config PWRTS = PWRT_OFF // Power-up timer selection bits (PWRT is disabled)
//#pragma config MVECEN = ON      // Multi-vector enable bit (Multi-vector enabled, Vector table used for interrupts)
//#pragma config IVT1WAY = ON     // IVTLOCK bit One-way set enable bit (IVTLOCKED bit can be cleared and set only once)
//#pragma config LPBOREN = OFF    // Low Power BOR Enable bit (Low-Power BOR disabled)
//#pragma config BOREN = SBORDIS  // Brown-out Reset Enable bits (Brown-out Reset enabled , SBOREN bit is ignored)
//
//// CONFIG4
//#pragma config BORV = VBOR_1P9  // Brown-out Reset Voltage Selection bits (Brown-out Reset Voltage (VBOR) set to 1.9V)
//#pragma config ZCD = OFF        // ZCD Disable bit (ZCD module is disabled. ZCD can be enabled by setting the ZCDSEN bit of ZCDCON)
//#pragma config PPS1WAY = ON     // PPSLOCK bit One-Way Set Enable bit (PPSLOCKED bit can be cleared and set only once; PPS registers remain locked after one clear/set cycle)
//#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
//#pragma config LVP = ON         // Low Voltage Programming Enable bit (Low voltage programming enabled. MCLR/VPP pin function is MCLR. MCLRE configuration bit is ignored)
//#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Extended Instruction Set and Indexed Addressing Mode disabled)
//
//// CONFIG5
//#pragma config WDTCPS = WDTCPS_31// WDT Period selection bits (Divider ratio 1:65536; software control of WDTPS)
//#pragma config WDTE = OFF       // WDT operating mode (WDT Disabled; SWDTEN is ignored)
//
//// CONFIG6
//#pragma config WDTCWS = WDTCWS_7// WDT Window Select bits (window always open (100%); software control; keyed access not required)
//#pragma config WDTCCS = SC      // WDT input clock selector (Software Control)
//
//// CONFIG7
//#pragma config BBSIZE = BBSIZE_512// Boot Block Size selection bits (Boot Block size is 512 words)
//#pragma config BBEN = OFF       // Boot Block enable bit (Boot block disabled)
//#pragma config SAFEN = OFF      // Storage Area Flash enable bit (SAF disabled)
//#pragma config DEBUG = OFF      // Background Debugger (Background Debugger disabled)
//
//// CONFIG8
//#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot Block not Write protected)
//#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers not Write protected)
//#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM not Write protected)
//#pragma config WRTSAF = OFF     // SAF Write protection bit (SAF not Write Protected)
//#pragma config WRTAPP = OFF     // Application Block write protection bit (Application Block not write protected)
//
//// CONFIG9
//#pragma config CP = OFF         // PFM and Data EEPROM Code Protection bit (PFM and Data EEPROM code protection disabled)
//
//#define _XTAL_FREQ 64000000
//
//// #pragma config statements should precede project file includes.
//// Use project enums instead of #define for ON and OFF.
//
//#include <xc.h>
//#include "init.h"
//
////Super simple state machine that makes the LED "breathe"
//void __interrupt(irq(TMR2)) changeCurrent(void)
//{
//    static char state = 0;
//    if (state == 0)
//    {
//        if (DAC2DATL == 0xFF)
//        {
//            state = 1;
//        }
//        else
//        {
//            DAC2DATL++;
//        } 
//    }
//    else
//    {
//        if (DAC2DATL == 0x00)
//        {
//            state = 0;
//        }
//        else
//        {
//            DAC2DATL--;
//        } 
//    }
//    PIR3bits.TMR2IF = 0;
//}
//
//void main(void) {
//    
//    TRISB7 = 0;
//    LATB7 = 0;
//    
//    initDAC();
//    initOPA();
//    initCMP();
//    initTMR2();
//    
//    //Enable Interrupts
//    INTCON0bits.GIE = 1;
//            
//    while (1)
//    {
//        //User defined code goes here
//    }
//    
//    return;
//}
