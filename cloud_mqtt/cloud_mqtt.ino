#include <ESP8266WiFi.h>
#include <PubSubClient.h>
 
const char* ssid = "";
const char* password =  "";
const char* mqttServer = "";
const int mqttPort = 00000;
const char* mqttUser = "";
const char* mqttPassword = "";
const char* topic = "encender/led";

WiFiClient espClient;
PubSubClient client(espClient);

int led = 2;

boolean state = false;
 
void setup() {
 
  Serial.begin(9600);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
 
  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);
 
  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
 
    if (client.connect("ESP8266Client", mqttUser, mqttPassword )) {
 
      Serial.println("connected");  
 
    } else {
 
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
 
    }
  }
 
  client.publish(topic, "0");
  client.subscribe(topic);

  //Configurando led
  pinMode(led, OUTPUT);
  digitalWrite(led, 1);
 
}
 
void callback(char* topic, byte* payload, unsigned int length) {
 
  String state = "0";
 
  Serial.print("Estatus del led:");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
    state = (char)payload[i];
  }

  digitalWrite(led,  state.toInt());
  Serial.println();
  Serial.println("-----------------------");
 
}
 
void loop() {
  client.loop();
}
