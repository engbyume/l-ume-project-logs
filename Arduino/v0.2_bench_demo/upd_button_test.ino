/*
  Quick Button Test
  Confirms button wiring & internal pull-up logic
  Expected: "Pressed" prints when button is held down
*/

const int buttonPin = 2;   // your button connected to D2

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);  // uses internal resistor
  Serial.println("Button test ready (press to see change)");
}

void loop() {
  int reading = digitalRead(buttonPin);

  if (reading == LOW) {
    Serial.println("Pressed");
  } else {
    Serial.println("Released");
  }

  delay(200);  // small delay so prints are readable
}
