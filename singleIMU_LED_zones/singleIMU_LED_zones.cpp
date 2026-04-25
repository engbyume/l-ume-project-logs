#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>

MPU6050 mpu;

// --- LED + button pins ---
const int ledGreen = 3;
const int ledYellow = 5;
const int ledRed = 6;
const int buttonPin = 2;

// --- system state ---
bool isRunning = false;
bool lastButton = HIGH;
unsigned long lastPrint = 0;
const unsigned long printInterval = 100;   // 10 Hz logging

void setup() {
  Serial.begin(9600);
  Wire.begin();

  mpu.initialize();
  if (mpu.testConnection()) {
    Serial.println("# LUME v0.3 IMU log start");
    Serial.println("# timestamp_ms, pitch_deg, zone");
  } else {
    Serial.println("# ERROR: MPU6050 not found");
  }

  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // --- handle button ---
  bool reading = digitalRead(buttonPin);
  if (reading == LOW && lastButton == HIGH) {
    isRunning = !isRunning;
    delay(200);
    if (!isRunning) {
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledYellow, LOW);
      digitalWrite(ledRed, LOW);
      Serial.println("# stopped");
    } else {
      Serial.println("# running");
    }
  }
  lastButton = reading;

  // --- read sensor + display LEDs ---
  int16_t ax, ay, az;
  mpu.getAcceleration(&ax, &ay, &az);

  float fax = (float)ax;
  float fay = (float)ay;
  float faz = (float)az;
  float denom = sqrt((fay * fay) + (faz * faz));
  if (denom < 1) denom = 1;
  float pitch = atan2(fax, denom) * 180.0 / PI;

  // Determine zone
  int zone = 0;
  if (abs(pitch) < 15) zone = 0;       // Green
  else if (abs(pitch) < 40) zone = 1;  // Yellow
  else zone = 2;                       // Red

  if (isRunning) {
    // LEDs live update
    digitalWrite(ledGreen, zone == 0);
    digitalWrite(ledYellow, zone == 1);
    digitalWrite(ledRed, zone == 2);

    // Print csv lines at 10 Hz
    unsigned long now = millis();
    if (now - lastPrint >= printInterval) {
      lastPrint = now;
      Serial.print(now);
      Serial.print(", ");
      Serial.print(pitch, 2);
      Serial.print(", ");
      Serial.println(zone);
    }
  }
}