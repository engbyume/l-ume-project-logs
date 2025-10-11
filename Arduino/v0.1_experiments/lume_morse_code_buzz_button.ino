// Morse Code "LUME": Motor buzzes Morse for LUME when button is pressed

int motorPin = 9;         // Pin number for the motor
int buttonPin = 2;        // Pin number for the button

void setup() {
  pinMode(motorPin, OUTPUT);   // Set pin 9 as OUTPUT (controls the motor)
  pinMode(buttonPin, INPUT);   // Set pin 2 as INPUT (reads the button)
}

void loop() {
  if (digitalRead(buttonPin) == HIGH) {   // If the button is pressed
    // L: .-..
    dot(); dash(); dot(); dot(); delay(300);
    // U: ..-
    dot(); dot(); dash(); delay(300);
    // M: --
    dash(); dash(); delay(300);
    // E: .
    dot(); delay(500);

    // Wait for button release to avoid repeated triggers
    while (digitalRead(buttonPin) == HIGH) { delay(10); }
  }
}

// Helper function for a Morse "dot" (short buzz)
void dot() {
  digitalWrite(motorPin, HIGH); delay(100);   // Motor ON for 0.1s
  digitalWrite(motorPin, LOW);  delay(100);   // Motor OFF for 0.1s
}

// Helper function for a Morse "dash" (long buzz)
void dash() {
  digitalWrite(motorPin, HIGH); delay(300);   // Motor ON for 0.3s
  digitalWrite(motorPin, LOW);  delay(100);   // Motor OFF for 0.1s
}
