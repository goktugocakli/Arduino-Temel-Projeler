import serial
import time
import webbrowser

arduino = serial.Serial(port="/dev/cu.usbserial-110", baudrate=9600, timeout=.1)

while True:
    if arduino.in_waiting > 0:
        veri = arduino.readline().decode('utf-8').rstrip()  # Seri porttan veriyi al ve decode et
        print("Arduino'dan gelen veri:", veri)
        if veri=="1":
            webbrowser.open("https://www.arduino.cc/reference/en/")
            break
