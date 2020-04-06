int azul = 7, verde = 6, rojo = 5;
char dato;

void setup(){
  Serial.begin(9600);
  pinMode(azul, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(rojo, OUTPUT);
}

void loop(){
  if(Serial.available()){
    dato = Serial.read();
    switch(dato){
      case 'b':
        digitalWrite(azul, 1);
        digitalWrite(rojo, 0);
        digitalWrite(verde, 0);
      break;
      case 'g':
        digitalWrite(verde, 1);
        digitalWrite(rojo, 0);
        digitalWrite(azul, 0);
      break;
      case 'r':
        digitalWrite(rojo, 1);
        digitalWrite(verde, 0);
        digitalWrite(azul, 0);
      break;
      default:
        digitalWrite(rojo, 1);
        digitalWrite(verde, 0);
        digitalWrite(azul, 0);
    }
  }
}
