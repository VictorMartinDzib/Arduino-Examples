#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Definiendo parametros de conexion
#define FIREBASE_HOST "ledhome-62346.firebaseio.com"
#define FIREBASE_AUTH "Y9f5MwRAnxDENncFdd2YslbVCefLRZOWs6BJP1rX"
#define WIFI_SSID "Familia_Martin"
#define WIFI_PASSWORD "8C61A3BE0B42"
int led = 13;
String estado = "";
int pwm = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT); 
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  digitalWrite(led, 0);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
 // Firebase.setInt("estado", 0);
}

void loop()
{
  estado = Firebase.getString("Led/estado");
  if (Firebase.failed()) {
      Serial.print("Error al obtener estado del led");
      Serial.println(Firebase.error());  
      return;
  } 
  Serial.println("Estado del led: " + (String) estado);
  //digitalWrite(led, estado);
  delay(100);
}
