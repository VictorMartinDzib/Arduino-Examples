// * Happy Birthday to You
// * Original Composition :
// * Composed by :
// * Coded By - http://forum.arduino.cc/index.php?topic=178460.0
// * Use BSD Clause 2 License for Distribution
// * Collection by GitHub User @abhishekghosh - https://github.com/AbhishekGhosh/Arduino-Buzzer-Tone-Codes

#define LDRPin A0
int BuzzerPin = 3;

// Variable donde se almacena el valor del LDR
int LDRValue = 5;

int length = 28; // the number of notes

char notes[] = "GGAGcB GGAGdc GGxecBA yyecdc";

int beats[] = { 2, 2, 8, 8, 8, 16, 1, 2, 2, 8, 8, 8, 16, 1, 2, 2, 8, 8, 8, 8, 16, 1, 2, 2, 8, 8, 8, 16 };

int tempo = 150;

void playTone(int tone, int duration) {

  for (long i = 0; i < duration * 1000L; i += tone * 2) {

    digitalWrite(BuzzerPin, HIGH);

    delayMicroseconds(tone);

    digitalWrite(BuzzerPin, LOW);

    delayMicroseconds(tone);

  }

}

void playNote(char note, int duration) {

  char names[] = {'C', 'D', 'E', 'F', 'G', 'A', 'B',

                  'c', 'd', 'e', 'f', 'g', 'a', 'b',

                  'x', 'y'
                 };

  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014,

                  956,  834,  765,  593,  468,  346,  224,

                  655 , 715
                };

  int SPEE = 5;

  // play the tone corresponding to the note name

  for (int i = 0; i < 17; i++) {

    if (names[i] == note) {
      int newduration = duration / SPEE;
      playTone(tones[i], newduration);

    }

  }

}

void setup() {

  Serial.begin(9600);

  pinMode(LDRPin, INPUT);
  pinMode(BuzzerPin, OUTPUT);

}

void loop() {


  LDRValue = analogRead(LDRPin);



    pinMode(BuzzerPin, HIGH);

    for (int i = 0; i < length; i++) {

      if (notes[i] == ' ') {

        delay(beats[i] * tempo); // rest

      } else {

        playNote(notes[i], beats[i] * tempo);

      }

      // pause between notes

      delay(tempo);

    }

  if (LDRValue < 512)
  {
    pinMode(BuzzerPin, LOW);
  }
  delay (1000);
}
