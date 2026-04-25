// button_motor_control.ino
// Motor vibrates ONLY while button is pressed

int motorPin = 9;    // Motor connected to pin 9
int buttonPin = 2;   // Button connected to pin 2

void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  int buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    digitalWrite(motorPin, HIGH); // Motor ON
  } else {
    digitalWrite(motorPin, LOW);  // Motor OFF
  }
}
