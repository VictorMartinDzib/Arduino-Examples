//SEGUNDA

int led = 3;
String texto = "";

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
 // analogWrite(led, 255);
  if (Serial.available()){
    //texto = Serial.read();
    texto = Serial.readString();
    if(texto.equals("encendido\n")){
      Serial.println("Led encendido");
      analogWrite(led, 255);
    }else if(texto.equals("apagado\n")){
      Serial.println("Led apagado");
      analogWrite(led, 0);
    }else{
        analogWrite(led, texto.toInt());
    }
    Serial.println(texto);
    delay(100);
  }else{
    //Serial.println("No hay comunicación");
  }
}
