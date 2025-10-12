# LUME Project Logs
Firmware · Data · Media  
Comprehensive record of the LUME motion‑feedback system builds (v0.1 → v1.0)

# LUME Prototype — Jeremy Ume

## Overview
# LUME — Light‑based User Motion Engine

**LUME** is a modular motion‑feedback engine that lets athletes and therapists visualize safe movement ranges in real time.  
This repository documents the system’s evolution — from early experiments to integrated demos — including firmware versions and reflections at each milestone.

---

## v0.1 — Early Experiments
**Progress**
- Built multiple breadboard prototypes to explore digital I/O, motors, buzzers, and buttons.  
- Verified logic for button input, timing, and debounce.  
- Tested feedback through vibration and tone patterns to understand user experience.  
- Captured notes and serial logs to guide the shift toward a light‑first feedback model.

**How to Run**
- Open any sketch in `Arduino/v0.1_experiments` and upload through the Arduino IDE.  
- Follow in‑code comments for wiring references.  
- Observe the reaction (motor vibration, buzzer pattern, or serial output).  

**Lessons Learned**
- Hardware debugging trains patience and precision; even a single miswired lead matters.  
- Understanding pull‑ups and pull‑downs was foundational for building stable input logic.  
- Early vibration and tone feedback proved confusing for quick interpretation → inspired move to LEDs.  
- Systematically logging every test saved hours when integrating later versions.

---

## v0.2 — Bench LED + Button Demo
**Progress**
- Combined button input and LED outputs into a unified bench‑top prototype.  
- Added non‑blocking timing with `millis()` for smooth, responsive control.  
- Implemented clean toggle logic so the sequence always restarts from the green zone.  
- Filmed the first admission‑grade demo showing clear start/stop visual feedback.

**How to Run**
- Upload any `.ino` file from `Arduino/v0.2_bench_demo` via Arduino IDE.  
- Watch LED sequence begin with green and cycle through yellow → red on button press.  
- Press the button again to stop and reset.  

**Lessons Learned**
- Integrating code pieces exposed how `delay()` blocks input — moving to `millis()` solved it elegantly.  
- Visual feedback (light → color → pattern) communicates motion safety immediately.  
- A single, consistent button sequence improves usability and filming clarity.  
- Documenting firmware by version shows measurable progress and readiness for competitions.

---

## Next Steps
- **v0.3 Portable Strap Prototype:** dual IMUs, elastic mount, NeoPixel feedback.  
- **v0.4 Analytics:** data logging, progression rules, CSV plots.  
- **v1.0 Wearable:** final field‑ready enclosure with calibration and battery power.  

---

_Last updated October 10th 2025_
