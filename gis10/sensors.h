#include <Arduino.h>

class sensors{
  
  protected:
    float currentValue;
  public:
    virtual void updateValue();
    virtual float getValue();
};
