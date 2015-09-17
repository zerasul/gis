#ifndef SEVENSEG_H
#define SEVENSEG_H
#include<Arduino.h>

#define SOILHUMIDITY 100
#define TIME 101
#define TEMPERATURE 102
#define OPTIMALHUMIDITY 103
#define DISPLAYERROR 104

/*********************************************************************
 * sevenSeg: library that controls a 2 digit Seven Segment           *
 * Author: Victor Suarez Garcia <victor.suarez@auratecnologica.com>  *
 * Date: 12/05/2015                                                  *
 * Copyrigth (C) 2015. Aura Tecnológica                              *
 *********************************************************************/
 
class sevenSeg{

private:
  byte p1;//First Digit
  byte p2;//Second Digit
  byte a;// a Segment
  byte b;// b Segment
  byte c;// c Segment
  byte d;// d Segment
  byte e;// e Segment
  byte f;// f Segment
  byte g;// g Segment
  void displayNumber(byte number);//Display a number in one digit
  void displaySoilHumidity();//Display Soil Humidity Simbol "H S".
  void displayOptimalHumidity();//Display Optimal Humidity Simbol "H O".
  void displayTemperature();// Display Temperature Simbol " T ".
  void displayError();//Display Error Simbol "E R".
  void display(boolean a, boolean b, boolean c, boolean d , boolean e, boolean f, boolean g); //Display a simbol selecting the segments
  void displayOneNumber(byte number);//Display a number in One Digit
public:
  sevenSeg(int p1, int p2, int a, int b, int c, int d, int e, int f, int g); //Constructor
  ~sevenSeg();//Destructor
  void write(byte number);//Write a number in the seven sensor
  void turnOff();//Turn Off the seven segs sensor
};
#endif

