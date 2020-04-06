int pinTrig = 9;
int pinEcho = 8;
int blanco = 3, verde = 5, rojo = 4;

float medicion, distancia;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  //Configurar el pin Trigger en modo SALIDA
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);
  pinMode(blanco, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(rojo, OUTPUT);
  digitalWrite(blanco, LOW);
  digitalWrite(verde, LOW);
  digitalWrite(rojo, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(pinTrig, HIGH);
  delay(10);
  digitalWrite(pinTrig, LOW);

  //Medimos la duración del pulso o señal de pin Echo
  medicion = pulseIn(pinEcho, HIGH);
  distancia = 0.017 * medicion;
  Serial.println("Distancia: " + String(distancia));

  if (distancia > 100) {
    Serial.println("PUERTA CERRaDA");
    digitalWrite(blanco, LOW);
    digitalWrite(verde, LOW);
    digitalWrite(rojo, HIGH);

  } else if (distancia > 60  && distancia < 100) {
        Serial.println("PUERTA MEDIO ABIERTA");
    digitalWrite(blanco, LOW);
    digitalWrite(rojo, LOW);
    digitalWrite(verde, HIGH);

  } else if (distancia < 60) {
        Serial.println("PUERTA ABIERTA");
    digitalWrite(rojo, LOW);
    digitalWrite(verde, LOW);
    digitalWrite(blanco, HIGH);
  }
}
