#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <Servo.h>
#include <string>
#include <iostream>
/*  
 *   Configuraciones de conexion de red wifi y MQTT
 */
 
const char* ssid = "Familia_Martin";
const char* password =  "8C61A3BE0B42";
const char* mqttServer = "hairdresser.cloudmqtt.com";
const int mqttPort = 16804;
const char* mqttUser = "ltqpcycu";
const char* mqttPassword = "OlLSDbmIx4pU";

const char* topic_stored = "smarttrash/stored";
const char* topic_distance = "smarttrash/distance";
const char* topic_status = "smarttrash/status";
WiFiClient espClient;
PubSubClient client(espClient);

/*
 * Configuracion de componentes
 */

int D0 = 16, D1=5, D3=2,D5=14, D7=13;
int Pecho = D0; //Echo al pin 6
int Ptrig = D1; //Trig pin 7
int led = D3;
int servo1=D5;
int servo2=D7;
float duracion=0, distancia=0;
Servo servoA;
Servo servoB;
long count = 0;
int publish_data = 0;
 
void setup() {
 
  Serial.begin(9600);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("conectando a la red " + String(ssid) + "...");
  }
  Serial.println("Te has conectado!");
 
  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);
 
  while (!client.connected()) {
    Serial.println("Conectando al servidor mqtt: " + String(mqttServer) + "...");
 
    if (client.connect("ServidorMQTT", mqttUser, mqttPassword )) {
 
      Serial.println("Te has conectado al servidor MQTT!");  
 
    } else {
 
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
 
    }
  }
 
  client.publish(topic_stored, "0");
  client.publish(topic_distance,"0");
  client.publish(topic_status, "0");
  
  client.subscribe(topic_stored);
  client.subscribe(topic_distance);
  client.subscribe(topic_status);

  //estableciendo componentes
  pinMode(Pecho, INPUT);
  pinMode(Ptrig, OUTPUT);
  
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);

  servoA.attach(servo1);
  servoB.attach(servo2);
 
}
 
void callback(char* topic, byte* payload, unsigned int length) {
 
  String state = "0";
 
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
    state = (char)payload[i];
  }

  digitalWrite(led,  state.toInt());
  Serial.println();
  Serial.println("-----------------------");
 
}
 
void loop() {

  /*
   * Leyendo distancia
   */

  digitalWrite (Ptrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Ptrig, LOW); //genera el pulso de triger de 10ms
  delayMicroseconds(30);
  duracion = pulseIn(Pecho, HIGH); //con esto sabemos cuanto tiempo estuvo en alto(HIGH)
  distancia = 0.017 * duracion; //   calcula la distancia en centimetros
  //Serial.println((int) distancia);
 
  detectDistance((int) distancia);
  /*
   * Ejecutando cliente
   */
  client.loop();

}

void detectDistance(int dist){
  
  if(dist <= 30){

      count++;  

      if(publish_data == 0){
      client.publish(topic_stored, String(count).c_str());
      client.publish(topic_distance, String(dist).c_str());
      client.publish(topic_status, "1");
      }

      servoA.write(90);
      servoB.write(90);

      //delay(1000);
      publish_data++;
    
   }  else  {
    publish_data = 0;
    servoA.write(0);
     servoB.write(0);
    
    }
}
