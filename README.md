# Battery Monitoring System
LCD display of a battery voltage and temperature with a warning circuit
# Features
* The acquisition of the temperature of a battery on the interval of **[0°c 60°c]**
  >Using 10-bit converter A/D
* The acquisition of the voltage of a battery on the interval of **[0V 12V]**
  >Using 10-bit converter A/D with resolution of **11.7mV**
* Visual Warning (**red flag**) when temperature is above of 30°c 
* Visual Warning (**Blinking two Leds**) when voltage is under 20% of its capacity
* Treatment & Displaying data 
  >Using 2x16 LCD display
# Materials & circuit
* **Microchip** 8bit_microcontroller **PIC16F877**
* 2x16 **LCD display**
* Voltage divider circuit
* **8_Mhz** clock frequency based on Crystal circuit
* Blinking Leds circuit
# The Schematic Circuit
![Capture d’écran 2021-01-26 174651](https://user-images.githubusercontent.com/61091193/105875872-9f11ae00-5ffe-11eb-9701-bf223a96cf29.png)
## Software Tools
* ISIS Proteus 8.9 Professional
  >Circuit's Simulation
* MikroC Pro for PIC
  >Programming the PIC16F877
## Research sources
   How Heat and Loading affect Battery Life [batteryuniversity.com](https://batteryuniversity.com/learn/article/how_heat_and_harsh_loading_reduces_battery_life)
