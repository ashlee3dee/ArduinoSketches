const int delay_ms = 1000;

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    digitalWrite(13, LOW);
    delay(delay_ms/2);
    digitalWrite(13, HIGH);
    delay(delay_ms/2);
}
