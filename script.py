# Note: Before executing the script, make sure arduino IDE is closed
# Serial communication => requires COM port to be available and both programs cannot be run simultaneously
# Upload code to Uno and close program

import serial       # allows access to serial ports 
import pyautogui    # allows keyboard/mouse inputs

signalLeft = b'A'   # move left
signalRight = b'D'  # move right
signalDown = b'S'   # move down
signalDrop = b'B'   # drop/spacebar
signalRotateL = b'Z' # rotate block left
signalRotateR = b'U' # rotate block right

comport = "COM7"
ser = serial.Serial(comport, 9600)

while True:
    signal = ser.read() # Read the signal once (signal might change midway through loop)
    if signal == signalLeft:
        pyautogui.press('left')
    elif signal == signalRight:
        pyautogui.press('right')
    elif signal == signalDown:
        pyautogui.press('down')
    elif signal == signalDrop:
        pyautogui.press('space')
    elif signal == signalRotateL:
        pyautogui.press('z')
    elif signal == signalRotateR:
        pyautogui.press('up')

