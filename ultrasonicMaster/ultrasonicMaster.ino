
#define echo 8
#define trig 9

long valores, distancia;

void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {

  digitalWrite(trig, 1);
  delayMicroseconds(10);
  digitalWrite(trig, 0);
  delayMicroseconds(20);

  valores = pulseIn(echo, 1);

  distancia = valores * 0.017;

  if(distancia >= 100){
    Serial.write('b');
  }else if(distancia >= 50 && distancia < 100){
    Serial.write('g');
  }else{
    Serial.write('r');
  }
 // Serial.println(distancia);
}
