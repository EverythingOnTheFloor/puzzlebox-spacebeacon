/*
  Morse.h - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/

#ifndef MpuController_h
#define MpuController_h
#include <Wire.h>

class MpuController
{
  public:
    MpuController(int pin);
    void dot();
    void dash();
  private:
    int _pin;
};

#endif

