int led = 3;
int pwm;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    pwm = Serial.read();
    analogWrite(led, pwm);
  }
}
