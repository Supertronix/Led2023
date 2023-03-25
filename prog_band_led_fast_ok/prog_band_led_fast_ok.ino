#include "FastLED.h"

#define NUM_LEDS 100 // nombre de LEDs
#define PIN 4 // port de connexion ws2812b

CRGB leds[NUM_LEDS];

void setup() {
   FastLED.addLeds <WS2812, PIN, GRB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
   FastLED.setBrightness(50);
}

void loop() {
   leds[0] = CHSV(0, 0, 255);
   FastLED.show();
   delay(500);

   leds[1] = CHSV(0, 255, 0);
   FastLED.show();
   delay(500);

   leds[2] = CRGB::Red;
   FastLED.show();
   delay(500);

   leds[3] = CRGB::White;
   FastLED.show();
   delay(500);
}