#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>

// IMU A at 0x68 (AD0 = GND)
MPU6050 imuA(0x68);
// IMU B at 0x69 (AD0 = 3.3V)
MPU6050 imuB(0x69);

// LED pins
const int ledGreen  = 3;  // Green LED
const int ledYellow = 5;  // Yellow LED
const int ledRed    = 6;  // Red LED

// Button pin
const int buttonPin = 2;

// State
bool isRunning = false;
bool lastButtonState = HIGH;

unsigned long lastLogTime    = 0;
const unsigned long logInterval = 100; // 0.1 s

void setup() {
  Wire.begin();
  Serial.begin(9600);
  while (!Serial) { ; }

  Serial.println("L-UME v0.3 - Button + CSV Logger + Zone LEDs (zones 1-3)");
  Serial.println("# timestamp_ms,pitchA_deg,pitchB_deg,delta_deg,zone");

  imuA.initialize();
  imuB.initialize();

  if (imuA.testConnection()) {
    Serial.println("# IMU A (0x68) connected.");
  } else {
    Serial.println("# IMU A (0x68) connection FAILED.");
  }

  if (imuB.testConnection()) {
    Serial.println("# IMU B (0x69) connected.");
  } else {
    Serial.println("# IMU B (0x69) connection FAILED.");
  }

  pinMode(ledGreen,  OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledRed,    OUTPUT);

  pinMode(buttonPin, INPUT_PULLUP); // D2 -> button -> GND

  // Start with LEDs off
  digitalWrite(ledGreen,  LOW);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledRed,    LOW);
}

void loop() {
  // --- Button handling ---
  bool reading = digitalRead(buttonPin);

  // detect press: HIGH -> LOW
  if (reading == LOW && lastButtonState == HIGH) {
    isRunning = !isRunning;   // flip state
    delay(200);               // crude debounce

    if (!isRunning) {
      // stopping: turn LEDs off
      digitalWrite(ledGreen,  LOW);
      digitalWrite(ledYellow, LOW);
      digitalWrite(ledRed,    LOW);
      Serial.println("# stopped");
    } else {
      Serial.println("# running");
      lastLogTime = millis();
    }
  }
  lastButtonState = reading;

  // --- only measure + log when running ---
  if (isRunning) {
    int16_t ax1, ay1, az1;
    int16_t ax2, ay2, az2;

    imuA.getAcceleration(&ax1, &ay1, &az1);
    imuB.getAcceleration(&ax2, &ay2, &az2);

    float fax1 = (float)ax1;
    float fay1 = (float)ay1;
    float faz1 = (float)az1;

    float fax2 = (float)ax2;
    float fay2 = (float)ay2;
    float faz2 = (float)az2;

    // Pitch A
    float denom1 = sqrt(fay1 * fay1 + faz1 * faz1);
    if (denom1 < 1) denom1 = 1;
    float pitchA = atan2(fax1, denom1) * 180.0 / PI;

    // Pitch B
    float denom2 = sqrt(fay2 * fay2 + faz2 * faz2);
    if (denom2 < 1) denom2 = 1;
    float pitchB = atan2(fax2, denom2) * 180.0 / PI;

    // Relative angle
    float delta = pitchB - pitchA;
    float absDelta = abs(delta);

    // Zone logic (1 = Green, 2 = Yellow, 3 = Red)
    int zone;
    if (absDelta < 15.0) {
      zone = 1;    // Green
    } else if (absDelta < 40.0) {
      zone = 2;    // Yellow
    } else {
      zone = 3;    // Red
    }

    // LED output
    digitalWrite(ledGreen,  zone == 1 ? HIGH : LOW);
    digitalWrite(ledYellow, zone == 2 ? HIGH : LOW);
    digitalWrite(ledRed,    zone == 3 ? HIGH : LOW);

    // CSV logging
    unsigned long now = millis();
    if (now - lastLogTime >= logInterval) {
      lastLogTime = now;

      Serial.print(now);
      Serial.print(",");
      Serial.print(pitchA, 2);
      Serial.print(",");
      Serial.print(pitchB, 2);
      Serial.print(",");
      Serial.print(delta, 2);
      Serial.print(",");
      Serial.println(zone);
    }
  }

  // small delay so loop is not too tight when paused
  delay(5);
}