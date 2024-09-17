# GPU Temperature Monitoring with Arduino

This project allows you to monitor the temperature of your AMD or NVIDIA GPU using an Arduino, along with visual feedback via a TM1637 seven-segment display and WS2812b ARGB LEDs. You can modify the code to display various GPU metrics (such as temperature, usage, or clock speeds) and even CPU temperature (on Linux).

## Features
- Monitors GPU temperature (AMD or NVIDIA)
- Displays GPU temperature on a TM1637 seven-segment display
- Provides three LED effects for WS2812b ARGB LEDs based on temperature ranges
- Supports custom display and effects based on temperature or GPU usage
- Compatible with multiple Arduino boards (tested with Arduino Nano)

## Requirements

### Hardware
- **Arduino Nano** (or any other Arduino board)
- **TM1637 seven-segment display**
- **WS2812b ARGB LED strip**
- Optional: Other types of displays or LEDs

### Software
- **Arduino IDE**
- **Adafruit NeoPixel Library** (for WS2812b LEDs)
- **TM1637 Library** (for the seven-segment display)
- **Python (with `pynvml` for NVIDIA cards or equivalent for AMD)** to fetch GPU data

## Setup

1. **Connect the Hardware:**
   - Connect the TM1637 seven-segment display to your Arduino (DIO to a digital pin, CLK to another).
   - Connect the WS2812b ARGB LED strip to an appropriate data pin.
   
2. **Arduino Code:**
   - Upload the Arduino code to your board.
   - Modify the code if you want to monitor GPU usage, clock speed, or CPU temperature (Linux only).

3. **PC-to-Arduino Communication:**
   - Install the required Python libraries (e.g., `pynvml` for NVIDIA GPUs):
     ```bash
     pip install pynvml
     ```
   - Run a Python script to fetch the GPU data and send it to the Arduino via serial communication.
   
4. **Adjust LED Effects:**
   - Modify the WS2812b LED effects in the Arduino code to match your desired temperature thresholds and lighting patterns.

## Usage

1. Power on the Arduino.
2. Run the Python script on your PC to start monitoring the GPU temperature.
3. The seven-segment display will show the temperature, and the WS2812b LEDs will display different effects based on the temperature.

## LED Effects

By default, the project includes three simple LED effects based on GPU temperature:
- **Effect 1:** Cool temperatures (e.g., < 50°C) - Slow glowing effect.
- **Effect 2:** Medium temperatures (e.g., 50°C - 70°C) - Pulse effect.
- **Effect 3:** High temperatures (e.g., > 70°C) - Fast flicker or warning lights.

Feel free to customize these effects in the Arduino code to suit your needs.

## Customization

- **Change Metrics:**
  You can modify the code to monitor other metrics such as GPU usage, GPU clock, or even CPU temperature (Linux only).
  
- **Change Displays:**
  If you want to use a different display (e.g., OLED), modify the display logic in the Arduino code.
  
- **Change Arduino Board:**
  You can use any Arduino-compatible board, but ensure you update the pin assignments accordingly.

## How to Contribute

If you find a bug or have suggestions for new features, feel free to open an issue or submit a pull request!


## Have fun!

Enjoy monitoring your GPU and customizing the visual effects!
