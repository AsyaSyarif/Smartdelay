/*
 Smart_delay.h - Library to use a non loop blocking delay based on the millis() comparison trick.
 Created by Martin Michotte, June 14, 2018.
 Released into the public domain.

 IMPORTANT: 
 When creating an instance of the Smartdelay class, you have to specifie how many simultanous delays you plan to use.
 Note that it's better to specifie too many than not anough. 
 In this exemple we have only 1 delay, therefor we specified it when creating the instance.
 If we had specified <1, our delay would not work. If we had specified >1, it would work but it would have taken more memory.  

 This exemple will blink the Arduino onboard LED at a desired frequency without pausing the loop. 
*/

#include <Smartdelay.h>

Smartdelay Smartdelay(1);

float Frequency = 1;       //input your frequency in Hz

const byte ledPin =  LED_BUILTIN;
int ledState = LOW;
float wait = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  //Serial.begin(9600);
  wait = 1000/(2*Frequency);
}

void loop() {
  //Serial.println("RUNNING");
  if (Smartdelay.delay(0,wait)) {
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    digitalWrite(ledPin, ledState);
  }
}
