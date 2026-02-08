# Arduino-Code
TETRIX PRIZM robotics controller code for teleop & autonomous control of the drivetrain.

**Note:** For specific to-dos and deadlines, please reference the **"Arduino Community Events"** project in the Projects section.

## Features

This repository contains two main Arduino sketches for the TETRIX PRIZM controller:

### Autonomous.ino
- Pre-programmed autonomous movement sequences
- Motor control using PRIZM library
- Timed movement patterns:
  - Forward movement (3 seconds)
  - Backward movement (3 seconds)
  - Right turn (3 seconds)
  - Left turn (3 seconds)

### TeleopControl.ino
- PS4 controller integration via TETRIX TeleOp module
- Real-time joystick control
- Left joystick (LY) controls motor 2
- Right joystick (RY) controls motor 1
- Tank-style drive control

## Hardware Setup

### Required Components
- TETRIX PRIZM Robotics Controller
- TETRIX motors (configured as Motor 1 and Motor 2)
- For TeleopControl: TETRIX TeleOp module with Bluetooth dongle
- For TeleopControl: Sony PS4 gaming controller (fully charged)

### Motor Configuration
- Motor 1: Right side motor (controlled by right joystick Y-axis in teleop)
- Motor 2: Left side motor (controlled by left joystick Y-axis in teleop)
- Both motors set to inverted mode for intuitive forward movement

## Getting Started

### For Autonomous Mode
1. Open **Autonomous.ino** in Arduino IDE
2. Ensure PRIZM and TELEOP libraries are installed
3. Upload to your TETRIX PRIZM controller
4. Press the green start button on the PRIZM controller
5. The robot will execute the pre-programmed movement sequence

### For TeleopControl Mode
1. Open **TeleopControl.ino** in Arduino IDE
2. Ensure PRIZM and TELEOP libraries are installed
3. Upload to your TETRIX PRIZM controller
4. Pair your PS4 controller with the TeleOp module:
   - Insert Bluetooth dongle into TeleOp module
   - Power up the TeleOp module (green LED should blink)
   - Press and hold SHARE + POWER on PS4 controller until LED blinks rapidly
   - Press MODE button on TeleOp module to pair
   - Wait for solid green LED on both devices
5. Press the green start button on the PRIZM controller
6. Control the robot using the PS4 joysticks

## Customization

### Modify Autonomous Movement Patterns
Edit the motor powers and delay times in the `setup()` function of **Autonomous.ino** to create custom movement sequences.

### Adjust Motor Inversion
Change the `prizm.setMotorInvert()` parameters in either file if your motors rotate in the wrong direction.

### Customize TeleopControl Mapping
Modify the joystick-to-motor mapping in the `loop()` function of **TeleopControl.ino** to change control behavior.

## Library Requirements

Both sketches require the following Arduino libraries:
- **PRIZM.h** - TETRIX PRIZM Controller Library
- **TELEOP.h** - TETRIX TeleOp Module Library

These libraries must be installed in your Arduino IDE before uploading the code.
