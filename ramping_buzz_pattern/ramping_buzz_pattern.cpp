// Ramping Buzz Pattern: Short, medium, long buzz when button is pressed

int motorPin = 9;         // Pin number for the motor
int buttonPin = 2;        // Pin number for the button

void setup() {
  pinMode(motorPin, OUTPUT);   // Set pin 9 as OUTPUT (controls the motor)
  pinMode(buttonPin, INPUT);   // Set pin 2 as INPUT (reads the button)
}

void loop() {
  if (digitalRead(buttonPin) == HIGH) {   // If the button is pressed
    // Short buzz
    digitalWrite(motorPin, HIGH);         // Motor ON
    delay(100);                           // Wait 0.1 second
    digitalWrite(motorPin, LOW);          // Motor OFF
    delay(500);                           // Wait 0.1 second

    // Medium buzz
    digitalWrite(motorPin, HIGH);         // Motor ON
    delay(300);                           // Wait 0.3 second
    digitalWrite(motorPin, LOW);          // Motor OFF
    delay(500);                           // Wait 0.1 second

    // Long buzz
    digitalWrite(motorPin, HIGH);         // Motor ON
    delay(600);                           // Wait 0.6 second
    digitalWrite(motorPin, LOW);          // Motor OFF
    delay(500);                           // Wait 0.3 second

    // Wait for button release to avoid repeated triggers
    while (digitalRead(buttonPin) == HIGH) { delay(10); }
  }
}
