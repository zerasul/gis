#ifndef _TEMPSENSORLIB
#define _TEMPSENSORLIB 1
/****************************************************
* GIS: Garden Irrigation System. v.1.0
* Sistema de riego de Jardin.
* Empresa: Aura Tecnologica S.L.
* Fecha: 11/01/2015.
* **************************************************/
#include <Arduino.h>
#include "sensors.h"
/****************************************************
* class: tempSensor: sensor de Temperatura de suelo.
* version: 1.0
* autor: vsuarez
****************************************************/
class tempSensor:sensors{
  private:
    int pin;//Pin analogico de lectura
    int powerPin;//Pin digital para dar el pulso
  public:
    tempSensor(int, int);
    ~tempSensor();
    void updateValue();
    float getValue();
};
#endif
