
class Buttons {
 
 private:
  boolean  buttonStates[5];
  boolean  latchButtons[5];
  int ButtonPin1;
  int ButtonPin2;
  int ButtonPin3;
  int ButtonPin4;
  int ButtonPin5;
 public:
   Buttons(int,int,int, int, int);
   ~Buttons();
   boolean[] generateButtonState();
   boolean[] controlButtons();
}
