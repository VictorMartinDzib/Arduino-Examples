
int potenciometro = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
int temp = 0;
void loop() {
  // put your main code here, to run repeatedly:
  
  int potencia_entrada= analogRead(potenciometro); /// inicializamos nuestro pin analogo
  int potencia_salida= map(potencia_entrada, 0, 1023, 0, 255);
  
  if(potencia_salida >= 1 && potencia_salida <= 254)
  {
    if(potencia_salida != temp){
      Serial.write(potencia_salida);
     // Serial.print("\n" + potencia_salida);
    }
    
  }
  delay(500);
  temp = potencia_salida;

}
