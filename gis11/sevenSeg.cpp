#include "sevenSeg.h"
sevenSeg::sevenSeg(int p1, int p2, int a, int b, int c, int d, int e, int f, int g){
  this->p1=p1;
  this->p2=p2;
  this->a=a;
  this->b=b;
  this->c=c;
  this->d=d;
  this->e=e;
  this->f=f;
  this->g=g;
  pinMode(this->p1,OUTPUT);
  pinMode(this->p2,OUTPUT);
  pinMode(this->a,OUTPUT);
  pinMode(this->b,OUTPUT);
  pinMode(this->c,OUTPUT);
  pinMode(this->d,OUTPUT);
  pinMode(this->e,OUTPUT);
  pinMode(this->f,OUTPUT);
  pinMode(this->g,OUTPUT);

}
sevenSeg::~sevenSeg(){
}

void sevenSeg::display(boolean a, boolean b, boolean c, boolean d , boolean e, boolean f, boolean g){
  digitalWrite(this->a,a);
  digitalWrite(this->b,b);
  digitalWrite(this->c,c);
  digitalWrite(this->d,d);
  digitalWrite(this->e,e);
  digitalWrite(this->f,f);
  digitalWrite(this->g,g);

}
void sevenSeg::displayOneNumber(byte number){
  switch(number){
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
    display(0, 0, 0, 0, 0, 0, 0) ;
    break;
  case 9:
    display(0, 0, 0, 0, 1, 0, 0);
    break;

  
   
  }
  delay(1);
  display(1, 1, 1, 1, 1, 1, 1);
}
void sevenSeg::displayNumber(byte number){
  byte decenas = (byte)number /10;
  byte unidades = number % 10;

  digitalWrite(this->p1,HIGH);
  displayOneNumber(decenas);

  digitalWrite(this->p1,LOW);

  digitalWrite(this->p2,HIGH);
  displayOneNumber(unidades);
  digitalWrite(this->p2,LOW);



}
void sevenSeg::write(byte number){
  if(number>=0 && number<100){
displayNumber(number);
  }
  else{
    switch(number){
    case SOILHUMIDITY:
        
      break;
     case OPTIMALHUMIDITY:
       
     break;
    }
  }
}
  void sevenSeg::displayOptimalHumidity(){
      digitalWrite(this->p1,HIGH);
   display(1, 0, 0, 1, 0, 0, 0);

  digitalWrite(this->p1,LOW);

  digitalWrite(this->p2,HIGH);
  displayOneNumber(0);
  digitalWrite(this->p2,LOW);
  }
void sevenSeg::turnOff(){
  digitalWrite(this->p1,LOW);
  digitalWrite(this->p2,LOW);
}




