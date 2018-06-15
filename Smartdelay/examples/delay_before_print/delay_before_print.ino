/*
 Smart_delay.h - Library to use a non loop blocking delay based on the millis() comparison trick.
 Created by Martin Michotte, June 14, 2018.
 Released into the public domain.

 IMPORTANT: 
 When creating an instance of the Smartdelay class, you have to specifie how many simultanous delays you plan to use.
 Note that it's better to specifie too many than not anough. 
 In this exemple we have 3 simultaneous delays, therefor we specified it when creating the instance.
 If we had specified <3, the third delay would not work. If we had specified >3, it would work but it would hav taken more memory.     
 

 This exemple will continually print "RUNNING" on your serial. 
 On top of that, it will print : 
 "1 second delay done" every 1 seconds 
 "2 second delay done" every 2 seconds 
 "10 second delay done" every 10 seconds 
*/

#include <Smartdelay.h>

Smartdelay Smartdelay(3); 

void setup() {
Serial.begin(9600);
}

void loop() {
  Serial.println("RUNNING");

  if(Smartdelay.delay(0,1000)){
    Serial.println("1 second delay done");
  }
  if(Smartdelay.delay(1,2000)){
    Serial.println("2 seconds delay done");
  }
  if(Smartdelay.delay(2,10000)){
    Serial.println("10 seconds delay done");
    Serial.println();
  }
  
}


