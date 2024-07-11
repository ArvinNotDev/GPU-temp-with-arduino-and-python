#include <TM1637Display.h>
#include <FastLED.h>

#define LED_PIN 7
#define NUM_LEDS 16
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
        if(temp < 40){
          for(int i=0;i<16;i++){
            leds[i] = CRGB(0, 0, 255);
            FastLED.show();
            delay(90);
           
          }}

        else if(temp < 54){
          for(int i=0;i<16;i++){
            leds[i] = CRGB(0, 255, 255);
            FastLED.show();
            delay(90);
           
          }
          }
        else if(temp < 65){
          for(int i=0;i<16;i++){
            leds[i] = CRGB(255, 255, 0);
            FastLED.show();
            delay(90);
            
          }
          }
        else if(temp < 75){
          for(int i=0;i<16;i++){
            leds[i] = CRGB(255, 0, 255);
            FastLED.show();
            delay(90);
            
          }
          }
        else{
          for(int i=0;i<16;i++){
            leds[i] = CRGB(255, 0, 0);
            FastLED.show();
            delay(90);
            
          
          }}
        
    }
}
