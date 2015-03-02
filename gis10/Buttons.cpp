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
int current; //Estado actual del boton.
int count; //segundos que esta pulsado
byte previous = HIGH;//Estado anterior.
unsigned long firstTime; //Hace cuanto se comenzo a pulsar el boton.

void Buttons::controlButtons() {
  for (int i = 0; i < 5; i++) {
    if (this->getButtonState(i) == 0)
      this->latchButtons[i] = 1;
    if(current == LOW && previous == HIGH && millis() - firstTime > 200){
      firstTime = millis(); //Memoriza cuando se ha pulsado el boton
    }
    if(current  == LOW && ((millis() - firstTime)% 1000) < 20 && millis() - firstTime > 500){
      count++; //Cada segundo que es pulsado se incrementa el contador.
    }
    if(current == HIGH && previous == LOW && count >=3 && count <= 6){
      Serial.println("Larga!");      //haz algo en pulsacion larga.
    }
    if(current == HIGH && previous == LOW && count >=0 && count < 3){
      Serial.println("Corta!");
    }
    if(current == HIGH){
      count = 0; //resetea el contador si el boton no es pulsado.    
    }
    previous = current;
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


