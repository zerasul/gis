#include <EEPROM.h>

#include <SnoozeLib.h>
#include "sevenSeg.h"
#include "humiditySensor.h"
#include "Button.h"
#include "tempSensor.h"

#define WAKEUPTIME 1000000
#define SLEEPTOTALTIME 200000

#define ENTERSLEEPTIME 1500
#define UPLONGPULSETIME 1000
#define DOWNLONGPULSETIME 1500

#define P1 19
#define P2 0
#define A 3
#define B 15
#define C 4
#define D 6
#define E 5
#define F 1
#define G 7

#define CONTROLPIN 16
#define HUMIDITYPIN A3

#define ENTER 2
#define UP 1
#define DOWN 14
#define HOPTBUTTON 1
#define TIMEIRR 1

#define EVLED 8
#define L_HO 9
#define L_IT 10

#define MAXTEMP 20//40

/* GIS: version 1.1*/

enum EnergyMode {
  WAKEUP_AUTO,
  SLEEPING,
  WAKEUP_USER
};

enum ESTATES {
  OPTIMUNHUMIDITY,
  SOILHUMIDITYSTATE,
  IRRIGATIONTIME,
  TRANSITION
};
enum TransitionTypes {
  HO,
  TR,
  SH
};
byte currentEnergyMode;
long wakeUpTimeElapsed;
long wakeupTime;
long timepassed;
long time;
byte currentHumidity;
byte currentState;
byte resting;
byte irrigating;
byte optimumhumidity;
byte irrigationtime;

sevenSeg sevengs(P1, P2, A, B, C, D, E, F, G);
humiditySensor hsensor(A3, 16);
tempSensor tsensor(A4, 16);
Button buttonEnter(ENTER, ENTERSLEEPTIME);
Button buttonUp(UP, UPLONGPULSETIME);
Button buttonDown(DOWN, DOWNLONGPULSETIME);
Button buttonTr(TIMEIRR);
Button buttonHo(HOPTBUTTON);

void setup() {
  currentEnergyMode = WAKEUP_USER;
  wakeUpTimeElapsed = 0;
  timepassed = 0;
  wakeupTime = millis();
  time = millis();
  pinMode(0, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(EVLED, OUTPUT);
  pinMode(L_HO, OUTPUT);
  hsensor.updateValue();
  //Obtencion de la configuracion
  optimumhumidity = EEPROM.read(0);
  optimumhumidity = (optimumhumidity == 0) ? 65 : optimumhumidity; //valor por defecto 65
  irrigationtime = EEPROM.read(1);
  irrigationtime = (irrigationtime == 0) ? 99 : irrigationtime; //Valor por defecto 99 segundos
  EEPROM.write(0, optimumhumidity);
  EEPROM.write(1, irrigationtime);
  resting = 0;
  irrigating = 0;
}

void loop() {
  currentDisplay();


  handleButtons();
  handleBackground();
}

void interruptHandler() {
  if (currentEnergyMode == SLEEPING) {
    snoozeLib.wakeup();
    currentEnergyMode = WAKEUP_USER;
  }


}

void currentDisplay() {
  switch (currentEnergyMode) {
    case WAKEUP_USER:
      switch (currentState) {
        case SOILHUMIDITYSTATE:
          sevengs.write(map(hsensor.getValue(), 0, 1023, 0, 99));
          break;
        case OPTIMUNHUMIDITY:

          sevengs.write(optimumhumidity);
          break;
        case IRRIGATIONTIME:
          sevengs.write(irrigationtime);
          break;

      }
      break;
  }

}
void handleButtons() {
  switch (currentEnergyMode) {
    case WAKEUP_AUTO:
      if (buttonEnter.is_pressed() == 1) {
        currentEnergyMode = WAKEUP_USER;
        buttonEnter.reset_button();
      }
      break;
    case WAKEUP_USER:
      if (buttonEnter.is_pressed() == 2) {
        currentEnergyMode = SLEEPING;
        buttonEnter.reset_button();
        sleep();
      }
      /*  if(buttonEnter.is_pressed() ==1){
           if(currentState ==  IRRIGATIONTIME){
              EEPROM.write(1, irrigationtime);

           }
           if(currentState == OPTIMUNHUMIDITY)
           {
              EEPROM.write(0, optimumhumidity);
           }
           currentState=SOILHUMIDITYSTATE;
           digitalWrite(L_HO,LOW);
           digitalWrite(L_IT,LOW);
        }*/
      if (buttonHo.is_pressed() == 1) {
        buttonHo.reset_button();
        currentState = OPTIMUNHUMIDITY;
        digitalWrite(L_HO, HIGH);
        digitalWrite(L_IT, LOW);
      }
      if (buttonTr.is_pressed() == 1) {
        buttonTr.reset_button();
        currentState = IRRIGATIONTIME;
        digitalWrite(L_IT, HIGH);
        digitalWrite(L_HO, LOW);
      }


  }

}
void handleBackground() {

  switch (currentEnergyMode) {
    case WAKEUP_USER:
      timepassed = millis();

      if ( timepassed - time > 5000) {
        hsensor.updateValue();
        tsensor.updateValue();
        time = millis();
      }
      currentState = SOILHUMIDITYSTATE;
      wakeUpTimeElapsed = millis();
      if ((wakeUpTimeElapsed - wakeupTime) > WAKEUPTIME) {
        currentEnergyMode = SLEEPING;

        sleep();

        if (currentEnergyMode != WAKEUP_USER)
          currentEnergyMode = WAKEUP_AUTO;
        wakeupTime = millis();
      }
      break;
    case SLEEPING:

      break;
    case WAKEUP_AUTO:
     // currentEnergyMode = WAKEUP_USER;
      break;
  }
  handleirrgation();
}

void handleirrgation() {

  if (tsensor.getValue() < MAXTEMP) {
    if (hsensor.getValue() < (optimumhumidity - 2))
      switch (resting) {
        case 1:
          if (irrigationtime * 4 * 1000 < millis() - time) {
            resting = 0;
          }
          break;
        case 0:
          if (irrigationtime * 1000 < millis() - time) {
            resting = 1;
            irrigating = LOW;
          } else {
            irrigating = HIGH;
          }
          break;

      }
    else
      irrigating = LOW;
  } else {
    irrigating = LOW;
  }

  digitalWrite(EVLED, irrigating);
}
void sleep() {
  //sevengs.turnOff();

  attachInterrupt(0, interruptHandler, RISING);
  snoozeLib.snooze(SLEEPTOTALTIME);

  detachInterrupt(0);
}






