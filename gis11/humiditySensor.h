#ifndef _HUMIDITYSENSORLIB
#define _HUMIDITYSENSORLIB 1
/****************************************************
* GIS: Garden Irrigation System. v.1.0
* Sistema de riego de Jardin.
* Empresa: Aura Tecnologica S.L.
* Fecha: 11/01/2015.
* **************************************************/
#include <Arduino.h>
#include "sensors.h"
/****************************************************
* class: HumiditySensor: sensor de Humedad.
* version: 1.0
* autor: vsuarez
****************************************************/
class humiditySensor:sensors{
  private:
    int pin;//Pin analogico de lectura
    int powerPin;//Pin digital para dar el pulso
  public:
    humiditySensor(int, int);
    ~humiditySensor();
    void updateValue();
    float getValue();
};
#endif
