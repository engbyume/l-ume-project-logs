# LUME Prototype — Jeremy Ume

## Overview
LUME is a modular motion feedback engine. This repo documents my prototyping journey, including code, logs, and media.

## Day 1-2 Progress
- Built and debugged button-controlled vibration motor circuit on breadboard
- Mastered breadboard wiring, digital input/output, and feedback patterns
- Documented all steps, issues, and solutions

## How to Run
- Upload `button_motor_control.ino` to Arduino Uno
- Connect button to pin 2, motor to pin 9 (see `/diagrams` for wiring)
- Press button to activate motor

## Next Steps
- Integrate MPU6050 motion sensor (pre-soldered module arriving soon)
- Trigger feedback based on motion events

## Lessons Learned
- Breadboard debugging is real engineering!
- Button orientation and pull-down resistors are critical
