#include "Adafruit_NeoPixel.h"
#include "FastLED.h"

int pix = 100;

Adafruit_NeoPixel strip (pix, 4, NEO_RGB + NEO_KHZ800);

// NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
// NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
// NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
// NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
// NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)

void setup() {
   strip.begin();
   strip.show();
   strip.setBrightness(50); // maximum 255
}

void loop() {
   for (int i = 0; i <= pix; i++) {
      strip.setPixelColor(i, 0, 0, 250);
      strip.show();
      delay(50);
   }

   for (int b = 50; b < 250; b++) {
      for (int i = 0; i <= pix; i++) {
         strip.setPixelColor(i, 250, 250, b * i / 250);
      }
      strip.show();
      delay(50);
   }
}