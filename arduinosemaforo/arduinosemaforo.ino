int led1Verde = 13;
int led2Blanco = 12;
int led3Rojo = 11;
int tiempo = 300;
int pause= 100; 
void setup()
{
  pinMode(led1Verde,OUTPUT);
  pinMode(led2Blanco,OUTPUT);
  pinMode(led3Rojo,OUTPUT);
}
void loop()
{ 
  digitalWrite(led1Verde, HIGH);
  delay(tiempo ); 
  digitalWrite(led1Verde, LOW);
  delay(pause); 
  
  digitalWrite(led2Blanco, HIGH);
  delay(tiempo * 2); // Wait for 1000 millisecond(s)
  digitalWrite(led2Blanco, LOW);
  delay(pause); // Wait for 1000 millisecond(s)
  
  digitalWrite(led3Rojo, HIGH);
  delay(tiempo * 3); // Wait for 1000 millisecond(s)
  digitalWrite(led3Rojo, LOW);
  delay(pause); // Wait for 1000 millisecond(s)

  digitalWrite(led2Blanco, HIGH);
  delay(tiempo * 2); // Wait for 1000 millisecond(s)
  digitalWrite(led2Blanco, LOW);
  delay(pause); // Wait for 1000 millisecond(s)

 
  
}
