/*
 Smart_delay.h - Library to use a non loop blocking delay based on the millis() comparison trick.
 Created by Martin Michotte, June 14, 2018.
 Released into the public domain.
 */

#include "Arduino.h"
#include "Smartdelay.h"

Smartdelay::Smartdelay(int val)
{
    _actualdelay[val] = {};
}


int Smartdelay::delay(byte number, long millisec)
{
  if ((millis() - _actualdelay[number]) > millisec) {
    _actualdelay[number] = millis();
    return 1;
  }
  else {
    return 0;
  }
}

