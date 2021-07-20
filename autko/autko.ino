#include "klasy.h"
#define B 2
#define x A0
#define y A1
int V;
int skret;

void setup() {
pinMode(6, OUTPUT);
digitalWrite(6,HIGH);
pinMode(5, OUTPUT);
digitalWrite(5,HIGH);

pinMode(7, OUTPUT);
pinMode(8,OUTPUT);
pinMode(4, OUTPUT);
pinMode(9,OUTPUT);
pinMode(B, INPUT);

Serial.begin(9600);

}

void loop() {
Joy ster(x, y);
int prd = 255;
Silnik s1;
Silnik s2;
skret = ster.steruj_x();
V = ster.steruj_y();
Serial.print("Y: ");
Serial.println(V);
Serial.print("X: ");
Serial.println(skret);

if(V == 4 && skret ==4)
{
 s1.wypelnij(7,8,6,0);
 s2.wypelnij(9,4,5,0);

}
else if(V > 4)
{
  if(skret == 4)
  {
    s1.wypelnij(7,8,6,(200 + (V-4)*11)); //(200 + (V-4)*11)
    s2.wypelnij(9,4,5,(200 + (V-4)*11)); 
   
  }
  else if (skret > 4)
  {
    s1.wypelnij(7,8,6,200);
    s2.wypelnij(9,4,5,(200 + (skret-4)*11));
  
  }
   else if (skret < 4)
  {
    s1.wypelnij(7,8,6,(200 + (skret-4)*11));
    s2.wypelnij(9,4,5,200);
  
    
  }
}
else if(V < 4)
{
  if(skret == 4)
  {
    s1.wypelnij(8,7,6,(200 + abs(V-4)*11));
    s2.wypelnij(4,9,5,(200 +abs(V-4)*11)); 
       

  }
  else if (skret > 4)
  {
    s1.wypelnij(8,7,6,200);
    s2.wypelnij(4,9,5,(200 + (skret-4)*11));   

  }
   else if (skret < 4)
  {
    s1.wypelnij(8,7,6,(200 + abs(skret-4)*11));
    s2.wypelnij(4,9,5,200);
   
    
  }
}

else if(V==4 && skret > 4)
{
 s1.wypelnij(7,8,6,(200+(V-4)*11));
 s2.wypelnij(9,4,5,0);

}
else if( V==4 && skret < 4)
{
  s1.wypelnij(7,8,6,0);
  s2.wypelnij(9,4,5,(200+abs(V-4)*11));

}
 
  s1.jedz();
  s2.jedz();


}
