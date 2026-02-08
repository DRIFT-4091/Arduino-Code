# Arduino-Code
Code to explore teleop &amp; autonomous control of the Arduino drivetrain

## Project Structure

- **Drivetrain.h** - Header file with class definition and method declarations
- **Drivetrain.cpp** - Implementation file with all drivetrain control logic
- **Arduino-Code.ino** - Main Arduino sketch file (setup and loop functions)

## Features

### Motor Control
- Independent left and right motor control
- Speed and direction control (PWM)
- Emergency stop functionality

### Autonomous Mode
- `moveForward(speed)` - Move forward at specified speed
- `moveBackward(speed)` - Move backward at specified speed
- `turnLeft(speed)` - Turn left in place
- `turnRight(speed)` - Turn right in place

### Teleop Mode
- Serial input control (w/s/a/d keys)
- `teleopControl(forward, turn)` - Arcade-style control
- Mode switching (autonomous/teleop)

## Hardware Setup

Default pin configuration (can be modified in Drivetrain.cpp constructor):
- Left Motor Pin 1: Digital Pin 2
- Left Motor Pin 2: Digital Pin 3
- Left Motor Enable (PWM): Pin 5
- Right Motor Pin 1: Digital Pin 4
- Right Motor Pin 2: Digital Pin 7
- Right Motor Enable (PWM): Pin 6

## Getting Started

1. Open **Arduino-Code.ino** in Arduino IDE
2. Verify the pin assignments match your hardware
3. Upload to your Arduino board
4. Open Serial Monitor (9600 baud)
5. Use keyboard commands to control:
   - 'w' - Move forward
   - 's' - Move backward
   - 'a' - Turn left
   - 'd' - Turn right
   - 'x' - Stop
   - 'm' - Toggle mode (Autonomous/Teleop)

## Customization

### Modify Pin Assignments
Edit the constructor in **Drivetrain.cpp**:
```cpp
Drivetrain::Drivetrain() {
    leftMotorPin1 = 2;    // Change these values
    leftMotorPin2 = 3;
    // ... etc
}
```

### Add Custom Autonomous Behaviors
Edit the `autonomousControl()` function in **Arduino-Code.ino**

### Add Custom Teleop Controls
Edit the `teleopControl()` function in **Arduino-Code.ino**

## Ready to Edit

All files are fully functional and ready for customization. Simply modify the TODO sections or add your own logic!
