/*
  Melody

  Plays a melody

  circuit:
   8-ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Tone

*/
#include "pitches.h"

// notes in the melody:
int randomnotes = 256;
int melody[] = {
  NOTE_A3, NOTE_B3, NOTE_C3, NOTE_D3, NOTE_E3, NOTE_F3, NOTE_G3
};
void setup() {
  randomSeed(analogRead(0));
}

void loop() {
  // no need to repeat the melody.
  int note = random(0, sizeof(melody));
  int noteDuration = 1000 / 16;
  tone(10, melody[note], noteDuration);
  delay(noteDuration / 2);
  noTone(10);
  delay(noteDuration / 2);
}
