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
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CHSV(baza+ i * 5, 255, 255);
    }
    baza++;
    FastLED.setBrightness(bright);
    FastLED.show();
    delay(20);
}