#include "matriz.h"


Matriz::Matriz( byte a, byte b, byte c, byte d, byte e, byte f,byte g,
 byte lacht1, byte lacht2) {

	this->pines[0] = a;
	this->pines[1] = b;
	this->pines[2] = c;
	this->pines[3] = d;
	this->pines[4] = e;
	this->pines[5] = f;
	this->pines[6] = g;

	this->lacht1 = lacht1;
	this->lacht2 = lacht2;

}

Matriz::~Matriz(){}


void Matriz::escribirDisplay(byte n) {

  switch (n){

    case 0:
        display(0, 0, 0, 0, 0, 0, 1);
        break;

    case 1:
        display(1, 0, 0, 1, 1, 1, 1);
        break;

    case 2:
        display(0, 0, 1, 0, 0, 1, 0);
        break;

    case 3:
        display(0, 0, 0, 0, 1, 1, 0);
        break;

    case 4:
        display(1, 0, 0, 1, 1, 0, 0);
        break;

    case 5:
        display(0, 1, 0, 0, 1, 0, 0);
        break;

    case 6:
        display(0, 1, 0, 0, 0, 0, 0);
        break;

    case 7:
        display(0, 0, 0, 1, 1, 1, 1);
        break;

    case 8:
        display(0, 0, 0, 0, 0, 0, 0);
        break;                          

    case 9:
        display(0, 0, 0, 0, 1, 0, 0);
        break;
    // Introducir 10 para escribir una H
    case 10:
        display(1, 0, 0, 1, 0, 0, 0);
        break;
    // Introducir 11 para dibujar el primer digito de la T de tiempode riego .
    case 11:
        display(0, 1, 1, 1, 0, 0, 1);
        break; 
    // Introducir 12 para dibujar el segundo dígito de la T de tiempode riego .
    case 12:
        display(0, 0, 0, 1, 1, 1, 1);
        break;                        
    // Introducir 13 para dibujar º .
    case 13:
        display(0, 0, 1, 1, 1, 0, 0);
        break; 
    // Introducir 14 para dibujar C .
    case 14:
        display(0, 1, 1, 0, 0, 0, 1);
        break;                            
    // Para apagar el display introducir cualquier numero no utilizado .
    default:
        display(1, 1, 1, 1, 1, 1, 1);

    }
}
 
void Matriz::display(boolean a, boolean b, boolean c, boolean d, boolean e,
 	boolean f, boolean g){

	digitalWrite (pines[0],a);   
	digitalWrite (pines[1],b);   
	digitalWrite (pines[2],c);
	digitalWrite (pines[3],d);
	digitalWrite (pines[4],e);
	digitalWrite (pines[5],f);
	digitalWrite (pines[6],g);
 
}


void Matriz::escribir(byte caracter) {

	byte decena = caracter/10;
	byte unidad = caracter%10;

	digitalWrite(lacht1, HIGH); 

	escribirDisplay(decena);

	digitalWrite(lacht1, LOW);
	digitalWrite(lacht2, HIGH);

	escribirDisplay(unidad);
	
	digitalWrite(lacht2, LOW);
}

void Matriz::transicion(byte n){

    switch (n){
        case 1:

            digitalWrite(lacht1, HIGH); 

            escribirDisplay(14);

            digitalWrite(lacht1, LOW);
            digitalWrite(lacht2, HIGH);

            escribirDisplay(13);
    
            digitalWrite(lacht2, LOW);
            break;

        case 2:

            digitalWrite(lacht1, HIGH); 

            escribirDisplay(250);

            digitalWrite(lacht1, LOW);
            digitalWrite(lacht2, HIGH);

            escribirDisplay(10);
    
            digitalWrite(lacht2, LOW);
            break;

        case 3:

            digitalWrite(lacht1, HIGH); 

            escribirDisplay(11);

            digitalWrite(lacht1, LOW);
            digitalWrite(lacht2, HIGH);

            escribirDisplay(12);
    
            digitalWrite(lacht2, LOW);
            break;
    }
}
