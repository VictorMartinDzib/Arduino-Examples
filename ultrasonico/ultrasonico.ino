int pinTrig = 13;
int pinEcho = 5;
int led = 3;

float medicion, distancia;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);
}

void loop() {
  // encendemos el TRIG
  digitalWrite(pinTrig, HIGH);
  delayMicroseconds(10);
  //Medimos la duración del pulso o señal del pin Echo
  medicion = pulseIn(pinEcho, HIGH);
  //calculamos la distancia
  distancia = (medicion/2) / 29;
  Serial.println("La distancia es: " + String(distancia));
}
