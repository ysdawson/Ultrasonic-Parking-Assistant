# 🚗 Ultrasonic Distance Alert System

A simple Arduino-based project that uses an **HC-SR04 ultrasonic sensor**, **LEDs**, and a **buzzer** to indicate object proximity. Ideal for parking sensors or proximity warning systems.

---

## 🔧 Features

- Measures distance using the HC-SR04 ultrasonic sensor
- Provides visual (LED) and audio (buzzer) alerts
- Three alert zones:
  - ✅ **Safe** (> 50 cm): Green LED ON
  - ⚠️ **Caution** (20–50 cm): Green + Red LED ON, Slow beeps
  - ❌ **Danger** (≤ 20 cm): Red LED ON, Fast beeps
- Serial monitor displays live distance (in cm)

---

## 🛠️ Components Required

| Component        |  Quantity |
|------------------|-----------|
| Arduino UNO      | 1         |
| HC-SR04 Sensor   | 1         |
| Red LED          | 1         |
| Green LED        | 1         |
| Buzzer           | 1         |
| Jumper Wires     | As needed |
| Breadboard       | As needed |

---

## ⚙️ Pin Connections

| Component      | Arduino Pin |
|----------------|-------------|
| HC-SR04 Trig   | 9           |
| HC-SR04 Echo   | 10          |
| Red LED        | 6           |
| Green LED      | 5           |
| Buzzer         | 7           |

---

## 📥 Installation

1. Install the [NewPing library](https://github.com/PaulStoffregen/NewPing)
   - In Arduino IDE: `Sketch > Include Library > Manage Libraries` → Search “NewPing” → Install

2. Upload the code below to your Arduino board.
