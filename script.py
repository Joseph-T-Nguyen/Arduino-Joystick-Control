# Note: Before executing the script, make sure arduino IDE is closed
# Serial communication => requires COM port to be available and both programs cannot be run simultaneously
# Upload code to Uno and close program

import serial       # allows access to serial ports 
import pyautogui    # allows keyboard/mouse inputs

signalLeft  = b'A'  # move left
signalRight = b'D'  # move right
signalDown  = b'S'  # move down
signalUp    = b'W'  # move up
signalB1    = b'B'  # Optional button 
signalB2    = b'Z'  # Optional button 
signalB3    = b'U'  # Optional button

comport = "COM7"
ser = serial.Serial(comport, 9600)

# Dictionary for default joystick signals
signal_actions = {
    signalLeft: 'left',
    signalRight: 'right',
    signalDown: 'down',
    signalUp: 'up'
}

buttons_required = False
invalid_input = True

# Check if buttons are required for the program
while invalid_input:
    buttons_req = input("Buttons required? Y/N: ")
    if buttons_req == 'Y':
        buttons_required = True
        invalid_input = False
    elif buttons_req == 'N':
        invalid_input = False
    else:
        print("Invalid Input")

# only if buttons are required, let user select functionality
if buttons_required:
    signal_actions[signalB1] = input("Configure button 1: ")
    signal_actions[signalB2] = input("Configure button 2: ")
    signal_actions[signalB3] = input("Configure button 3: ")
else:
    # Defaults to 'space' if button is not required
    signal_actions[signalB1] = ' '
    signal_actions[signalB2] = ' '
    signal_actions[signalB3] = ' '

# Main loop
while True:
    signal = ser.read() # Read the signal once (signal might change midway through loop)
    action = signal_actions.get(signal) # get corresponding signal
    if action:
        pyautogui.press(action)

    
