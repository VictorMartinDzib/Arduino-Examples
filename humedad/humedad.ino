#include <DHT.h>
#include <DHT_U.h>

int SENSOR = 3;
int TEMPERATURA;
int HUMEDAD;
int pinLed = 7;


DHT dht(SENSOR, DHT11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinLed, OUTPUT);
  dht.begin();
}

void loop() {

  //potenciometro
  int potencia_entrada= analogRead(A0); /// inicializamos nuestro pin analogo
  //int potencia_salida= map(potencia_entrada, 0, 1023, 0, 255);
  analogWrite(pinLed, potencia_entrada);
  //Serial.println("entrada> "+ String(potencia_entrada)+"- salida>"+String(potencia_salida));

  
  // put your main code here, to run repeatedly:
  TEMPERATURA = dht.readTemperature();
  HUMEDAD = dht.readHumidity();
  Serial.print("Temperatura: ");
  Serial.print(TEMPERATURA);
  Serial.print(" : Humedad: ");
  Serial.println(HUMEDAD);
  //digitalWrite(pinLed, 1);
  delay(500);
  //digitalWrite(pinLed, 0);
}
