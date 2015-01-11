/****************************************************
* GIS: Garden Irrigation System. v.1.0
* Sistema de riego de Jardin.
* Empresa: Bender Mecatronics Systems. S.Coop. A.
* Fecha: 11/01/2015.
* **************************************************/

//PINES
#define TRIEGOBUTTON 2
#define HOPTBUTTON 3
#define UPBUTTON 4
#define DOWNBUTTON 5
#define ENTERBUTTON 6

enum estados {
  HSUELO,
  HOPTIMA,
  TIEMPORIEGO
};

Buttons button(TRIEGOBUTTON, HOPTBUTTON, UPBUTTON, DOWNBUTTON, ENTERBUTTON);
byte tiemporiego;
byte humedadoptima;
byte humedadactual;

void setup() {

  estado = HSUELO;
}

void loop() {
  // put your main code here, to run repeatedly:

}

void display() {


}

void handler() {
  boolean buttonStates[5] = button.generateButtonState();
  boolean latchButtons[5] = button.controlButtons();
  if (buttonStates[0] == HIGH && latchButtons[0] == HIGH && estado != TIEMPORIEGO) {
    latchButtons[0] = LOW;
    estado = TIEMPORIEGO;
  }

  if (buttonStates[1] == HIGH && latchButtons[1] == HIGH && estado != HOPTIMA) {
    latchButtons[1] = LOW;
    estado = HOPTIMA;
  }

  if (buttonStates[0] == HIGH && latchButtons[0] == HIGH && estado == TIEMPORIEGO) {
    latchButtons[0] = LOW;
    estado = HSUELO;
  }
  if (buttonStates[1] == HIGH && latchButtons[1] == HIGH && estado == HOPTIMA) {
    latchButtons[1] = LOW;
    estado = HSUELO;
  }



}

void cambiarValor(boolean states[], boolean latches[]) {
  switch (estado) {
    case TIEMPORIEGO:
      if (buttonStates[2] == HIGH && latchButtons[2] == HIGH) {
        latchButtons[2] = LOW;
        if(tiemporiego<99){
          tiemporiego++; 
        }else{
          tiemporiego=0; 
        }
         
      }
      if (buttonStates[3] == HIGH && latchButtons[3] == HIGH) {
        latchButtons[3] = LOW;
        if(tiemporiego>0){
          tiemporiego--; 
        }else{
          tiemporiego=99; 
        }
         
      }
      break;
      case HOPTIMA:
      if (buttonStates[2] == HIGH && latchButtons[2] == HIGH) {
        latchButtons[2] = LOW;
        if(humedadoptima<99){
          humedadoptima++; 
        }else{
          humedadoptima=0; 
        }
         
      }
      if (buttonStates[3] == HIGH && latchButtons[3] == HIGH) {
        latchButtons[3] = LOW;
        if(humedadoptima>0){
          humedadoptima--; 
        }else{
          humedadoptima=99; 
        }
         
      }
      break;
  }

}

void updateStatus() {

}
