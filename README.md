# PID-Temperature-Control-System
PID-based temperature-controlled cooling system using ESP32 and LM35 

# PID-Based Temperature Controlled Cooling System

## Overview

This project implements a closed-loop temperature control system using **ESP32**, **LM35 temperature sensor**, **L298N motor driver**, and a **DC cooling fan** with PWM-based speed regulation. The system uses a **PID (Proportional–Integral–Derivative) controller** to dynamically adjust fan speed based on real-time temperature feedback and maintain a target setpoint of **25°C**.

The project demonstrates intelligent actuator response and embedded control system design for thermal management applications. A miniature DC fan is used as a proof-of-concept to show PID-controlled response rather than full-scale cooling.

---

## Features

* Real-time temperature monitoring using LM35 sensor
* PID-based closed-loop control using Embedded C
* PWM fan speed control using ESP32
* Adjustable setpoint temperature (default: 25°C)
* Deadband implementation to reduce rapid ON/OFF switching
* Integral anti-windup protection for stable control
* Serial Monitor output for debugging and performance analysis
* Scalable design for future TEC/Peltier-based cooling systems

---

## Hardware Used

* ESP32 Development Board
* LM35 Temperature Sensor
* L298N Motor Driver Module
* DC Miniature Cooling Fan
* Jumper Wires
* Breadboard
* External Power Supply (if required)

---

## Working Principle

1. LM35 continuously senses the surrounding temperature
2. ESP32 reads analog sensor values and converts them to temperature
3. PID controller calculates the error:

Error = Setpoint - Current Temperature

4. Based on PID output, PWM duty cycle is adjusted
5. Fan speed increases when temperature rises above setpoint
6. Fan slows down or turns OFF when temperature falls near the target temperature

This creates a stable closed-loop control system.

---

## PID Control Logic

### PID Equation

Output = Kp × Error + Ki × Integral + Kd × Derivative

### Tuned Parameters

* Kp = 10
* Ki = 0.1
* Kd = 5

These values were tuned to provide smooth fan response and reduce instability.

---

## Project Outcomes

* Successfully demonstrated dynamic fan speed control based on temperature variation
* Reduced unnecessary fan switching using deadband logic
* Improved response stability using anti-windup protection
* Built a strong proof-of-concept for embedded thermal regulation systems

---

## Future Improvements

* Replace miniature fan with TEC/Peltier module for real cooling
* Add OLED/LCD display for live monitoring
* Enable Wi-Fi dashboard using IoT integration
* Implement remote monitoring using MQTT/Blynk/Arduino Cloud

---

## Skills Demonstrated

Embedded C, ESP32, PID Control, PWM, ADC, Sensor Interfacing, Motor Driver Integration, Real-Time Monitoring, Debugging, Embedded System Design

---

## Author

**Hariharan Ashok**
MSc Embedded Systems & IoT
Embedded Systems | Firmware Development | STM32 | ESP32 | RTOS

LinkedIn: linkedin.com/in/hariharan-ashok

---

