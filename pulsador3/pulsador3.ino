int led = 4;
int boton = 3;
int time = 10000;

void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(boton, INPUT);
  digitalWrite(led, LOW);
}

void loop()
{
  digitalWrite(led, LOW);
  while(digitalRead(boton)==LOW){//Se bloquea apagado
  }
  digitalWrite(led, HIGH); //se sale del cicio y se enciende
  while(digitalRead(boton)==LOW){ //Se bloque encendido
  } 
}
