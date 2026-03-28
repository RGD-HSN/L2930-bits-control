# L2930-bits-control

# Motor Control using L293D and 74HC595 Shift Register

## Overview
This project implements a custom motor control system using the **L293D motor driver** combined with a **74HC595 shift register**.  
Instead of using standard motor driver libraries, the control logic was **manually implemented by manipulating bits**, allowing more efficient and flexible control of multiple motors.

The system controls **4 DC motors** using PWM for speed and bitwise operations for direction.

---

## ⚙️ Features
- Control of 4 DC motors using a single shift register  
- Direction control using **bit manipulation**  
- Speed control using **PWM signals**  
- Reduced number of Arduino pins using 74HC595  
- Custom implementation (no external motor driver library)  

---

## 🧠 How It Works
- The **74HC595 shift register** is used to control motor directions by setting specific bits.  
- Each motor is assigned **two bits**:
  - One for forward  
  - One for backward  
- The direction is controlled by updating a shared byte (`motorState`) and sending it to the shift register using `shiftOut()`.

Speed is controlled independently using PWM pins:
- `analogWrite()` sets motor speed  
- Bitwise operations define direction  

---

## 🔩 Hardware
- Arduino Uno  
- L293D Motor Driver  
- 4 DC Motors  
- Power Supply  

---

## Pin Configuration
### Shift Register
- `CLOCK_PIN` → Clock  
- `LATCH_PIN` → Latch  
- `SERIAL_PIN` → Data  

### PWM Pins
- Motor 1 → Pin 3  
- Motor 2 → Pin 5  
- Motor 3 → Pin 6  
- Motor 4 → Pin 10  

---

## 💻 Key Concept
The main idea is controlling motors using **bitwise operations**:

<img width="557" height="387" alt="Screenshot 2026-03-28 at 3 15 35 AM" src="https://github.com/user-attachments/assets/d2e39467-189b-40e4-b12a-0149c9130811" />

```cpp
motorState = (motorState & MASK) | VALUE;





