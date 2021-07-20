#include "klasy.h"
#include "arduino.h"
#define x A0
#define y A1
void Silnik::jedz()
{

analogWrite(pin_predkosc, predkosc);
digitalWrite(pin_sterowanie_1,HIGH);
digitalWrite(pin_sterowanie_2,LOW);

}

int Joy::steruj_x()
{
  int parametr_x;
  parametr_x=analogRead(x);
  parametr_x= map(parametr_x, 0, 1023, 0, 9);
  return parametr_x;
  
}

int Joy::steruj_y()
{
  int parametr_y;
  parametr_y=analogRead(y);
  parametr_y= map(parametr_y, 0, 1023, 0, 9);
  return parametr_y;
  
}

Joy::Joy(char n, char m)
{
  x = n;
  y = m;
}

Silnik::Silnik(int  p1, int  p2, int pv, double v)
{
  pin_predkosc = pv;
  pin_sterowanie_1 = p1;
  pin_sterowanie_2 = p2;
  predkosc = v;
}

void Silnik::wypelnij(int p1, int p2, int pv, double v)
{
  pin_predkosc = pv;
  pin_sterowanie_1 = p1;
  pin_sterowanie_2 = p2;
  predkosc = v; 
}
