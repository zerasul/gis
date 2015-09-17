#include<Arduino.h>
#include "Button.h"

Button::Button(byte pin, long maxtime){
  this->latch=false;
  this->max_time=maxtime;
  this->p_time=0;
  this->p_valor=0;
  this->button_pin=pin;
}
Button::Button(byte pin){
  Button(pin,0);
}
Button::~Button(){}

byte Button::is_pressed(){
  if(digitalRead(this->button_pin)==1){
    // Si el pulsador DOWN esta pulsado y y su LACHT habilitado, pone el valor a 1 y deshabilita poniendo el LACHT a 1
    // Y por último como este pulsador consta de pulsación larga guarda en su variable de tiempo el momento en que se dio la pulsación.
    if(this->latch== 0){
      this->p_valor=1;
      this->latch=1;
      this->p_time=millis();
    }
    if(this->max_time>0){
    // Si es LACTH esta deshabilitado ya que el pulsador sigue  pulsado, si pasa 1 segundo así se activará la pulsación larga y toma un nuevo intervalo de tiempo
    // Para que dentro de un segundo si se mantiene pulsado de nuevamente de una pulsación larga.
    if( this->latch==1 && this->p_time+this->max_time<= millis()){
     this->p_valor=2;
     this->p_time=millis();
    }
    }

  }
  //Si el pulsador no esta pulsado habilita el lacht
  else{
  this->latch=0;
 
  }
  return this->p_valor;
}
void Button::reset_button(){
  this->p_valor=0;
}
