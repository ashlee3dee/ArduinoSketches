#define CC 176
#define POT1 0
#define MSDELAY 10

int val = 0; //Our initial pot values. We need one for the first value and a second to test if there has been a change made. This needs to be done for all 3 pots.
int lastVal = 0;

const int buttonPin[5] = {2, 3, 4, 5, 6};
bool currentButtonState[5] = {LOW, LOW, LOW, LOW, LOW};
bool lastButtonState[5] = {LOW, LOW, LOW, LOW, LOW};

void setup()
{
  Serial.begin(115200);       // Set the speed of the midi port to the same as we will be using in the Hairless Midi software
}

void loop()
{
  HandleButtons();
  //  val = analogRead(POT1) / 8; // Divide by 8 to get range of 0-127 for midi
  //  if (val != lastVal) // If the value does not = the last value the following command is made. This is because the pot has been turned. Otherwise the pot remains the same and no midi message is output.
  //  {
  //    MIDImessage(CC, 1, val); // 176 = CC command (channel 1 control change), 1 = Which Control, val = value read from Potentionmeter 1
  //  }
  //  lastVal = val;

  delay(MSDELAY);
}

void MIDImessage(byte command, byte data1, byte data2) //pass values out through standard Midi Command
{
  Serial.write(command);
  Serial.write(data1);
  Serial.write(data2);
}



void HandleButtons() {
  for (int i = 0; i < 5; i++)
  {
    currentButtonState[i] = digitalRead(buttonPin[i]); //save current pin state
    if (currentButtonState[i] != lastButtonState[i]) //check if pin state has changed from last state
    {
      if (currentButtonState[i] == HIGH)  //is the button pressed?
      {
        MIDImessage(10010001, 01010000, 01010000);
      }
      if (currentButtonState[i] == LOW)  //is the button not pressed?
      {
        MIDImessage(10000001, 01010000, 01010000);
      }
    }
    lastButtonState[i] = currentButtonState[i];
  }
}

