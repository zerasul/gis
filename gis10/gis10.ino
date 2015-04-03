/******************************************************************************
* GIS: Garden Irrigation System. v.1.01                                       *
* Sistema de riego de Jardin.                                                 *
* Empresa: Bender Mecatronics Systems. S.Coop. A.                             *
* Fecha: 11/01/2015.                                                          *
* *****************************************************************************/

#include "Buttons.h"
#include "matriz.h"

/******************************************************************************
*                                                                             *
*                           PINES DE LOS BOTONES                              *
*                                                                             *
* *****************************************************************************/


#define TRIEGOBUTTON 2 // Boton tiempo de riego
#define HOPTBUTTON   3 // Boton Humedad Optima
#define UPBUTTON     4 // Up Button
#define DOWNBUTTON   5 // Down Button
#define ENTERBUTTON  6 // Enter Button

/******************************************************************************
*                                                                             *
*                           PINES DE LA MATRIZ                                *
*                                                                             *
* *****************************************************************************/


#define A      7
#define B      8 
#define C      9 
#define D      10
#define E      11
#define F      12
#define G      13
#define LACHT1 1 
#define LACHT2 15 



/******************************************************************************
*                                                                             *
*                enumeracion con los estados del dispositivo.                 *
*                                                                             *
* *****************************************************************************/

enum estados {
  HSUELO,     // Lectura de la humedad del suelo
  HOPTIMA,    // Establecer la humedad optima
  TIEMPORIEGO // Establecer el tiempo de riego
};



#define TEMPERATURAMAX 1
#define HUMEDAD        2
#define TIEMPOR        3

/******************************************************************************
*                                                                             *
*                declaracion de las principales variables                     *
*                                                                             *
* *****************************************************************************/


//Objeto con los pines de la matriz de 7 segmentos
Matriz matriz(A, B, C, D, E, F, G, LACHT1, LACHT2);

//Objeto con el pin de los botones.
Buttons button(TRIEGOBUTTON, HOPTBUTTON, UPBUTTON, DOWNBUTTON, ENTERBUTTON);

//Variable con el tiempo de riego.
byte tiemporiego;

//Variable con la humedad optima
byte humedadoptima;

//variable con la humedad actual
byte humedadactual;

//estado actual.
byte estado;


/******************************************************************************
*                                                                             *
*                                  SETUP                                      *
*                                                                             *
* *****************************************************************************/


void setup() {

  estado = HSUELO;
}

/******************************************************************************
*                                                                             *
*                                   LOOP                                      *
*                                                                             *
* *****************************************************************************/


void loop() {

  handler();

}


/******************************************************************************
*                                                                             *
*                                HANDLER                                      *
*                                                                             *
* *****************************************************************************/


void handler() {

  button.controlButtons();

  if (button.getButtonState(0) == HIGH && button.getLatchState(0) == HIGH && 
    estado != TIEMPORIEGO) {
          matriz.transicion(3);
          button.setLatchState(0, LOW);
          estado = TIEMPORIEGO;
  }

  if (button.getButtonState(1) == HIGH && button.getLatchState(1) == HIGH &&
   estado != HOPTIMA) {
          matriz.transicion(2);
          button.setLatchState(1, LOW);
          estado = HOPTIMA;
  }

  if (button.getButtonState(0) == HIGH && button.getLatchState(0) == HIGH &&
   estado == TIEMPORIEGO) {
          matriz.transicion(3);
          button.setLatchState(0, LOW);
          estado = HSUELO;
  }
  if (button.getButtonState(1) == HIGH && button.getLatchState(1) == HIGH && 
    estado == HOPTIMA) {

          matriz.transicion(2);
          button.setLatchState(1, LOW);
          estado = HSUELO;
  }

  cambiarValor();

}

/******************************************************************************
*                                                                             *
*                           CAMBIAR VALOR                                     *
*                                                                             *
* *****************************************************************************/


void cambiarValor() {
  switch (estado) {

    case TIEMPORIEGO:


      if (button.getButtonState(2) == HIGH && button.getLatchState(2) == HIGH){
        
          button.setLatchState(2, LOW);
          if (tiemporiego < 99) {
              tiemporiego++;
              matriz.escribir(tiemporiego); 
           } else {
              tiemporiego = 0;
              matriz.escribir(tiemporiego); 
          }

      }
      if (button.getButtonState(3) == HIGH && button.getLatchState(3) == HIGH){
          button.setLatchState(3, LOW);
          if (tiemporiego > 0) {
              tiemporiego--;
              matriz.escribir(tiemporiego); 
          } else {
              tiemporiego = 99;
              matriz.escribir(tiemporiego); 
          }

      }

      break;

    case HOPTIMA:


      if (button.getButtonState(2) == HIGH && button.getLatchState(2) == HIGH){
       
        button.setLatchState(2, LOW);

        if (humedadoptima < 99) {

          humedadoptima++;
          matriz.escribir(humedadoptima); //-------------------->

        } else {

          humedadoptima = 0;
          matriz.escribir(humedadoptima); //-------------------->

        }

      }
      if (button.getButtonState(3) == HIGH && button.getLatchState(3) == HIGH){
       
        button.setLatchState(3, LOW);

        if (humedadoptima > 0) {

          humedadoptima--;
          matriz.escribir(humedadoptima); //-------------------->

        } else {

          humedadoptima = 99;
          matriz.escribir(humedadoptima); //-------------------->

        }

      }

      break;
  }

}

/******************************************************************************
*                                                                             *
*                            UPDATE STATUS                                    *
*                                                                             *
* *****************************************************************************/


void updateStatus() {

}

/******************************************************************************
*                                                                             *
*                            CLIMATE CONTROL                                  *
*                                                                             *
* *****************************************************************************/

void climateControl(int humedadoptima, int tiemporiego){
  
  
}

