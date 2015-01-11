#include "Buttons.cpp"

Buttons::Buttons(int pin1, int pin2, int pin3, int pin4, int pin5) {
  this->ButtonPin1 = pin1;
  this->ButtonPin2 = pin2;
  this->ButtonPin3 = pin3;
  this->ButtonPin4 = pin4;
  this->ButtonPin5 = pin5;

  this->buttonStates[0] = 0;
  this->buttonStates[1] = 0;
  this->buttonStates[2] = 0;
  this->buttonStates[3] = 0;
  this->buttonStates[4] = 0;
  this->latchButtons[0] = 0;
  this->latchButtons[1] = 0;
  this->latchButtons[2] = 0;
  this->latchButtons[3] = 0;
  this->latchButtons[4] = 0;
}

boolean[] Buttons::generateButtonState() {

  buttonStates[0] = digitalRead(this->ButtonPin1);
  buttonStates[1] = digitalRead(this->ButtonPin2);
  buttonStates[2] = digitalRead(this->ButtonPin3);
  buttonStates[3] = digitalRead(this->ButtonPin4);
  buttonStates[4] = digitalRead(this->ButtonPin5);
  return this->buttonState;
}

boolean[] Buttons::controlButtons(int ){
 for(byte i=0;i<5;i++){
   if(buttonStates[i]==0)
     this->latchButtons[i]=1;
   
 } 
 return this->latchButtons;
}
