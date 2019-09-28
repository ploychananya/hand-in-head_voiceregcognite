# Hand in Head
Controll mouse cursor by using head movement and voice command.

Department of Computer Engineering, Faculty of Engineering, Kasetsart University.

## File Description
	* firmware/master-arduino-ide : a firmware source code for main practicum board that connected with gyro sensors.
	* firmware/second-avr-firmware : a firmware source code for second practicum board that connected with Peripheral sensor board.
	* firmware/python : a python script that provide speech recognite function and control the second practicum board.
	* schematic.pdf : schematic diagram.

## Flashing main firmware into main Practicum Board
- open firmware/arduino-ide/main.ino using Arduino IDE
- click upload button.
## Flashing second firmware into second Practicum Board


## Install required package for project's python script.
- sudo apt-get install python3-pip 
- sudo pip3 install SpeechRecognition
- sudo apt-get install python-xlib scrot python3-tk python3-dev python3-setuptools
- pip install pyautogui
- sudo pip install pillow
- pip install pillow --global-option="build_ext" --global-option="--debug"

## Hardware for this project
	* Practicum Board v3 - ATmega168 microcontroller
	* GY-521 MPU6050 Accelerometer/Gyro Module
	* Microphone for PC
	* LED - Peripheral board
