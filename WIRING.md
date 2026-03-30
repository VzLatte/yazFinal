# Full System Wiring Guide

## Components Required
- 1x ESP32-CAM module
- 1x ESP32 Development Board
- 1x PAM8403 Audio Amplifier
- 1x 4-ohm 3W Speaker
- 1x 5V Power Supply (capable of providing at least 2 Amps, as the CAM and amplifier have high peak draws)
- Jumper wires

---

## 1. Power Distribution
The ESP32-CAM and the Amplifier draw significant power. It is highly recommended to power them using an external 5V power supply rather than relying solely on the PC's USB connection if you experience stability issues.

| Power Source | ESP32-CAM | ESP32 Dev Board | PAM8403 Amp |
| :--- | :--- | :--- | :--- |
| **5V (Positive)** | `5V` / `VCC` Pin | `5V` / `VIN` Pin | `5V` / `VCC` Pin |
| **GND (Negative)** | `GND` Pin | `GND` Pin | `GND` Pin |

*Crucial Step: You MUST ensure all GND pins are connected together so that the logic signals share a common reference voltage.*

---

## 2. UART Communication Link
This bridges the Text output from the ESP32-CAM to the ESP32 Speech board.

| ESP32-CAM Output | ESP32 Dev Board Input | Notes |
| :--- | :--- | :--- |
| **GPIO 14** (U1TXD) | **GPIO 16** (RXD2) | Data line sending the text strings from the Camera to the Talkie board. |
| **GND** | **GND** | Need shared ground (Handled in Step 1). |

---

## 3. Audio Output System
This wiring leverages the native DAC pin on the ESP32 Dev Board to drive the raw analog Talkie signal to your amplifier.

| Source Component | Target Pin (PAM8403) | Speaker Terminals |
| :--- | :--- | :--- |
| **ESP32 Dev GPIO 25** (DAC1) | **L** or **R** Audio Input | |
| **ESP32 Dev GND** | **GND** Audio Target | |
| **PAM8403 Output L+** | | Connect to Speaker **Positive (+)** |
| **PAM8403 Output L-** | | Connect to Speaker **Negative (-)** |

*Note: The PAM8403 is a stereo amplifier. You only need to use one side (e.g., the Left channel `L`) since Talkie only produces mono sound.*

---

## Verification Checklist Before Powering On
- [ ] Are all Grounds (GND) across the 3 boards connected together?
- [ ] Is the ESP32-CAM connected to 5V, NOT 3.3V? (Taking consecutive images will quickly crash on 3.3V pins).
- [ ] Is the ESP32-CAM TX pin (GPIO 14) explicitly wired to the Dev Board RX pin (GPIO 16)?
- [ ] Is the Dev Board DAC pin (GPIO 25) securely routed to the audio input track of the PAM8403?
