// James Allen July 2020
// Ver 1.0
// AT Tiny 85 RGB LED Potentiometer Controller

#include <FastLED.h>

#define LED_PIN 0             // which pin are LEDS connected to?
#define NUM_LEDS 8
#define COLOR_ORDER GRB			// Use the FastLED example to test this. Sometimes RGB makes the code control the wrong R, G or B
#define LED_TYPE WS2811        // WS2812 are very common RGB LED Chips. FastLED library supports a number of types

#define MAX_BRIGHTNESS 164      // Set the max_brightness 
#define MIN_BRIGHTNESS 0       // set to a minimum of 0%

//define the pins of the AT Tiny and what they do in the code

const int redPin = A1;
const int bluePin = A2;
const int greenPin = A3;

struct CRGB leds[NUM_LEDS];

void setup() {
  delay(3000); // in case we do something stupid. We dont want to get locked out.
  
//setup code for FastLED library
  LEDS.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(MAX_BRIGHTNESS);
}

void loop() {
  int redValue = map(analogRead(redPin), 0, 1023, 0, 255); //Maps values from 0-1023 to 0-255
  int blueValue = map(analogRead(bluePin), 0, 1023, 0, 255); //Maps values from 0-1023 to 0-255
  int greenValue = map(analogRead(greenPin), 0, 1023, 0, 255); //Maps values from 0-1023 to 0-255

  int i;
  for (i = 0; i < 8; i++) {
  leds[i].r = (redValue);
  leds[i].b = (blueValue);
  leds[i].g = (greenValue);
  FastLED.show();
}

}