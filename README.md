# wakemypi
Wake Up a Raspberry Pi with a Arduino Board to save Energy

The plan is to connect the Raspberry Pi (RPi) with a Arduino Board via Serial.
The RPi commands the Arduino to wake him up in n-milliseconds (max 4,294,967,295).
The Arduino is giving a "OK" back and sets the delay timer. Only then the Rpi should shut down (shutdown -h now).
When the delay is over, the Arduino sets a HIGH on the 4N45 pin to short the RUN pins of the RPi.

When the Arduino starts, the RPi gets a hard Reset (RUN pins short) too. 


## Circuit

I want to develop a Circuit where the logic level from the Raspberry Pi (3,3V) is convertet to the level of the Arduino (5V).

Also i want a Optocuppler (4N35) for switching the RUN Pin of the Raspberry Pi.

[https://circuits.io/circuits/5854598-wakemypi](https://circuits.io/circuits/5854598-wakemypi)

## Pinout

### Arduino Nano

Pin nr. | desc. | dest
1 | D3 | Singal LED

31|Tx|LLC HV3
30|Rx|LLC HV4
GND|GND|LLC HV GND
GND|GND|Signal LED
GND|GND|4N35 Pin 2 (Cathode)
32|D2|100Ohm - 4N35 Pin 1 (Anode)
5V|5V|LLC HV Vin

### RPi

Pin nr.|desc|dest
1|3.3 VDC|LLC LV Vin
6|GND|LLC LV GND
8|Tx|LLC LV 4
10|Rx|LLC LV 3
RUN 3.3V|RUN 3.3 V|4N35 Pin 5 (Colector)
RUN GND|RUN GND|4N35 Pin 4 (Emitter)



## PCB (comming soon)
