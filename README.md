# Face Recognition Access Control System Using ESP32-CAM

This repository contains the Arduino code, configuration, and assembly instructions for building a face recognition-based access control system using the ESP32-CAM module. This system is designed to grant or deny access to a restricted area based on facial recognition. It is ideal for applications such as smart door locks, attendance systems, or home security.

---

## Table of Contents
1. [Overview](#overview)
2. [Components Used](#components-used)
3. [System Dimensions](#system-dimensions)
4. [Assembly Instructions](#assembly-instructions)
5. [Arduino Code Explanation](#arduino-code-explanation)
6. [How to Test Without Simulation](#how-to-test-without-simulation)
7. [Contributing](#contributing)
8. [License](#license)

---

## Overview
The face recognition system uses the ESP32-CAM module to capture images and perform facial recognition. When a recognized face is detected, the system activates a relay to unlock a door or solenoid lock. The ESP32-CAM's built-in Wi-Fi allows remote monitoring and control via a web interface.

---

## Components Used
To build this face recognition system, you will need the following components:
- **ESP32-CAM with OV2640 Camera**
- **5V Relay Module**
- **5V Power Adapter**
- **MicroSD Card (Optional)**
- **Jumper Wires**
- **Breadboard (Optional)**
- **12V Solenoid Lock (Optional)**

---

## System Dimensions
For an ideal face recognition system:
- **Height**: 10–15 cm
- **Width**: 10–15 cm
- **Length**: 10–15 cm

These dimensions ensure that the system is compact yet spacious enough to house all components.

---

## Assembly Instructions
Follow these steps to assemble your face recognition system:
1. Prepare the ESP32-CAM and connect it to your computer using an FTDI programmer.
2. Connect the relay module to the ESP32-CAM.
3. Mount the solenoid lock and connect it to the relay module.
4. Power the system using a 5V power adapter.
5. Secure all components inside a protective enclosure.

---

## Arduino Code Explanation
The provided Arduino code captures images using the ESP32-CAM and performs face recognition. If a recognized face is detected, the system activates the relay to unlock the door. The face recognition logic can be implemented using libraries like TensorFlow Lite or OpenCV.

---

## How to Test Without Simulation
1. Upload the code to the ESP32-CAM using an FTDI programmer.
2. Test the camera and Wi-Fi connection using the Serial Monitor.
3. Stand in front of the camera and observe the Serial Monitor for access messages.
4. Verify that the relay and solenoid lock operate correctly.

---

## Contributing
Feel free to fork this repository and contribute improvements or new features. If you have suggestions or find bugs, please open an issue.

---

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

By following this guide, you should be able to build and test your own face recognition access control system using the ESP32-CAM module. Happy tinkering! 🚀
