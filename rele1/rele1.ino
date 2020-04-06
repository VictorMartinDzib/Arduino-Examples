int rele = 2;
/***   Setup  ***/
void setup() {
    pinMode(rele,OUTPUT);
}
 
/***   Loop  ***/
void loop() {
    digitalWrite(rele,LOW);
    delay(3000);
    digitalWrite(rele,HIGH);
    delay(3000);
}
