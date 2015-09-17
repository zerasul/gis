/****************************************************
* GIS: Garden Irrigation System. v.1.0
* Sistema de riego de Jardin.
* Empresa: Bender Mecatronics Systems. S.Coop. A.
* Fecha: 11/01/2015.
* **************************************************/
#include <Arduino.h>
#include "tempSensor.h"
/****************************************************
* constructor de la clase
* parametros:
* - pin: pin analogico del que se realizara la lectura
* - powerPin: pin digital que realizara un pulso
* **************************************************/
tempSensor::tempSensor(int pin, int powerPin){
 this->pin=pin; 
 this->powerPin=powerPin;
 pinMode(this->powerPin,OUTPUT);
 this->currentValue=0.0;
}
/****************************************************
* destructor de la clase
* **************************************************/
tempSensor::~tempSensor(){
  
}
/****************************************************
* Actualiza el valor obtenido al leer el sensor de temperatura
* **************************************************/
void tempSensor::updateValue(){
  int sum=0; 
   for(int i=0;i<5;i++){
   digitalWrite(this->powerPin,HIGH);
  int aux = analogRead(this->pin);
  float auxi = ((aux / 1024) * 5);
  auxi = (auxi * 480) / (5 - auxi);
  sum += byte(auxi * 2.5641 - 256.41);
   digitalWrite(this->powerPin,LOW);
 }
 this->currentValue=sum/5;
}
/****************************************************
* Obtiene el ultimo valor actualizado
* devuelve: ultimo valor actualizado
* **************************************************/
float tempSensor::getValue(){
   return this->currentValue; 
}
