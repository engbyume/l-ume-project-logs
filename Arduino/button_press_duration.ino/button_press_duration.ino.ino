// button_press_duration.ino
// Short press = single buzz, long press (>2s) = double buzz

int motorPin = 9;
int buttonPin = 2;
unsigned long buttonPressTime = 0;
bool buttonWasPressed = false;

void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH && !buttonWasPressed) {
    buttonPressTime = millis();
    buttonWasPressed = true;
  }

  if (buttonState == LOW && buttonWasPressed) {
    unsigned long pressDuration = millis() - buttonPressTime;
    if (pressDuration > 2000) {
      // Long press: double buzz
      for (int i = 0; i < 2; i++) {
        digitalWrite(motorPin, HIGH);
        delay(100);
        digitalWrite(motorPin, LOW);
        delay(100);
      }
    } else {
      // Short press: single buzz
      digitalWrite(motorPin, HIGH);
      delay(200);
      digitalWrite(motorPin, LOW);
    }
    buttonWasPressed = false;
  }
}