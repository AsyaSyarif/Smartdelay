/*
 Smart_delay.h - Library to use a non loop blocking delay based on the millis() comparison trick.
 Created by Martin Michotte, June 14, 2018.
 Released into the public domain.
*/

#ifndef Smartdelay_h
#define Smartdelay_h

#include "Arduino.h"

class Smartdelay
{
  public:
    Smartdelay(int val);
    int delay(byte number, long millisec);
  private:
    unsigned long _actualdelay[5] = {};
};

#endif
