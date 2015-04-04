/****************************************************
* GIS: Garden Irrigation System. v.1.0
* Sistema de riego de Jardin.
* Empresa: Aura Tecnologica S.L.
* Fecha: 03/04/2015.
* **************************************************/
#include<Arduino.h>
#include "tempSensor.h"
/****************************************************
* constructor de la clase
* parametros:
* - pin: pin analogico del que se realizara la lectura
* - powerPin: pin digital del que se realizara el pulso
* **************************************************/
tempSensor::tempSensor(int pin, int powerPin){
 this->pin=pin;
 this->powerPin=powerPin; 
}
/****************************************************
* destructor de la clase
* **************************************************/
tempSensor::~tempSensor(){
  
}
/****************************************************
* actualiza el valor actual del sensor
* **************************************************/
void tempSensor::updateValue(){
   digitalWrite(this->powerPin,HIGH);
   this->currentValue=analogRead(this->pin);
   digitalWrite(this->powerPin,LOW); 
}
/****************************************************
* obtiene el ultimo valor actualizado
* devuelve: ultimo valor actualizado
* **************************************************/
float tempSensor::getValue(){
  return   this->currentValue; 
}
