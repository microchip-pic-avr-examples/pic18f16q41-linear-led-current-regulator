<a href="https://www.microchip.com" rel="nofollow"><img src="images/microchip.png" alt="MCHP" width="300"/></a>

# Linear LED Current Regulator using PIC18F16Q41
Using only a few peripherals, the PIC18F16Q41 can be used as a linear constant current regulator for an LED based load. The key to this code example is the Q41's operational amplifier (OPA) module that directly controls the MOSFET which acts as a low-side current regulator. The output of the OPA is controlled by using the digital-to-analog (DAC) converter.

## Related Documentation

[TB3280: Using Operational Amplifiers in PIC16 and PIC18](http://ww1.microchip.com/downloads/en/DeviceDoc/Using-the-Operational-Amplifier-on-PIC16-and-PIC18-90003280A.pdf)  
[TB3279: Optimizing Internal Operational Amplifiers for Analog Signal Conditioning](http://ww1.microchip.com/downloads/en/DeviceDoc/Optimizing-Internal-Operational-Amplifiers-for-Analog-Signal-Conditioning-90003279A.pdf)  
[AN3521: Analog Sensor Measurement and Acquisition](https://www.microchip.com/en-us/application-notes/an3521)  

[Code Example: PWM LED Current Regulator](https://github.com/microchip-pic-avr-examples/pic18f16q41-pwm-led-current-regulator)  

## Software Used

* [MPLAB® IDE 6.00 or newer](https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide?utm_source=GitHub&utm_medium=TextLink&utm_campaign=MCU8_MMTCha_pic18q41&utm_content=pic18f16q41-linear-led-current-regulator)
* [Microchip XC8 Compiler 2.40 or newer](https://www.microchip.com/en-us/tools-resources/develop/mplab-xc-compilers?utm_source=GitHub&utm_medium=TextLink&utm_campaign=MCU8_MMTCha_pic18q41&utm_content=pic18f16q41-linear-led-current-regulator)
* [MPLAB® Code Configurator (MCC) 4.1.16 or newer](https://www.microchip.com/en-us/tools-resources/configure/mplab-code-configurator?utm_source=GitHub&utm_medium=TextLink&utm_campaign=MCU8_MMTCha_pic18q41&utm_content=pic18f16q41-linear-led-current-regulator)

## Hardware Used

**Note: Version 2.0.0 of this project switched to the Curiosity Nano and modified the circuit.**

* [PIC18F16Q41 Curiosity Nano Evaluation Kit (EV26Q64A)](https://www.microchipdirect.com/product/EV26Q64A?utm_source=GitHub&utm_medium=TextLink&utm_campaign=MCU8_MMTCha_pic18q41&utm_content=pic18f16q41-linear-led-current-regulator)
* [Curiosity Nano Adapter Board (AC164162)](https://www.microchip.com/en-us/development-tool/AC164162?utm_source=GitHub&utm_medium=TextLink&utm_campaign=MCU8_MMTCha_pic18q41&utm_content=pic18f16q41-linear-led-current-regulator)

## External Parts Required

* 6.8 ohm resistor (current shunt)
* 100k ohm resistor
    * This resistor ensures the MOSFET remains off if the part is off or not configured.
* 10k resistor (*Optional*)
    * This resistor protects the device in the event of an over-voltage transient. See **Higher Voltage Operation** for details. If not used, replace with a jumper wire.
* Capacitor (*Optional*)
    * This capacitor can reduce oscillations in the power supply caused by the changing current draw of the LED. 
* N-Type MOSFET
    * For this demo, a small signal transistor such as a 2N7000A is recommended. 
* LED(s)
    * Red is recommended due to the lower voltage drop. 

#### Power Dissipation
Before building or operating this demo, ensure that the parts selected for this demo are appropriately rated for the peak power of this circuit. The transistor used will be running in the linear region. The default current limit is set to 17.5mA. 

## Wiring
![Schematic Diagram](./images/schematic.png)

**Note: VDD can be 3.3V or 5V. However, 5V should be used with a protection resistor, as the nano runs on 3.3V by default.**

| Pin | Function
| --- | --------
| RC2 | OPA1OUT (Connect to the gate of the MOSFET)  
| RC3 | Current Sense Input  

## Operation
![LED Demo GIF](./images/Demo.gif)  
*Example Output*

This code example configures the DAC2 to generate a triangle wave output that is used by the operational amplifier to set the current through the LED. The operational amplifier tries to set the current through the shunt resistor such that the voltage on the shunt (I x Rs) is equal to output of the DAC.

The output current is approximately equal to **Iout = Vdac / 6.8**.

![Waveform Output](images/waveform.PNG)  
*Voltage Across the Shunt Resistor*

#### Short Circuit Protection
Due to the MOSFET acting as voltage controlled current sink, there is some short circuit protection built into the circuit. However, it is not recommended to depend on this circuit as the only means of protection. Prolonged short circuits may cause heating of the FET and shunt.

#### Higher Voltage Operation
It is possible to run the LED supply at a voltage much higher than Vdd. Parts used must be evaluated for power dissipation and operating voltage. In addition, protecting the PIC18F16Q41 from voltages higher than Vdd is critical. A simple resistor from the current sense pin to the Operational Amplifier input provides basic protection, although this has not been tested and characterized. (The protection network must be analyzed with regards to the specific conditions in circuit.)

**Warning: The input to any power or I/O pin on the PIC18F16Q41 must remain within the absolute maximum ratings stated in the device datasheet, otherwise permanent damage may occur.**

#### Power Supply Oscillations
In some setups with high inductance on the power supply, small oscillations may occur in the waveform. In the event this occurs (generally with external supplies that have long leads), decoupling the LED supply near the LEDs assists in reducing or removing this effect. 

**Note: Small gltiches in the output function are not caused by this. This is due to the settling time in the DAC and OPAMP.**

## Summary
This code example demonstrates the PIC18F16Q41's operational amplifier in use as a current regulator for LEDs.   
