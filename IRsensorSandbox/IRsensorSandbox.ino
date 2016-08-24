#define ANALOGIN01 A0
#define DIGITALOUT01 10
#define msDelay 100
int analogSignal = 0;
int maxInput = 0;
int minInput = 1024;
int ledControl = 0;
//min and max inputs from testing:
//795     891
void setup() {
  // put your setup code here, to run once:
  pinMode(DIGITALOUT01, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogSignal = constrain(analogRead(ANALOGIN01), 810, 850);
  Serial.println(analogSignal);
  ledControl = map(analogSignal, 810, 850, 255, 0);
  analogWrite(DIGITALOUT01, ledControl);
  //delay(msDelay);
}
