#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>

// IMU A at 0x68 (AD0 = GND)
MPU6050 imuA(0x68);
// IMU B at 0x69 (AD0 = 3.3V)
MPU6050 imuB(0x69);

// LED pins
const int ledGreen  = 3;  // Green LED on row 35
const int ledYellow = 5;  // Yellow LED on row 39
const int ledRed    = 6;  // Red LED on row 42

void setup() {
  Wire.begin();
  Serial.begin(9600);
  while (!Serial) { ; }

  Serial.println("L-UME v0.3 - Delta Angle Zone Test (zones 1-3)");

  imuA.initialize();
  imuB.initialize();

  if (imuA.testConnection()) {
    Serial.println("IMU A (0x68) connected.");
  } else {
    Serial.println("IMU A (0x68) connection FAILED.");
  }

  if (imuB.testConnection()) {
    Serial.println("IMU B (0x69) connected.");
  } else {
    Serial.println("IMU B (0x69) connection FAILED.");
  }

  pinMode(ledGreen,  OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledRed,    OUTPUT);

  Serial.println("Format: A, B, delta, zone (1=Green,2=Yellow,3=Red)");
}

void loop() {
  int16_t ax1, ay1, az1;
  int16_t ax2, ay2, az2;

  // --- read accel from both IMUs ---
  imuA.getAcceleration(&ax1, &ay1, &az1);
  imuB.getAcceleration(&ax2, &ay2, &az2);

  // convert to float
  float fax1 = (float)ax1;
  float fay1 = (float)ay1;
  float faz1 = (float)az1;

  float fax2 = (float)ax2;
  float fay2 = (float)ay2;
  float faz2 = (float)az2;

  // --- compute pitch for A ---
  float denom1 = sqrt(fay1 * fay1 + faz1 * faz1);
  if (denom1 < 1) denom1 = 1;
  float pitchA = atan2(fax1, denom1) * 180.0 / PI;

  // --- compute pitch for B ---
  float denom2 = sqrt(fay2 * fay2 + faz2 * faz2);
  if (denom2 < 1) denom2 = 1;
  float pitchB = atan2(fax2, denom2) * 180.0 / PI;

  // --- relative angle ---
  float delta = pitchB - pitchA;
  float absDelta = abs(delta);

  // --- zone logic (1 = Green, 2 = Yellow, 3 = Red) ---
  int zone;
  if (absDelta < 15.0) {
    zone = 1;  // Green (safe)
  } else if (absDelta < 40.0) {
    zone = 2;  // Yellow (caution)
  } else {
    zone = 3;  // Red (over-limit)
  }

  // --- LED output ---
  digitalWrite(ledGreen,  zone == 1 ? HIGH : LOW);
  digitalWrite(ledYellow, zone == 2 ? HIGH : LOW);
  digitalWrite(ledRed,    zone == 3 ? HIGH : LOW);

  // --- Serial output for debugging ---
  Serial.print("A: ");     Serial.print(pitchA, 2);
  Serial.print("  B: ");   Serial.print(pitchB, 2);
  Serial.print("  delta: "); Serial.print(delta, 2);
  Serial.print("  zone: ");  Serial.println(zone);

  delay(200);
}
