#include <Arduino.h>
/******************************************
* Buttons libary: libreria de control de botones
*  para el proyecto GIS.
*  v: 1.0.
* Fecha: 11/01/2015
*******************************************/
class Buttons {
 
 private:
  int pines[5];//Array con los pines
  bool  latchButtons[5];//latch para controlar los botones
 public:
   Buttons(int,int,int, int, int);
   ~Buttons();
   bool getButtonState(int);
   bool getLatchState(int);
   void setLatchState(int,int);
   void controlButtons();
   
};
