# LUME Prototype — Jeremy Ume

## Overview
**LUME** is a modular motion‑feedback engine that helps athletes and therapists visualize safe movement ranges in real time.  
This repository documents the version‑by‑version evolution of the system — wiring diagrams, firmware, logs, and reflections.

---

## v0.1 — Early Experiments
**Progress**
- Built and debugged button‑controlled vibration and motor tests on the breadboard.  
- Validated button input logic (digital HIGH/LOW), timing, and debounce.  
- Experimented with buzzer and motor feedback patterns to test different feedback modalities.  
- Documented setup steps, errors, and quick fixes before committing to a light‑first design.  

**How to Run**
1. Upload any `.ino` file from `Arduino/v0.1_experiments/` to the Arduino Uno.  
2. Wire components as described in each sketch’s comments (e.g., button → D2, motor → D9).  
3. Open Serial Monitor if the sketch uses serial logging.  
4. Activate button or motion input to view physical output responses.

**Lessons Learned**
- Breadboard debugging *is* real engineering — small wiring errors cost hours.  
- Button orientation and pull‑down/pull‑up resistors are foundational for stable input.  
- Rapid component‑by‑component testing saves time once systems integrate later.  
- Non‑visual feedback (motors/buzzers) taught clarity lessons that led to the LED‑first interface.

---

## v0.2 — Bench LED + Button Demo
**Progress**
- Integrated 3‑LED (green/yellow/red) system with button‑controlled on/off toggling.  
- Implemented non‑blocking timing using `millis()` for consistent, responsive control.  
- Designed the firmware to always start from the green LED zone for repeatable demos.  
- Verified start/stop logic and sequence visuals for filming and data logging.

**How to Run**
1. Upload `button_press_triple_led_sequence.ino` from `Arduino/v0.2_bench_demo/`.  
2. Connect LEDs → pins 3, 5, 6 with 220 Ω resistors; button → pin 2 → GND.  
3. Press button once → LED sequence starts (green → yellow → red).  
4. Press again → sequence stops and resets to green.

**Lessons Learned**
- Transitioning from separate tests to an integrated demo revealed timing issues from blocking `delay()` calls.  
- Using `millis()` unlocked simultaneous input checking and smooth responsiveness.  
- Visual (light‑first) feedback provides instant usability compared to audible or haptic cues.  
- Documenting each build phase in GitHub + Notion creates a living engineering journal — essential for admissions and competitions.

---

## Next Steps
- **v0.3 Portable Strap Prototype:** dual‑IMU rig, battery power, on‑body test sessions.  

---

_Last updated: October 5, 2025_
