# LED-Configutration-System:
This Arduino based system calculates the operation point voltage of any LED. 
The system utilizes the output voltage and current from arduino-uno to light up the connected LED as well us 16x2 LCD display. 
Since LEDs have a strict requiremnt for the right voltage and current (we assume 20mA), the right amount of resistance is obtained by calculation.
The operation point voltage is then read through analog pin of the microcontroler.
However, the analog signal is raw so to say. Therefore, The signal needs conversion to digital one before we manipulate it with our to-be embedded code.
AD converter on our microcontroler can do the conversion quite cleverly. The integrated AD converter descretizes 0-5v analog(continuos time) value in to the range of 
0-1023(descret time) values and convert the reading to the nearest value in the range. 
Last but not least, This digital value is again converted to 0-5v format before sending it to the 16x2 LCD display. This task will be handled through coding. further information about LED including operation voltage at different forward voltage and the required amount of ressistance will also be displayed on the LCD. 
the circuit also contains a potentiometer which will be used to control the contrast of the LCD. 

Required hardware Components:

    1. Arduino Uno
	2. Interfacing (power) Cable
	3. Breadboard
	4. 150 Ohm, 220 Ohm Resistors
	5. 10K potentiometer
	6. Wires 19x
	7. LED
	8. 16x2 LCD Display
