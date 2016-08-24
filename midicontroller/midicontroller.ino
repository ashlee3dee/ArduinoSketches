#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

#define LEDPIN 13

const int buttons[] = {2, 3, 4, 5, 6};
const int notes[] = {50, 51, 52, 53, 54};
void setup() {
  // put your setup code here, to run once:
  MIDI.begin(1);
  Serial.begin(115200);

  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);

  pinMode(LEDPIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 4; i++)
  {
    int buttonState = digitalRead(buttons[i]);
    int currentNote = notes[i];
    if (buttonState == HIGH)
    {
      digitalWrite(LEDPIN, HIGH);
      //MIDI.sendNoteOn(currentNote, 100, i);
    } else {
      digitalWrite(LEDPIN, LOW);
      //MIDI.sendNoteOff(currentNote, 100, i);
    }
  }
}
