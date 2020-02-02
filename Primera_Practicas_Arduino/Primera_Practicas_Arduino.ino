#include <LiquidCrystal.h>

int rojo = 13;
int verde = 12;

void setup()
{
  pinMode(rojo, OUTPUT);
  pinMode(verde, OUTPUT);
}

void loop()
{
  digitalWrite(rojo, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(rojo, LOW);
  delay(1000); // Wait for 1000 millisecond(s)

  digitalWrite(verde, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(verde, LOW);
  delay(1000);
  

  mifuncion();
}

void mifuncion(){
  
}
