// feedback_patterns.ino
// Motor does a double buzz pattern

int motorPin = 9;

void setup() {
  pinMode(motorPin, OUTPUT);
}

void loop() {
  // First buzz
  digitalWrite(motorPin, HIGH);
  delay(100);
  digitalWrite(motorPin, LOW);
  delay(100);

  // Second buzz
  digitalWrite(motorPin, HIGH);
  delay(100);
  digitalWrite(motorPin, LOW);
  delay(700); // Wait before repeating
}
