//PRIMERA PRACTICA

String texto = "";

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()){
    //texto = Serial.read();
    texto = Serial.readString();
    if(texto.equals("NA")){
      Serial.println("APROBADO");
    }else{
      Serial.println("REPROBADO, DATE DE BAJA");
    }
    Serial.println(texto);
    delay(5000);
  }else{
    //Serial.println("No hay comunicación");
  }
}
