#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>

// IMU A at 0x68 (AD0 = GND)
MPU6050 imuA(0x68);
// IMU B at 0x69 (AD0 = 3.3V)
MPU6050 imuB(0x69);

void setup() {
  Wire.begin();
  Serial.begin(9600);
  while (!Serial) { ; }  // wait for Serial on Nano

  Serial.println("L-UME v0.3 - Dual IMU Accel Test");

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

  Serial.println("Format: A: ax,ay,az  |  B: ax,ay,az");
}

void loop() {
  int16_t ax1, ay1, az1;
  int16_t ax2, ay2, az2;

  // Read accelerometer from both sensors
  imuA.getAcceleration(&ax1, &ay1, &az1);
  imuB.getAcceleration(&ax2, &ay2, &az2);

  Serial.print("A: ");
  Serial.print(ax1); Serial.print(", ");
  Serial.print(ay1); Serial.print(", ");
  Serial.print(az1);

  Serial.print("  |  B: ");
  Serial.print(ax2); Serial.print(", ");
  Serial.print(ay2); Serial.print(", ");
  Serial.println(az2);

  delay(200);  // ~5 lines per second
}