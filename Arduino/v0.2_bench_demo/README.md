# LUME v0.2 — Bench LED + Button Demo
---

**Purpose:**  
Combine button input and triple‑LED output into one integrated bench‑top system.  
This version delivered reliable start/stop control, introduced non‑blocking timing with `millis()`, and proved the clarity of light‑first feedback.

**Key sketches planned to live here:**
- `button_press_triple_led_sequence.ino` — final bench demo: press once to begin the LED cycle (Green → Yellow → Red); press again to stop and reset to Green; uses non‑blocking timing and debounce logic.
- `upd_button_test.ino` — confirmed INPUT_PULLUP logic and button stability before integration.
  
**Related Directories:**  
[`/data`](../../data)  • [`/media`](../../media) 

_Last updated: October 10 2025_
