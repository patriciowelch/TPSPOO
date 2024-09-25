import pyautogui
import time
time.sleep(5)
with open('G:\\Otros ordenadores\\Mi PC\\UNIVERSIDAD\\8S\\POO\\TPSPOO\\Pruebas\\shrek.txt') as f:
    lines = f.readlines()
    for line in lines:
        if line != '\n':
            pyautogui.typewrite(line)
            time.sleep(0.2)