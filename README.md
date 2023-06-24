# Project-Gardenia
A simple houseplant monitoring system with separate modules for each type of plant.
Meant to be used in conjunction with Thingspeak Cloud channels, with the following hardware:
1. NodeMCU ESP8266 microcontroller
2. DHT11 temperature and humidity sensor
3. Analog resistive soil moisture sensor

This project was created originally for a college hardware project competition.
Contributors: Urmika Chakraborty, Rajshekhar Bit, Sampriti Sarkar, Sayak Das, Rudradeep Kundu.

Directions:
1. Extract the files from the ZIP.
2. Note the path of each individual .ino file. The .ino files will require their own separate folders to run.
3. Open Select.vbs in editing mode using Notepad and copy the file paths into the "Path" placeholder.
4. When running, select "ESP-12E module" in the Boards section of the Arduino IDE. (Note: If not already installed, you may have to download the ESP series boards
   into the board manager)
5. Ensure that you have the correct COM port driver in your computer. Select the required COM port in the IDE.
6. Add your Wifi name (SSID), Wifi password, channel number and API key in the specified places in the code.
7. Run Select.vbs and open your required file with the corresponding numeric input in the textbox.
8. Compile and upload the code when you connect the ESP8266 with your computer.
9. Open the serial monitor to check connection status.
10. Use either the serial monitor or your ThingSpeak cloud channel to monitor plant health.

Further improvements: Addition of automation, watering system and CO2 sensor provisions.
Updated occassionally.
