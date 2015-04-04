/****************************************************
* GIS: Garden Irrigation System. v.1.0
* Sistema de riego de Jardin.
* Empresa: Aura Tecnologica S.L.
* Fecha: 03/04/2015.
* **************************************************/
#include <Arduino.h>
#include "sensors.h"
/***************************************************
* class tempSensor: sensor de temperatura
* version: 1.0
* autor: vsuarez
****************************************************/
class tempSensor:sensors{
  
  private:
  float pin;//Pin analogico del que se realizara la lectura
  float powerPin; // pin digital del que se obtendra el pulso
  
  public:
    tempSensor(int, int);
    ~tempSensor();
    void updateValue();
    float getValue();
};
