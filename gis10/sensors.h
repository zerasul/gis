/****************************************************
* GIS: Garden Irrigation System. v.1.0
* Sistema de riego de Jardin.
* Empresa: Aura Tecnologica S.L.
* Fecha: 03/04/2015.
* **************************************************/
#include <Arduino.h>
/***************************************************
* class Sensors: clase base para los sensores
* version: 1.0
* autor: vsuarez
***************************************************/
class sensors{
  
  protected:
    float currentValue;//Valor actual
  public:
    virtual void updateValue();//Actualiza el valor actual
    virtual float getValue();//Obtiene el ultimo valor actualizado
};
