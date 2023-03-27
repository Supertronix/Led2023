#include "FastLED.h"

byte bright = 50; // luminosité des LEDs
byte baza = 0;

#define NUM_LEDS 100 // nombre de LEDs
#define PIN 4 // port de connexion ws2812b
CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds <WS2812, PIN, GRB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(bright);
}

void loop() {
    fadeToBlackBy(leds, NUM_LEDS, 2);
    for (int i = 0; i < 8; i++) {
      leds[beatsin16(i + 7, 0, NUM_LEDS - 1)] |= CHSV(baza+=16, 200, 255);
    }
    FastLED.setBrightness(bright);
    FastLED.show();
    delay(20);
}