int pinArray[] = {13,11,12,10,9,8,7,6,5,4};
int controlLed = 13; // LED de control
int waitNextLed = 100; 
int tailLength = 11; // Número de LED-s conectados (que es también el tamaño del array)
int lineSize = 11;
void setup(){
int i;
  pinMode (controlLed, OUTPUT);
  for(i = 0; i < lineSize; i++)
  {
    pinMode(pinArray[i], OUTPUT);
  }

}
void loop(){
  int i;
  int tailCounter = tailLength; 
  digitalWrite(controlLed, HIGH);
  for (i=0; i<lineSize; i++)
  {
    digitalWrite(pinArray[i],HIGH);
    delay(waitNextLed);
    if (tailCounter == 0){
      digitalWrite(pinArray[i-tailLength],LOW);
    }else if(tailCounter > 0){
       tailCounter--;
    }
  }
  for (i=(lineSize-tailLength); i<lineSize; i++){
    digitalWrite(pinArray[i],LOW); 
    delay(waitNextLed);
  }
}
