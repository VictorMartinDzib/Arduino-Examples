#include <SimpleDHT.h>
int pinSensor = 3;
int pinLed = 4;
SimpleDHT11 dht11(pinSensor); // invocar el metodo de la libreria
void setup() {
  Serial.begin(9600);
  pinMode(pinLed, OUTPUT);
}
void loop() {
  byte temperatura = 0;
  byte humedad = 0;
  int error = SimpleDHTErrSuccess;
  if ((error = dht11.read(&temperatura, &humedad, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("No se ha detectado la temperatura"); Serial.println(error);delay(2000);
    return;
  }
  if((int)temperatura >= 29){
    digitalWrite(pinLed, 1);
  }else{
    digitalWrite(pinLed, 0);
  }
  Serial.print((int)temperatura); Serial.print(" *C, ");
  Serial.print((int)humedad); Serial.println(" RH%");
}
