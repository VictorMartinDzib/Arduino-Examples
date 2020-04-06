int led = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led,HIGH);
  Serial.println("Prendiendo");
  delay(1000);
  digitalWrite(led,LOW);
  delay(1000);

}
