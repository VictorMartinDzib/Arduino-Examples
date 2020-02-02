// Arduprofe, Prueba movimiento Servomotores
// Mueve servos (8,7 y 4) de extremo a extremo con parada en el centro
// Debe instalr la libreria Servo.h para que funcione el programa

#include <Servo.h>                // Incluye la libreria Servo
 
Servo servo;
void setup() 
{ 
  servo.attach(6,660,1400);    // Asocia el servo1 al pin 8, define el min y max del ancho del pulso   
}   
void loop() 
{                    
       //Gira el servo a 150 grados 
       servo.write(0);
       delay(700);
       
       servo.write(180);
       delay(700);                 
} 
