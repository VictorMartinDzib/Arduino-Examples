short green = 13;
short yellow = 12;
short red = 11;
int time = 3000;
int timeshort = 100;

void setup()
{
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
}

void loop()
{
  digitalWrite(green, HIGH);
  delay(time); // Wait for 1000 millisecond(s)
  digitalWrite(green, LOW);
  delay(timeshort); // Wait for 1000 millisecond(s)
  
  digitalWrite(yellow, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(yellow, LOW);
  delay(timeshort); // Wait for 1000 millisecond(s)
  
  digitalWrite(red, HIGH);
  delay(time); // Wait for 1000 millisecond(s)
  digitalWrite(red, LOW);
  delay(timeshort); // Wait for 1000 millisecond(s)

  digitalWrite(yellow, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(yellow, LOW);
  delay(timeshort); // Wait for 1000 millisecond(s)
}
