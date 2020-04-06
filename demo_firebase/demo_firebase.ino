//#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "ledhome-62346.firebaseio.com"
#define FIREBASE_AUTH "Y9f5MwRAnxDENncFdd2YslbVCefLRZOWs6BJP1rX"
#define WIFI_SSID "Familia_Martin"
#define WIFI_PASSWORD "8C61A3BE0B42"

void setup() {
  Serial.begin(9600);

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
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

int n = 0;
int i = 1;
void loop() {
  // set value
  Firebase.setFloat("number", 42.0);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);
  
  // update value
  Firebase.setFloat("number", 43.0);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);

  // get value 
  Serial.print("number: ");
  Serial.println(Firebase.getFloat("number"));
  delay(1000);

  // remove value
  Firebase.remove("number");
  delay(1000);

  // set string value
  if(i<2){
    Firebase.setString("message", "hello world");
  }
  
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /message failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);
  
  // set bool value
  Firebase.setBool("truth", false);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /truth failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);

  Serial.println("Leyendo bd...");
  delay(1000);
  String value = Firebase.getString("message");
  Serial.println("message; " + value);
  Serial.println("Recuperando ejecucion");
  delay(1000);
  // append a new value to /logs
  String name = Firebase.pushInt("logs", n++);
  // handle error
  if (Firebase.failed()) {
      Serial.print("pushing /logs failed:");
      Serial.println(Firebase.error());  
      return;
  }
  Serial.print("pushed: /logs/");
  i++;
  Serial.println(name);
  delay(1000);
}
