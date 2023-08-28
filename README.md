# Arduino-Joystick
Arduino joystick module (HW-504) to play various online games. 

Usage instructions:
1. Make sure you have `python` and the relevant packages installed.
* You will need the `serial` library to allow access to serial ports: `pip install pyserial`
* You will need the `pyautogui` library to allow keyboard/mouse inputs: `pip install pyautogui`
2. Upload the code to the arduino first, and then close the arduino IDE: serial communication requires the COM port to be available and both programs cannot be run simultaneously.
3. In the python script, change the variable `comport` to be your device's port number. 
4. Execute the python script by running: `py script.py` 
5. To stop the code, press `CTRL` + `C`

Hardware connections:
* Pins `A0`, `A1` connected to `VRx`, `VRy` respectively
* Pins `2`, `4`, `7` connected to pushbutton ground leg
* `3*pulldown resistors` required to pull input voltage down to `0`: allows default (unpressed) state of pushbutton to be logic level `0`

# Subway Surfer Demo
No additional pushbutton peripherals were required, as the game was playable with only the up, down, left and right arrow keys. 

Game link: https://subway-surfers.me/

# Tetris Demo
Additional pushbuttons were required to rotate left, right, and hard drop the block. These were configured according to my settings in the online game:
* "a" for `rotate left`
* " " for `hard drop`
* "d" for `rotate right`

Game link: https://www.freetetris.org/game.php
