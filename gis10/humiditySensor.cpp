#include <Arduino.h>
#include "humiditySensor.h"

humiditySensor::humiditySensor(int pin, int powerPin){
 this->pin=pin; 
 this->powerPin=powerPin;
 pinMode(this->powerPin,OUTPUT);
 this->currentValue=0.0;
}

humiditySensor::~humiditySensor(){
  
}

void humiditySensor::updateValue(){
   digitalWrite(this->powerPin,HIGH);
   this->currentValue=analogRead(this->pin);
   digitalWrite(this->powerPin,LOW);
}

float humiditySensor::getValue(){
   return this->currentValue; 
}
