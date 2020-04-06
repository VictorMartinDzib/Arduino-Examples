#include <Servo.h>

int pinServo = 6;
int rojo = 13;
int amarillo = 12;
int verde = 11;

Servo servo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(pinServo);
  pinMode(rojo, OUTPUT);
   pinMode(amarillo, OUTPUT);
    pinMode(verde, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int potencia_entrada= analogRead(A0); /// inicializamos nuestro pin analogo
  int potencia_salida= map(potencia_entrada, 0, 1023, 0, 180);
  if(potencia_salida <=1 ){
    digitalWrite(rojo, 1);
    digitalWrite(verde, 0);
    digitalWrite(amarillo, 0);
  }else if(potencia_salida >= 88 && potencia_salida <= 92){
        digitalWrite(rojo, 0);
    digitalWrite(verde, 0);
    digitalWrite(amarillo, 1);
  }else if(potencia_salida >= 179){
    digitalWrite(rojo, 0);
    digitalWrite(verde, 1);
    digitalWrite(amarillo, 0);
  }
  analogWrite(3, potencia_salida);
  Serial.println("entrada> "+ String(potencia_entrada)+"- salida>"+String(potencia_salida));
  servo.write((int) potencia_salida);
}
