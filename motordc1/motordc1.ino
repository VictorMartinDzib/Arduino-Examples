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
  for(i=0; i <= 255; i++){
   analogWrite(MOTOR, i);
    Serial.println(i);
    delay(500);
  }
  
  for(i=255; i >= 0; i--){
   analogWrite(MOTOR, i);
    Serial.println(i);
    delay(500);
  }
}
