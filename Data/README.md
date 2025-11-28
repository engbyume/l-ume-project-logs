# 📊 L-UME Data Archive

This folder documents and organizes all datasets and CSV logs captured across L-UME versions.

---

## 🧾 v0.3 – Portable Strap Logs

**Title:** L-UME v0.3 Single‑IMU LED Feedback Test  
**Recorded:** October 11 2025  
**Contents:** Angles (°) • Zone (0–2) • Timestamp (ms)  
**Format:** `timestamp_ms, pitch_deg, zone`  
**Sample duration:** ~10 s  (bench demonstration session)  

📂 **File:** [`v03_singleIMU_LEDzones_test01.csv`](https://drive.google.com/file/d/1JcwH6IhPZllYQX5yKX-scLxYUWgrg9ns/view?usp=drive_link)

---

## 🧪 v0.3 – Dual-IMU Bench Logs

**Title:** L‑UME v0.3 Dual-IMU Delta Angle + Zone Test  
**Recorded:** November 20 2025  
**Contents:** Pitch angles A/B (°) • Relative angle Δθ (°) • Zone (1–3) • Timestamp (ms)  
**Format:** `timestamp_ms, pitchA_deg, pitchB_deg, delta_deg, zone`  
**Sample duration:** ~10–20 s (bench demonstration session; button-gated start/stop)

---

📂 **File:** `v03_dualIMU_LEDzones_session01.csv`
## 📈 Upcoming Additions
Future datasets will include dual‑IMU strap tests with relative angle (Δθ) and progression metrics for v0.4 analytics. 
Each entry will include:
- recording date and duration   
- sensor configuration (IMU addresses, mount notes)   
- CSV schema and time resolution  

---

**Related Folders:** [`/Arduino`](../Arduino)  • [`/media`](../media)

_Last updated: October 12 2025_
