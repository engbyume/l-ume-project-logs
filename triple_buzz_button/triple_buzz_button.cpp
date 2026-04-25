// Triple Buzz Pattern: Motor buzzes 3 times when button is pressed

int motorPin = 9;         // Declare a variable to store the pin number for the motor (pin 9)
int buttonPin = 2;        // Declare a variable to store the pin number for the button (pin 2)

void setup() {
  pinMode(motorPin, OUTPUT);   // Set pin 9 as an OUTPUT (so Arduino can send voltage to the motor)
  pinMode(buttonPin, INPUT);   // Set pin 2 as an INPUT (so Arduino can read the button state)
}

void loop() {
  if (digitalRead(buttonPin) == HIGH) {   // Check if the button is pressed (HIGH = 5V = pressed)
    for (int i = 0; i < 3; i++) {         // Repeat the following block 3 times (i = 0, 1, 2)
      digitalWrite(motorPin, HIGH);       // Turn the motor ON (send 5V to pin 9)
      delay(300);                         // Wait for 100 milliseconds (0.1 second)
      digitalWrite(motorPin, LOW);        // Turn the motor OFF (send 0V to pin 9)
      delay(300);                         // Wait for 100 milliseconds before the next buzz
    }
    // Wait for the button to be released before allowing another triple buzz
    while (digitalRead(buttonPin) == HIGH) { delay(10); }
  }
}