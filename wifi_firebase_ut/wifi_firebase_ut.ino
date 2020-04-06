#include<ESP8266WiFi.h> //libreria para wifi para el modulo 
#include<FirebaseESP8266.h> // libreria de firebase 

#define HOST "https://casa1-3e193.firebaseio.com/" // Link de la base de datos
#define AUTH "nnuDtrcWE3uQ1chOn3QOmxZmF8ZlAIeIfs9k4rgl"  // llave secreta generada en firebase
#define SSID_WIFI "ServerLab2" // nombre del wifi
#define PASS_WIFI "DITCisco98" // cotraseña del wifi



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // conrol + t acomoda el codigo
  WiFi.begin(SSID_WIFI, PASS_WIFI); //parametro del wifi y password
  Serial.println("Accediendo a la red "+ String(SSID_WIFI));

  while(WiFi.status()!=WL_CONNECTED){

    Serial.println(">>>>");
    delay(1000);
    
  }

  Serial.println("Conectado a "+ String(SSID_WIFI));
  Serial.println("Nuestra ip es: ");
  Serial.print(WiFi.localIP());


}

void loop() {
  // put your main code here, to run repeatedly:

}
