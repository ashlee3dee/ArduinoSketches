const int motorPin = 10;
const int buttonPin = 2;
const int ms_delay = 1000;

int buttonState = 0;

void setup() {
  // put your setup code here, to run once:
  //set pin controlling motor to OUT
  pinMode(motorPin, OUTPUT);
  //set pin controlling LED to IN
  pinMode(buttonPin, INPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  //update button state
  buttonState = digitalRead(buttonPin);

  //if the button is ON
  if(buttonState == HIGH)
  {
    analogWrite(motorPin, 255); 
  }else{
    analogWrite(motorPin, 0);
  }
}
