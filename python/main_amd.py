import serial
import time
from pyadl import *

ser = serial.Serial('COM3', 9600) #change the com to your arduino port(it might be COM4 or whatever)

def send_string(ser, string_value):
    ser.write(string_value.encode())


def get_gpu_temperature():
    device = ADLManager.getInstance().getDevices()[0]
    gpu_temp = device.getCurrentTemperature()
    return gpu_temp

while True:
    string_value = str(get_gpu_temperature())
    send_string(ser, string_value)
    time.sleep(4.5)
