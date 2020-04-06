int MOTOR = 3;
int i=0;
void setup()
{
  Serial.begin(9600);
  pinMode(MOTOR, OUTPUT);
  analogWrite(MOTOR,0);
}

void loop()
{
  analogWrite(MOTOR, 255);
}
