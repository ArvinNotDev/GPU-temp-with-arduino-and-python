#include <TM1637Display.h>
#include <FastLED.h>

#define LED_PIN     7
#define NUM_LEDS    16
const int CLK = 2;
const int DIO = 3;
CRGB leds[NUM_LEDS];
TM1637Display display(CLK, DIO);

void setup() {
    Serial.begin(9600);  
    Serial.setTimeout(2000);  
    display.setBrightness(0x0a);
    FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}
void loop() {
  if (Serial.available() > 0) {
      String received_string = Serial.readStringUntil('\n');
      int temp;
      temp = received_string.toInt();
      display.showNumberDec(temp);
    }
  static uint8_t hue = 0;
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(hue + i * 255 / NUM_LEDS, 255, 255);
  }
  FastLED.show();
  hue++;
  delay(10);
}
        