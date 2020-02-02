#include <Ultrasonic.h>
#include <Servo.h> 

Ultrasonic sensorA(7, 6); //pin trig, pin echo  
Ultrasonic sensorB(8,9); //pin trig, pin echo 9,8
int ledA=13; //pin del arduino que se conecta al led
int ledB=12; //pin del arduino que se conecta al led
int ledrojo=12; //pin del arduino que se conecta al led
int distanciaA; // variable de distancia del ultrasonico derecho
int distanciaB; // variable de distancia del ultrasonico izquierdo
int pausa; //retardo del led en encender y apaga dependiendo del sensor

Servo servoA;
Servo servoB;
int pinA=2, pinB=3;


void setup(){
  pinMode(ledA,OUTPUT);
  pinMode(ledB,OUTPUT);
 // pinMode(ledrojo,OUTPUT);
  servoA.attach(pinA,660,1400);
  servoB.attach(pinB,660,1400);
  
  Serial.begin(9600);
}

void loop(){
  distanciaA = sensorA.Ranging(CM);
  distanciaB = sensorB.Ranging(CM);

  if( distanciaB < 15 && distanciaB != 5){
    Serial.print("Abriendo paso para la salida");
    pausa = 2000;
    digitalWrite(ledB, HIGH);
    servoB.write(150);
  
  }else if(distanciaA < 15){
    Serial.println("Abrendo paso para la entrada");
    pausa = 2000;
    digitalWrite(ledA, HIGH);
    servoA.write(180);
  }else{
    digitalWrite(ledB, LOW);
    servoB.write(40);
    digitalWrite(ledA, LOW);
    servoA.write(60);
    pausa = 50;
  }
  
  Serial.print(distanciaA);
  Serial.print(" : ");
  Serial.print(distanciaB);
  Serial.println("");
  delay(pausa);
}
