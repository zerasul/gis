#include <Arduino.h>
#include "sensors.h"

class humiditySensor:sensors{
  private:
    int pin;
    int powerPin;
  public:
    humiditySensor(int, int);
    ~humiditySensor();
    void updateValue();
    float getValue();
};
