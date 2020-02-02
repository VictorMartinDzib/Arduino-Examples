/*  Sensor PIR con Arduino
 *
 *  Escrito por Nano en beneficio de los seres humanos
 *  www.robologs.net
 */
 
int sensor = 2;
int led = 13;
 
  
void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(sensor, INPUT);
}
  
void loop()
{
  int lectura = digitalRead(sensor);
  Serial.println(lectura);
  digitalWrite(led, lectura);
}
