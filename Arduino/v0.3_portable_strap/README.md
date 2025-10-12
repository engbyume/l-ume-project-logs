# L-UME v0.3 — Portable Strap Prototype
---
**Purpose:**  
Transition LUME from bench prototype to a portable, on‑body system capable of recording real motion data.  
This version introduced dual IMUs, a wearable form factor, and CSV logging for competitive submissions (MIT THINK and Regeneron).

**Key sketches planned to live here:**
- `v03_singleIMU_pitch.ino` — verified clean sensor readings and pitch calculation from one MPU6050.
- `v03_singleIMU_LED_zones.ino` — mapped sensor angles to 3 LED zones (G/Y/R) with button start/stop control.
- `v03_dualIMU_LEDzones.ino` — used delta angle (Δθ = pitch₂ – pitch₁) for relative motion feedback on strap.
- `v03_logger.ino` — output structured CSV lines timestamp, pitch₁, pitch₂, Δθ, zone for analytics.

**Related Directories:**  
[`/data`](../../data)  • [`/media`](../../media) 

_Last updated: October 12 2025_
