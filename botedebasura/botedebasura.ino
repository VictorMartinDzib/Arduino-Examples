#include <Servo.h>

int echo = 8;
int trig = 9;
int servo = 6;
int servo2=5;
short a = 2, b = 4;
int degres = 90;
int degres2 = 20;
long distancia, medidas;
Servo palanca, palanca2;

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  palanca.attach(servo);
  palanca.write(degres);
  palanca2.attach(servo2);
  palanca2.write(degres2);
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
  if(distancia < 90){
    palanca.write(degres2);
    palanca2.write(degres);
    Serial.println("Abriendo tapa");
    digitalWrite(a,1);
    digitalWrite(b,1);
    delay(1000);
  }else{
    //Serial.println("Abriendo tapa");
    palanca.write(degres);
    palanca2.write(degres2);
    digitalWrite(a,0);
    digitalWrite(b,0);
    delay(100);
  }
}
