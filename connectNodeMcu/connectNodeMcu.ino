#include "ESP8266WiFi.h"

char* ssid = "Familia_Martin";
char* pass = "8C61A3BE0B42";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(10);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);

  Serial.print("Conectando a:\t");
  Serial.println(ssid); 
 
  // Esperar a que nos conectemos
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(200);
   Serial.print('.');
  }
 
  // Mostrar mensaje de exito y dirección IP asignada
  Serial.println();
  Serial.print("Conectado a:\t");
  Serial.println(WiFi.SSID()); 
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());

}

void loop() {
  // put your main code here, to run repeatedly:

}
