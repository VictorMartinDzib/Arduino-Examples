#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal.h>

int SENSOR = 3;
int TEMPERATURA;
int HUMEDAD;

const int rs = 1, en = 2, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

byte customChar[] = {
  B00000,
  B00100,
  B01010,
  B01010,
  B00100,
  B00000,
  B00000,
  B00000
};

DHT dht(SENSOR, DHT11);

void setup() {
  // put your setup code here, to run once:
 // Serial.begin(9600);
  dht.begin();
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
   lcd.createChar(0, customChar);
  lcd.print("Termometro");
 
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("Temperatura: ");
  lcd.setCursor(0, 1);
  lcd.print("Humedad: " );

}

void loop() {

  //potenciometro
  int potencia_entrada= analogRead(A0); /// inicializamos nuestro pin analogo

  // put your main code here, to run repeatedly:
  TEMPERATURA = dht.readTemperature();
  HUMEDAD = dht.readHumidity();

  lcd.setCursor(12, 0);
  // print the number of seconds since reset:
  lcd.print(String(TEMPERATURA) + (char)223+ "C");
  lcd.setCursor(10, 1);
  lcd.print(String(HUMEDAD) + "%");
  
  //Serial.print("Temperatura: ");
  //Serial.print(TEMPERATURA);
 // Serial.print(" : Humedad: ");
  //Serial.println(HUMEDAD);
  //digitalWrite(pinLed, 1);
 // delay(500);
  //digitalWrite(pinLed, 0);
}
