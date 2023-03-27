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
    int pos = random16(NUM_LEDS);
    leds[pos] += CHSV(baza++ + random8(64), 200, 255);
    FastLED.setBrightness(bright);
    FastLED.show();
}