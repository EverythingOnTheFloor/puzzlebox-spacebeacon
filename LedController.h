/*
  Morse.h - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/

#ifndef LedController_h
#define LedController_h
#include <Adafruit_NeoPixel.h>
#define LED_PIN 6
#define LED_COUNT 1
#define DEFAULT_BRIGHTNESS 50

class LedController
{
  public:
    LedController();
    String setRed(int color);
    void initialize();
  private:
    Adafruit_NeoPixel strip2;

};

#endif