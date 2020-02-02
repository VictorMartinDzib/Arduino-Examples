#include <Keypad.h>

const byte filas = 4;
const byte columnas = 4;
 
char teclas[filas][columnas] = {
   { '1','2','3', 'A'},
   { '4','5','6', 'B'},
   { '7','8','9', 'C'},
   { '#','0','*', 'D'}
};
 
const byte pinFilas[filas] = { 13, 12, 11, 10 };
const byte pinColumnas[columnas] = { 9, 8, 7, 6 };
 
Keypad teclado = Keypad(makeKeymap(teclas), pinFilas, pinColumnas, filas, columnas);
 
void setup() {
   Serial.begin(9600);
}
 
void loop() {
   char clave = teclado.getKey();
 
   if (clave) {
      Serial.println(clave);
   }
}
