
#include <IRremote.h>

int rojo = 11, azul = 10, verde = 9;
int sensor = 3;

#define on 0xF7C03F
#define off 0xF740BF
#define up 0xF700FF
#define down 0xF7807F

IRrecv irrecv(sensor);
decode_results codigo;
long pwm = 0;
int led = 13;
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(rojo, OUTPUT);
  pinMode(azul, OUTPUT);
  pinMode(led, OUTPUT);
}

void loop()
{
  irrecv.sendRaw();
  if (irrecv.decode(&codigo))
  {
    Serial.println(codigo.value, HEX);
    irrecv.resume();

    if (codigo.value == on) {
      analogWrite(led, 255);
    } else if (codigo.value == off) {
      analogWrite(led, 0);
    } else if (codigo.value == up) {
      if (pwm <= 255) {
        pwm += 5;
      }
      analogWrite(led, pwm);
    } else if (codigo.value == down) {
      if (pwm >= 0) {
        pwm -= 5;
      }
      analogWrite(led, pwm);
    }
  }

}
