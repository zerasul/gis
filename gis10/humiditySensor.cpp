/****************************************************
* GIS: Garden Irrigation System. v.1.0
* Sistema de riego de Jardin.
* Empresa: Bender Mecatronics Systems. S.Coop. A.
* Fecha: 11/01/2015.
* **************************************************/
#include <Arduino.h>
#include "humiditySensor.h"
/****************************************************
* constructor de la clase
* parametros:
* - pin: pin analogico del que se realizara la lectura
* - powerPin: pin digital que realizara un pulso
* **************************************************/
humiditySensor::humiditySensor(int pin, int powerPin){
 this->pin=pin; 
 this->powerPin=powerPin;
 pinMode(this->powerPin,OUTPUT);
 this->currentValue=0.0;
}
/****************************************************
* destructor de la clase
* **************************************************/
humiditySensor::~humiditySensor(){
  
}
/****************************************************
* Actualiza el valor obtenido al leer el sensor de humedad
* **************************************************/
void humiditySensor::updateValue(){
   digitalWrite(this->powerPin,HIGH);
   this->currentValue=analogRead(this->pin);
   digitalWrite(this->powerPin,LOW);
}
/****************************************************
* Obtiene el ultimo valor actualizado
* devuelve: ultimo valor actualizado
* **************************************************/
float humiditySensor::getValue(){
   return this->currentValue; 
}
