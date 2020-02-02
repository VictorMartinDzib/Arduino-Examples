int p1=0, p2=0; 


void setup() {
  pinMode(13, OUTPUT);
  pinMode(2, INPUT);
  Serial.begin(9660);
}

int count = 0;
void loop() {
  p1 = digitalRead(2);   
  if (p1 == HIGH && p2 == LOW) {
    digitalWrite(13, HIGH);
    Serial.println("Pulsando");
    p1 = LOW;
  }
  else {
    digitalWrite(13, LOW);
  } 
  p2 = p1;
}
