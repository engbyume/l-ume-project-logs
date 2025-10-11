/*
  v0.3_singleIMU_pitch.ino
  Purpose: Confirm clean MPU6050 angle readings for LED mapping (Hour 1).
  Hardware: Arduino UNO + 1x MPU6050
  Notes: Stable pitch 0–3 deg flat, ±90 deg full range.
*/

#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>

MPU6050 mpu;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  mpu.initialize();
  Serial.println("Testing connection...");
  if (mpu.testConnection()) {
    Serial.println("MPU6050 connected successfully!");
  } else {
    Serial.println("MPU6050 connection failed!");
  }
}

void loop() {
  int16_t ax, ay, az;
  mpu.getAcceleration(&ax, &ay, &az);

  // Convert to floats for math and handle near‑zero cases
  float fax = (float)ax;
  float fay = (float)ay;
  float faz = (float)az;

  // Protect against division by zero
  float denom = sqrt((fay * fay) + (faz * faz));
  if (denom < 1) denom = 1;           // avoid 0

  // Compute pitch (degrees)
  float pitch = atan2(fax, denom) * 180.0 / PI;

  // Only print if pitch is a valid number
  if (!isnan(pitch)) {
    Serial.print("AX: "); Serial.print(ax);
    Serial.print("\tAY: "); Serial.print(ay);
    Serial.print("\tAZ: "); Serial.print(az);
    Serial.print("\tPitch (deg): ");
    Serial.println(pitch);
  } else {
    Serial.println("Pitch invalid (nan) skipped");
  }

  delay(200);
}
