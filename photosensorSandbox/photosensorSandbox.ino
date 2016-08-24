
const int TICK_DELAY = 10;
const int PIZO = 12;
const int PHOTOCELL = A0;
int photocellReading;
int lastReading;
int currentTone;
void setup() {
  // put your setup code here, to run once:
  pinMode(PIZO, OUTPUT);
  pinMode(PHOTOCELL, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  photocellReading = analogRead(PHOTOCELL);
  Serial.println( (photocellReading + lastReading) / 2);
  currentTone = map(photocellReading, 0, 1023, 1, 10000);
  lastReading = photocellReading;
  tone(PIZO, currentTone, TICK_DELAY);
  delay(TICK_DELAY);

}
