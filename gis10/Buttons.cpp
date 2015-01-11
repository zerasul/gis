#include "Buttons.h"
/*
 *
 * Contructor de la clase:
 * pin1-> pin primero
 * pin2-> pin segundo
 * pin3-> pin tercero
 * pin4-> pin cuarto
 * pin5-> pin quinto
 */
Buttons::Buttons(int pin1, int pin2, int pin3, int pin4, int pin5) {
  this->pines[0] = pin1;
  this->pines[1] = pin1;
  this->pines[2] = pin1;
  this->pines[3] = pin1;
  this->pines[4] = pin1;
  this->latchButtons[0] = 0;
  this->latchButtons[1] = 0;
  this->latchButtons[2] = 0;
  this->latchButtons[3] = 0;
  this->latchButtons[4] = 0;
}
Buttons::~Buttons(){
  
}
/*
 * obtiene el estado del boton en funcion del numero de pin
 * pin: Numero del 0 al 4 con el numero de pin.
 * bool: indica si esta en alto o bajo.
 */
bool Buttons::getButtonState(int pin) {

  return digitalRead(this->pines[pin]);

}
/*
 *
 * inicializa los latch de los botones
 * */
void Buttons::controlButtons() {
  for (int i = 0; i < 5; i++) {
    if (this->getButtonState(i) == 0)
      this->latchButtons[i] = 1;

  }
}
/*
 * obtiene el estado del cerrojo.
 * pin: numero del 0 al 4 con el numero de pin
 * devuelve el estado del cerrojo.
 */
bool Buttons::getLatchState(int pin){
   return this->latchButtons[pin];
}
/*
 *
 * Establece el estado del cerrojo.
 * pin: numero del 0 al 4 con el numero de pin.
 * estate: estado a activar (0 o 1).
 */
void Buttons::setLatchState(int pin,int state){
   this->latchButtons[pin]=state;
}
