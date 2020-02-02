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
  color(255, 0, 255);
  digitalWrite(pinLedR, 1);
  
}

// funcion para generar colores
void color (int rojo, int verde, int azul) {
  analogWrite(pinLedR, rojo);
  analogWrite(pinLedV, verde);
  analogWrite(pinLedA, azul);
}

/*
for(int i=0; i <= 255; i ++){
    for(int j=b; j <= 255; j++)
    {
      if(j==255){
          b = 255;
       }
      for(int k=a; k <= 255; k++)
      {
        
        color(i, j, k);
        if(k==255){
          a = 255;
        }
        Serial.println("color(" + String(i)+"," + String(j) + ", " + String(k) +")");
        //delay(pausa);
      }
    }
  }
*/
