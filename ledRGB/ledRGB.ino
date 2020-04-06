int pinLedR = 3;  // pin Rojo del led RGB
int pinLedV = 5;  // pin Verde del led RGB
int pinLedA = 6;   // pin Azul del led RGB

int pausa = 100;
int a = 0, b=0, c=0;

void setup() {
  Serial.begin(9600);
  pinMode(pinLedR, OUTPUT);    // pone el pinLedR como output
  pinMode(pinLedV, OUTPUT);    // pone el pinLedV como output
  pinMode(pinLedA, OUTPUT);    // pone el pinLedA como output
}

void loop() {
  //  colores basicos:
       // delay por pausa
  digitalWrite(pinLedR, 1);
  digitalWrite(pinLedV, 1);
  digitalWrite(pinLedA, 1);  
}

// funcion para generar colores
void color (int rojo, int verde, int azul) {
  analogWrite(pinLedR, rojo);
  analogWrite(pinLedV, verde);
  analogWrite(pinLedA, azul);
}
