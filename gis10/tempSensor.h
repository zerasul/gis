#include <Arduino.h>
#include "sensors.h"

class tempSensor:sensors{
  
  private:
  float pin;
  float powerPin;
  
  public:
    tempSensor(int, int);
    ~tempSensor();
    void updateValue();
    float getValue();
};
