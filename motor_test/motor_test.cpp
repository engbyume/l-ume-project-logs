// button_test.ino
// Prints 0 when button is NOT pressed, 1 when pressed (use Serial Monitor)

int buttonPin = 2; // Button connected to pin 2

void setup() {
  Serial.begin(9600);      // Start serial communication at 9600 baud
  pinMode(buttonPin, INPUT);
}

void loop() {
  int buttonState = digitalRead(buttonPin);
  Serial.println(buttonState); // 0 = not pressed, 1 = pressed
  delay(200);
}
