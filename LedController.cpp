/*
  Morse.cpp - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/
#include "LedController.h"
#include <Adafruit_NeoPixel.h>

LedController::LedController()
{

}
void LedController::initialize(){
  strip2 = Adafruit_NeoPixel(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
  strip2.begin();
  strip2.show();
  strip2.setBrightness(1);
  }
String LedController::setRed(int color){
     for(int i=0; i<strip2.numPixels(); i++) {
         strip2.setPixelColor(i, strip2.Color(color,255-color,0));
     }
     strip2.show();
    return "yeet";
}