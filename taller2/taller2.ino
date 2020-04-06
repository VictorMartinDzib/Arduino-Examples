#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

void setup()
{
  // INDICAMOS QUE TENEMOS CONECTADA UNA PANTALLA DE 16X2
  lcd.begin(16, 2);
  // MOVER EL CURSOR A LA PRIMERA POSICION DE LA PANTALLA (0, 0)
  lcd.home();
  // IMPRIMIR "Hola Mundo" EN LA PRIMERA LINEA
  lcd.print("Eres un crack");
  // MOVER EL CURSOR A LA SEGUNDA LINEA (1) PRIMERA COLUMNA (0)
  lcd.setCursor ( 0, 1 );
  // IMPRIMIR OTRA CADENA EN ESTA POSICION
  lcd.print("GEEKFACTORY");
  // ESPERAR UN SEGUNDO
  delay(1000);
  
  Serial.begin(9600);
}
 
void loop()
{
  // EN EL CICLO PRINCIPAL SOLAMENTE RECORREMOS EL MENSAJE DE UN LADO A OTRO
  // VARIABLE PARA CONTROL DE CICLOS
  int i;
  
   // when characters arrive over the serial port...
  if (Serial.available()) {
    // wait a bit for the entire message to arrive
    delay(100);
    // clear the screen
    lcd.clear();
    // read all the available characters
    while (Serial.available() > 0) {
      // display each character to the LCD
      lcd.write(Serial.read());
      delay(100);
    }
  }
 

}
