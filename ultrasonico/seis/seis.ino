int leds[] = {2,3,4};
int times = 1000;
int size = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i=0; i < size; i++)
  {
    pinMode(leds[i],  OUTPUT);
  }
}
void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i < 3; i++)
  {
    int j=0, k=0;
    for(j=0; j<size; j++){
      digitalWrite(leds[j], 1);
      delay(times);
      digitalWrite(leds[j], 0);
      delay(times-800);
      Serial.println(j);
    }
    for(k=size-2; k>0; k--){
      digitalWrite(leds[k], 1);
      delay(times);
      digitalWrite(leds[k], 0);
      delay(times-800);
      Serial.println(k);
    }
  }

  Serial.println("APAGANDO..");
  for(int a = 0; a < size; a++){
    digitalWrite(leds[a], 1);
    Serial.println(a);
    //
  }
  delay(times);
  for(int b = 0; b < size; b++){
    digitalWrite(leds[b], 0);
    Serial.println(b);
  }
  delay(times);
  Serial.println("Reiniciando..");
}
