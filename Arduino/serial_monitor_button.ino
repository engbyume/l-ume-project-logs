// Serial Monitor Button Test
// Pin 2: Button (one side to 5V, other side to pin 2 + 10kΩ resistor to GND)

int buttonPin = 2; // Button connected to digital pin 2

void setup() {
  Serial.begin(9600);      // Start serial communication at 9600 baud
  pinMode(buttonPin, INPUT); // Set pin 2 as input
}

void loop() {
  int buttonState = digitalRead(buttonPin); // Read the button state (0 = not pressed, 1 = pressed)
  Serial.println(buttonState);              // Print the state to Serial Monitor
  delay(200);                              // Wait 200ms for readability
}