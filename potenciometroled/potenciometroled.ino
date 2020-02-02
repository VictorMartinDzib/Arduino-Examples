

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int potencia_entrada= analogRead(A0); /// inicializamos nuestro pin analogo
  int potencia_salida= map(potencia_entrada, 0, 1023, 0, 295);
  analogWrite(3, potencia_salida);
  Serial.println("entrada> "+ String(potencia_entrada)+"- salida>"+String(potencia_salida));
  
}
