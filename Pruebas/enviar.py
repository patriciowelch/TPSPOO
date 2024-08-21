import webbrowser
import pyautogui
import time

# Ruta completa al ejecutable de Opera GX
opera_path = "C:/Users/patri/AppData/Local/Programs/Opera GX/opera.exe"

# Registrar Opera GX como navegador
webbrowser.register('operagx', None, webbrowser.BackgroundBrowser(opera_path))
telefonos = [2615116792, 
             2634521357, 2612432259, 2615113147, 2622369514, 2616791642, 2612069140, 
             2920273179, 2616405861, 2664856570, 2615875195, 2616793607, 2612060074, 
             2612512028, 3812018866, 2615433401, 2616820963]
mensaje = "https://chat.whatsapp.com/GXNhHhdzeLoEVkucwmlaBu"


for telefono in telefonos:
    promp = "wa.me/{telefono}?text={mensaje}".format(telefono=telefono, mensaje=mensaje)
    print(promp)
    # Abrir en Opera GX
    webbrowser.open(promp)
    #mover mouse a 350, 350
    pyautogui.moveTo(700, 350, duration=0)
    time.sleep(5)
    pyautogui.click()
    time.sleep(5)
    pyautogui.moveTo(700, 440, duration=0)
    time.sleep(2)
    pyautogui.click()
    time.sleep(20)
    pyautogui.press('enter')
    time.sleep(2)
    pyautogui.moveTo(595, 18, duration=0)
    time.sleep(1)
    pyautogui.click()
    time.sleep(2)
