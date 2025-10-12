#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>

MPU6050 mpu;

// LED and button pins
const int ledGreen = 3;
const int ledYellow = 5;
const int ledRed = 6;
const int buttonPin = 2;

bool isRunning = false;       // start/stop state
bool lastButton = HIGH;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  // ----- sensor setup -----
  mpu.initialize();
  if (mpu.testConnection()) Serial.println("MPU6050 connected.");
  else Serial.println("MPU6050 connection failed!");

  // ----- IO setup -----
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);   // internal pull‑up resistor
}

void loop() {
  // ---------- BUTTON HANDLER ----------
  bool reading = digitalRead(buttonPin);
  if (reading == LOW && lastButton == HIGH) {
    isRunning = !isRunning;
    delay(200);   // debounce
    if (!isRunning) {
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledYellow, LOW);
      digitalWrite(ledRed, LOW);
      Serial.println("System paused.");
    } else {
      Serial.println("System running...");
    }
  }
  lastButton = reading;

  // ---------- SENSOR + LED CONTROL ----------
  if (isRunning) {
    int16_t ax, ay, az;
    mpu.getAcceleration(&ax, &ay, &az);

    float fax = (float)ax;
    float fay = (float)ay;
    float faz = (float)az;

    // avoid divide‑by‑zero
    float denom = sqrt((fay * fay) + (faz * faz));
    if (denom < 1) denom = 1;

    float pitch = atan2(fax, denom) * 180.0 / PI;

    Serial.print("Pitch (deg): ");
    Serial.println(pitch);

    // --- zone logic ---
    if (abs(pitch) < 15) {                 // safe
      digitalWrite(ledGreen, HIGH);
      digitalWrite(ledYellow, LOW);
      digitalWrite(ledRed, LOW);
    }
    else if (abs(pitch) < 40) {            // caution
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledYellow, HIGH);
      digitalWrite(ledRed, LOW);
    }
    else {                                // beyond limit
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledYellow, LOW);
      digitalWrite(ledRed, HIGH);
    }
  }
  delay(100); // update rate
}
