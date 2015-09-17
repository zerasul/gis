#ifndef _BUTTONLIB
#define _BUTTONLIB 1
#include<Arduino.h>
/****************************************************
* GIS: Garden Irrigation System. v.1.0
* Sistema de riego de Jardin.
* Empresa: Aura Tecnologica S.L.
* Fecha: 22/05/2015.
* **************************************************/

class Button{
  private:
  boolean latch;
  long max_time;
  long p_time;
  byte p_valor;
  byte button_pin;
  
  public:
   Button(byte button_pin, long maxtime);
   Button(byte button_pin);
  ~Button();
  byte is_pressed(); 
  void reset_button();
};

#endif
