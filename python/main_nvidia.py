import serial
import time
import pynvml

ser = serial.Serial('COM3', 9600) #change the com to your arduino port(it might be COM4 or whatever)


def send_string(ser, string_value):
    ser.write(string_value.encode())


def get_gpu_temperature():
    pynvml.nvmlInit()
    handle = pynvml.nvmlDeviceGetHandleByIndex(0)
    gpu_info = pynvml.nvmlDeviceGetTemperature(handle, pynvml.NVML_TEMPERATURE_GPU)
    return gpu_info



while True:
    string_value = str(get_gpu_temperature())
    send_string(ser, string_value)
    time.sleep(4.5)
