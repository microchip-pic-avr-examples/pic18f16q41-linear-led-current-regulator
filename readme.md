<!-- Please do not change this html logo with link -->
<a href="https://www.microchip.com" rel="nofollow"><img src="images/microchip.png" alt="MCHP" width="300"/></a>

# Linear LED Current Regulator using PIC18F16Q41
Using only a few peripherals, the PIC18F16Q41 can be used as a linear constant current regulator for an LED based load. The key to this code example is the Q41's operational amplifier (OPA) module that directly controls the MOSFET which acts as a low-side current regulator. The output of the OPA is controlled by using the digital-to-analog (DAC) converter.

## Related Documentation

<a href="https://www.microchip.com/wwwproducts/en/PIC18F16Q41">PIC18F16Q41 Product Information</a><br>
TBxxxx, "Using Operational Amplifiers in PIC16 and PIC18"<br>
TBxxxx, "Optimizing Internal Operational Amplifiers for Analog Signal Conditioning"<br>
ANxxxx, "Analog Sensor Measurement and Acquisition"<br>
<a href="https://github.com/microchip-pic-avr-examples/pic18f16q41-switching-led-current-regulator">Code Example: Switching LED Current Regulator</a><br>

## Software Used

* <a href="http://www.microchip.com/mplab/mplab-x-ide">MPLAB® IDE 5.40 or newer</a>
* <a href="https://www.microchip.com/mplab/compilers">Microchip XC8 Compiler 2.20 or newer</a>
* <a href="https://www.microchip.com/mplab/mplab-code-configurator">MPLAB® Code Configurator (MCC) 3.95.0 or newer</a>

## Hardware Used

* <a href="https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/DM164137"> Microchip Curiosity Development Board (DM164137) </a>

## External Parts Required

* 5.6 ohm resistor (current shunt)
* *(Optional)* 100k resistor
    * This resistor discharges the capacitor passively and ensures the MOSFET remains off if the part is off or the pin is tri-stated. For this example, it is not needed.
* N-Type MOSFET (rec. signal transistor, such as a 2N7000A)
* LED(s)

#### Power Dissipation
Before building or operating this demo, ensure that the parts selected for this demo are appropriately rated for the peak power of this circuit.

## Wiring
<img src="images/schematic.png" alt="Schematic" width="500px"/><br>

| Pin | Function
| --- | --------
| RB5 | Current Sense Input
| RC2 | OPA1OUT (Connect to the gate of the MOSFET)

## Operation
This code example configures the DAC2 to generate a triangle wave output that is used by the operational amplifier to set the current through the LED. The operational amplifier tries to set the current through the shunt resistor such that the voltage on the shunt (I x Rs) is equal to output of the DAC. 

The output current is approximately equal to **Iout = Vdac / 6.8**.

<img src="images/waveform.PNG" alt="Waveform" width="500px"/><br>
*Voltage Across the Shunt Resistor*

#### Short Circuit Protection
Due to the MOSFET acting as voltage controlled current sink, there is some short circuit protection built into the circuit. However, it is not recommended to depend on this circuit as the only means of protection. Prolonged short circuits may cause heating of the FET and shunt.

## Summary
This code example demonstrates the PIC18F16Q41's operational amplifier in use as a current regulator for LEDs.   
