// ----- LUME v0.2: LED toggle sequence with button control -----
// Always starts from GREEN when turned on

int ledGreen = 3;
int ledYellow = 5;
int ledRed = 6;
int buttonPin = 2;

bool isRunning = false;
bool lastButtonState = HIGH;

unsigned long lastBlink = 0;
int currentLED = 0;
unsigned long interval = 500;

void setup() {
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // ---------- BUTTON TOGGLE ----------
  bool reading = digitalRead(buttonPin);

  if (reading == LOW && lastButtonState == HIGH) {
    isRunning = !isRunning;   // flip start/stop
    delay(200);               // debounce

    if (isRunning) {
      // when turning ON, reset to start from GREEN
      currentLED = 0;
      lastBlink = millis();
    } else {
      // when stopping, turn everything OFF
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledYellow, LOW);
      digitalWrite(ledRed, LOW);
    }
  }
  lastButtonState = reading;

  // ---------- LED SEQUENCE ----------
  if (isRunning) {
    unsigned long now = millis();
    if (now - lastBlink >= interval) {
      lastBlink = now;

      // turn all LEDs off
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledYellow, LOW);
      digitalWrite(ledRed, LOW);

      // light current LED
      if (currentLED == 0) digitalWrite(ledGreen, HIGH);
      else if (currentLED == 1) digitalWrite(ledYellow, HIGH);
      else if (currentLED == 2) digitalWrite(ledRed, HIGH);

      // advance index
      currentLED++;
      if (currentLED > 2) currentLED = 0;
    }
  }
}