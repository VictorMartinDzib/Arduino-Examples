#include <Servo.h>

int echo = 8;
int trig = 9;
int servoA = 6;
int servoB = 5;
short ledA = 2, ledB = 4;
int UP = 90;
int DOWN = 20;
long distancia, medidas;
Servo motorA, motorB;

void setup() {
  
  Serial.begin(9600);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  motorA.attach(servoA);
  motorA.write(DOWN);
  motorB.attach(servoB);
  motorB.write(UP);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  delayMicroseconds(20);

  medidas = pulseIn(echo, HIGH);
  distancia = (medidas/2) / 29;
  Serial.println(distancia);
  if(distancia < 70){
    motorA.write(DOWN);
    motorB.write(DOWN);
    Serial.println("Abriendo tapa");
    digitalWrite(ledA,1);
    digitalWrite(ledB,1);
    delay(1);
  }else{
    //Serial.println("Abriendo tapa");
    motorA.write(UP);
    motorB.write(UP);
    digitalWrite(ledA,0);
    digitalWrite(ledB,0);
    delay(1);
  }
}
