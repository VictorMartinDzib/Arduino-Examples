#include <Servo.h>

int echo = 8;
int trig = 9;
int servo = 6;
short a = 2;
long distancia, medidas;
Servo palanca;

void setup() {
  Serial.begin(9600);1
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(a, OUTPUT);
  palanca.attach(servo);
  palanca.write(0);
}

void loop() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  delayMicroseconds(20);

  medidas = pulseIn(echo, HIGH);
  distancia = (medidas/2) / 29;
  Serial.println(distancia);
  if(distancia < 30){
    palanca.write(90);
    digitalWrite(a,1);
    delay(1000);
  }else{
    palanca.write(0);
    digitalWrite(a,0);
    delay(100);
  }
}
