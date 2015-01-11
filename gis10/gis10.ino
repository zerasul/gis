/****************************************************
* GIS: Garden Irrigation System. v.1.0
* Sistema de riego de Jardin.
* Empresa: Bender Mecatronics Systems. S.Coop. A.
* Fecha: 11/01/2015.
* **************************************************/
#include "Buttons.h"
//PINES
#define TRIEGOBUTTON 2 //Boton tiempo de riego
#define HOPTBUTTON 3 //Boton Humedad Optima
#define UPBUTTON 4 // Up Button
#define DOWNBUTTON 5 // Down Button
#define ENTERBUTTON 6 //Enter Button

/*
* enumeracion con los estados del dispositivo.
*
*/
enum estados {
  HSUELO,//Lectura de la humedad del suelo
  HOPTIMA,//Establecer la humedad optima
  TIEMPORIEGO //establecer el tiempo de riego
};

Buttons button(TRIEGOBUTTON, HOPTBUTTON, UPBUTTON, DOWNBUTTON, ENTERBUTTON);//Objeto con el pin de los botones.
//Variable con el tiempo de riego.
byte tiemporiego;
//Variable con la humedad optima
byte humedadoptima;
//variable con la humedad actual
byte humedadactual;
//estado actual.
byte estado;

void setup() {

  estado = HSUELO;
}

void loop() {

  handler();

}

void display() {


}

void handler() {
  button.controlButtons();
  if (button.getButtonState(0) == HIGH && button.getLatchState(0) == HIGH && estado != TIEMPORIEGO) {
    button.setLatchState(0, LOW);
    estado = TIEMPORIEGO;
  }

  if (button.getButtonState(1) == HIGH && button.getLatchState(1) == HIGH && estado != HOPTIMA) {
    button.setLatchState(1, LOW);
    estado = HOPTIMA;
  }

  if (button.getButtonState(0) == HIGH && button.getLatchState(0) == HIGH && estado == TIEMPORIEGO) {
    button.setLatchState(0, LOW);
    estado = HSUELO;
  }
  if (button.getButtonState(1) == HIGH && button.getLatchState(1) == HIGH && estado == HOPTIMA) {
    button.setLatchState(1, LOW);
    estado = HSUELO;
  }

  cambiarValor();

}

void cambiarValor() {
  switch (estado) {
    case TIEMPORIEGO:
      if (button.getButtonState(2) == HIGH && button.getLatchState(2) == HIGH) {
        button.setLatchState(2, LOW);
        if (tiemporiego < 99) {
          tiemporiego++;
        } else {
          tiemporiego = 0;
        }

      }
      if (button.getButtonState(3) == HIGH && button.getLatchState(3) == HIGH) {
        button.setLatchState(3, LOW);
        if (tiemporiego > 0) {
          tiemporiego--;
        } else {
          tiemporiego = 99;
        }

      }
      break;
    case HOPTIMA:
      if (button.getButtonState(2) == HIGH && button.getLatchState(2) == HIGH) {
        button.setLatchState(2, LOW);
        if (humedadoptima < 99) {
          humedadoptima++;
        } else {
          humedadoptima = 0;
        }

      }
      if (button.getButtonState(3) == HIGH && button.getLatchState(3) == HIGH) {
        button.setLatchState(3, LOW);
        if (humedadoptima > 0) {
          humedadoptima--;
        } else {
          humedadoptima = 99;
        }

      }
      break;
  }

}

void updateStatus() {

}
