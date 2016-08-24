const int POWERPIN = 6;
const int CONTROLPIN = 7;


void setup() {
  // put your setup code here, to run once:
  pinMode(POWERPIN, OUTPUT);
  pinMode(CONTROLPIN, OUTPUT);
  analogWrite(POWERPIN, 255);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(CONTROLPIN, HIGH);
  delay(500);
  digitalWrite(CONTROLPIN, LOW);
  delay(500);
}
