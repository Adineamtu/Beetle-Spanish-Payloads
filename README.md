
# 🇪🇸 Beetle Spanish Payloads (ATMEGA32U4)

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Hardware: Arduino Beetle](https://img.shields.io/badge/Hardware-Beetle%20(ATmega32U4)-blue)](https://www.arduino.cc/)

A collection of optimized payloads for the **Arduino Beetle (BadUSB)**, specifically designed to work with **Spanish (ES) keyboard layouts**.

---

## 🚀 Why this repository?
Most BadUSB scripts assume a US keyboard layout. When used on a Spanish system, special characters like `:`, `/`, `\`, `-`, or `.` get scrambled. This repository includes a custom library to fix this mapping, ensuring your scripts run perfectly on Spanish-configured machines.

## 📂 Project Structure

| Category | Payload Name | Description |
| :--- | :--- | :--- |
| 🔑 **Security** | [Wifi-Stealer](./Payloads/Wifi-Stealer/) | Extracts Wi-Fi passwords and sends them to a Discord Webhook. |
| 📦 **System** | [Standard Installer](./Payloads/Auto-Installer/Standard-Installer.ino) | Installs software via Winget with a visible console. |
| 👤 **Stealth** | [Stealth Installer](./Payloads/Auto-Installer/Stealth-Installer.ino) | Silent installation using background PowerShell. |
| 🎭 **Fun** | [Fake System Alert](./Payloads/Pranks/Fake-System-Alert.ino) | Displays a series of professional-looking VBScript pop-up alerts. |

## 🛠️ Getting Started

### 1. Requirements
* **Hardware**: Arduino Beetle (ATmega32U4) or any Pro Micro.
* **Library**: You **must** include the library found in the `/Library` folder in your project.

### 2. Installation
1. Download `KeyboardES_ES_Beetle.h` from the [Library](./Library/) folder.
2. Place it in your Arduino sketch folder.
3. Use `#include "KeyboardES_ES_Beetle.h"` at the beginning of your code.
4. Replace variables like `YOUR_DISCORD_WEBHOOK_URL` with your actual data.

## ⚠️ Disclaimer
This project is for **educational and ethical auditing purposes only**. The author is not responsible for any misuse or damage caused by these scripts. Always obtain permission before testing on systems you do not own.

---
*Created with ❤️ for the BadUSB community.*
