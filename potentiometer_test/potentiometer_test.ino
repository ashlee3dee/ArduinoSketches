//vars
int analogInPin = A0 ;
int analogOutPin = 3;
int potInput;
//functions

void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  potInput = analogRead(analogInPin);
  int ledControlVar = map(potInput, 100, 1023, 0, 255);
  Serial.println(ledControlVar);
  //Serial.println(ledControlVar);
  analogWrite(analogOutPin, ledControlVar);
}
