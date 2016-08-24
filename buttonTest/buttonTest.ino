//setup midi environment
#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();

#define LEDPIN 13

//references to each pin number
const int INPUTPINS[] = {2, 3, 4, 5, 6};

//references to the current STATUS of each pin
int PINSTATES[5];
int lastPinState;
//BUILTIN FUNCTIONS
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  setupPins();
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 5; i++) {
    handleButton(i);
  }
}
//UTILITY FUNCTIONS
void handleButton(int bnum)
{
  int currentPinState = digitalRead(INPUTPINS[bnum]);
  if (currentPinState != PINSTATES[bnum]) {
    if (currentPinState == HIGH)
    {
      MIDI.sendNoteOn(40 + (bnum * 3), 100, 1);
    }
    if (currentPinState == LOW) {
      MIDI.sendNoteOff(40 + (bnum * 3), 0, 1);
    }
  }
  PINSTATES[bnum] = currentPinState;
}


void setupPins()
{
  //iterate through the pins
  for (int i = 0; i < 5; i++)
  {
    //set each pin to INPUT
    PINSTATES[i] = digitalRead(i);
    pinMode(i, INPUT);
  }

  pinMode(LEDPIN, OUTPUT);

}
