#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
#include <Servo.h>

int D0 = 16, D1=5, D3=0,D5=14, D7=13;
float distancia, duracion; //long valores decimales
int posicion1 = 360;
int posicion2 = -90;
Servo miServo; //al pin 13
Servo miServito;
int Pecho = D0; //Echo al pin 6
int Ptrig = D1; //Trig pin 7
int led = D3;
int derecho = 0;
int derecho_cuenta = 0;
int derecho_ahora = 0;
int derecho_anterior = 0;
int cuenta;
String capacidad = "";

//Cambia estos datos
#define SSID_WIFI "Familia_Martin"
#define PASS_WIFI "8C61A3BE0B42"


/*No toques nada de aca*/
#define HOST "https://covid-19-gel.firebaseio.com/"
#define AUTH "a28sBk0MtWp1k8KDMvdZKuYLOJzd0cFtCTHrFN6f"
FirebaseData datosFirebase;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //1.3 Accedemos a la red agregando como parametro las credenciales
  WiFi.begin(SSID_WIFI, PASS_WIFI);
  Serial.println("Accediendo a la red " + String(SSID_WIFI));
  //1.4 validamos el estado de la conexion para verificar
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("UwU");
    delay(1000);

  }
  Serial.println("Conectando a " + String(SSID_WIFI));
  //1.5Obtenemos la ip asignada
  Serial.println(WiFi.localIP());

  //2.3  Conexion a firebase con las credenciales host, llave secreta
  Firebase.begin(HOST, AUTH);
  pinMode(Pecho, INPUT);
  pinMode(Ptrig, OUTPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  miServo.attach (D7);
  miServito.attach(D5);
  cuenta = Firebase.getInt(datosFirebase, "Dispensador/cont");
}

void loop() {

  if (Firebase.getString(datosFirebase, "Dispensador/estatus")) {
    if (datosFirebase.dataType() == "string") {
      String estatus = datosFirebase.stringData();
      if (estatus == "off") {
        digitalWrite(D3, LOW);
        Serial.println("Apagado");
      } else {
        Serial.println("prendido");
        servo();
        delay(1000);
        contar();
      }
    }
  } else {
    Serial.println("LO SIENTO");
    delay(1000);
  }

}
void servo() {
  int cont = 0;

  digitalWrite (Ptrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Ptrig, LOW); //genera el pulso de triger de 10ms
  delayMicroseconds(30);
  duracion = pulseIn(Pecho, HIGH); //con esto sabemos cuanto tiempo estuvo en alto(HIGH)
  distancia = 0.017 * duracion; //   calcula la distancia en centimetros

  Serial.println(distancia);
  if (distancia < 15) {
    miServo.write(posicion1);                //mueve el servo si la distancia es menor a 50cm
    miServito.write(posicion2);
    //envia la palabra "obstaculo" por el puerto serial }
    derecho = HIGH;
    Serial.println("Obstaculo");
  }
  else {
    miServo.write(posicion2);
    miServito.write(posicion1);
    derecho = LOW;
    digitalWrite(led, LOW);

  }
  if (derecho ==  HIGH) { // Comprueba activado derecho.
    derecho_ahora = 1;
  }
  else {
    derecho_ahora = 0;
  }
  if (derecho_ahora != 0) {
    if (derecho_ahora == 1) {
      derecho_cuenta = derecho_cuenta + 1;
    }
  }

  if (derecho == HIGH )
  {
    cuenta += 1;
    Serial.print("Subido ");
    Serial.println(cuenta);
    Firebase.setInt(datosFirebase, "Dispensador/cont", cuenta);
    delay(100);
  }


}

void contar() {
  if (Firebase.getInt(datosFirebase, "Dispensador/cont")) {
    if (datosFirebase.dataType() == "int") {
      int co = datosFirebase.intData();
      if (co <= 10 ) {
        digitalWrite(D3, LOW);
        capacidad = "Lleno";
        Firebase.setString(datosFirebase, "Dispensador/capacidad", capacidad);
      } else if (co >= 11 && co <= 20) {
        capacidad = "Medio";
        Firebase.setString(datosFirebase, "Dispensador/capacidad", capacidad);
      }
      else if (co >= 21 && co <= 30) {
        capacidad = "Vacío";
        Firebase.setString(datosFirebase, "Dispensador/capacidad", capacidad);
      }
      else {
        digitalWrite(D3, LOW);
      }
    }
  }
}
