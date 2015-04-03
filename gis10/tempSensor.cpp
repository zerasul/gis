
#include<Arduino.h>
#include "tempSensor.h"

tempSensor::tempSensor(int pin, int powerPin){
 this->pin=pin;
 this->powerPin=powerPin; 
}

tempSensor::~tempSensor(){
  
}

void tempSensor::updateValue(){
   digitalWrite(this->powerPin,HIGH);
   this->currentValue=analogRead(this->pin);
   digitalWrite(this->powerPin,LOW); 
}

float tempSensor::getValue(){
  return   this->currentValue; 
}
