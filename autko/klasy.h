#ifndef tl
#define tl
#define x A0
#define y A1
#include "arduino.h"
class Silnik
{
  public:
int pin_predkosc;
int pin_sterowanie_1;
int pin_sterowanie_2;
double predkosc;

  Silnik(int = 0, int = 0, int = 0, double = 0.0);

void jedz();
void wypelnij(int, int, int, double);

};

class Joy
{
  public:

  char x, y;

  Joy(char = 0, char = 0);

  int steruj_x();
  int steruj_y();  
  
};



#endif 
