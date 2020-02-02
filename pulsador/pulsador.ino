int led = 4;
int boton = 3;
int time = 10000; //Tiempo
void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(boton, INPUT); //Se define como entrada de datos
  digitalWrite(led, LOW);
}

void loop()
{
  while(digitalRead(boton)==LOW){
      Serial.println("Bloqueado en el ciclo" );

  }
  digitalWrite(led, HIGH);
   Serial.println("ESPERANDO 10 SEGUNDOS");
  delay(time); // tiempo de suspension
  digitalWrite(led, LOW);
  delay(100); // Wait for 1000 millisecond(s)
}
