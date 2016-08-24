#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

void setup() {
  // put your setup code here, to run once:
  MIDI.begin(1);
  Serial.begin(115200);
  pinMode(13, OUTPUT);
}

#define lenMs 50
#define LED 13
const int noteRange[] = {0, 50};
int currentNote = noteRange[0];
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED, HIGH);
  MIDI.sendNoteOn(currentNote, 100, 1);
  delay(lenMs);
  MIDI.sendNoteOff(currentNote, 0, 1);
  digitalWrite(LED, LOW);
  delay(lenMs);
  if(currentNote < noteRange[1])
  {
    currentNote++;
  }else{
    currentNote = noteRange[0];
  }
}

