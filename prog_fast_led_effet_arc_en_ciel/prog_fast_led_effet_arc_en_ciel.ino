#include "FastLED.h"
#include <Adafruit_NeoPixel.h>

byte bright = 50; // luminosité des LEDs
byte baza = 0;

#define NUM_LEDS 165 // nombre de LEDs 100 par defaut
#define PIN 2 // câble bleu
#define PIN 8 // câble vert
#define PIN 4 // port de connexion ws2812b câble jaune
#define PIN 7 // câble orange
CRGB leds[NUM_LEDS];

NEO_RGB leds1[118]
NEO_RGB leds3[120]

#define LED_PIN 
#define LED_COUNT 120

Adafruit_NeoPixel led1(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  FastLED.addLeds <WS2812, PIN, GRB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(bright);
  
  LED_PIN.addLeds<NEO_RGB, 2>(leds1, 118);
  LED_PIN.addLeds<NEO_RGB, 8>(leds3, 120);

  leds1.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  leds1.show();            // Turn OFF all pixels ASAP
  leds1.setBrightness(250); // Set BRIGHTNESS to about 1/5 (max = 255)
  
  leds3.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  leds3.show();            // Turn OFF all pixels ASAP
  leds3.setBrightness(255); // Set BRIGHTNESS to about 1/5 (max = 255)
}

void loop() {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CHSV(baza+ i * 5, 255, 255);
    }
    baza++;
    FastLED.setBrightness(bright);
    FastLED.show();
    delay(20);

  leds1.show();
  leds3.show();
}