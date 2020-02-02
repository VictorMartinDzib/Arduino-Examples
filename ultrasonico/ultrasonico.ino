int pinTrig = 9;
int pinEcho = 8;
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
  distancia = 0.017 * medicion;
  Serial.println("La distancia es: " + String(distancia));
  if(distancia < 30){
    digitalWrite(led, 1);
  }else{
    digitalWrite(led, 0);
  }
}
