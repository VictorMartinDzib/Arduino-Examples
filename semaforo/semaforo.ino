
int ledverde = 13;
int ledamarillo = 12;
int ledrojo = 11;
int delayVal = 0;

int array[] = {13, 12, 11};

void setup()
{
  pinMode(ledverde, OUTPUT);
  pinMode(ledamarillo, OUTPUT);
  pinMode(ledrojo, OUTPUT);
}

void loop()
{
  
  digitalWrite(ledverde, HIGH);
  delay(2000);// Wait for 1000 millisecond(s)
  
  digitalWrite(ledverde, LOW);
  delay(500);
  
 digitalWrite(ledamarillo, HIGH);
  delay(50);
  
   digitalWrite(ledamarillo, LOW);
  delay(500);
  
  digitalWrite(ledamarillo, HIGH);
  delay(500);
  
   digitalWrite(ledamarillo, LOW);
  delay(50);
  
  digitalWrite(ledamarillo, HIGH);
  delay(500);
  
   digitalWrite(ledamarillo, LOW);
  delay(50);
  
  digitalWrite(ledamarillo, HIGH);
  delay(500);
  
   digitalWrite(ledamarillo, LOW);
  delay(50);
 // delay(100); // Wait for 1000 millisecond(s)
  digitalWrite(ledrojo, HIGH);
  delay(1000);
  
  digitalWrite(ledrojo, LOW);
  delay(500);
  
 
  
}
