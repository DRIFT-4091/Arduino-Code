#include "Drivetrain.h"

// Create drivetrain object
Drivetrain drivetrain;

// Mode selection
enum Mode {
    AUTONOMOUS,
    TELEOP
};

Mode currentMode = TELEOP;

void setup() {
    // Initialize serial communication
    Serial.begin(9600);
    
    // Initialize drivetrain
    drivetrain.begin();
    
    Serial.println("Arduino Drivetrain Initialized");
    Serial.println("Mode: TELEOP");
}

void loop() {
    if (currentMode == AUTONOMOUS) {
        // Autonomous mode example
        autonomousControl();
    } else {
        // Teleop mode example
        teleopControl();
    }
}

void autonomousControl() {
    // Example autonomous sequence
    // TODO: Implement your autonomous control logic here
    
    drivetrain.moveForward(150);
    delay(2000);
    
    drivetrain.turnRight(100);
    delay(1000);
    
    drivetrain.moveForward(150);
    delay(2000);
    
    drivetrain.stop();
    delay(1000);
}

void teleopControl() {
    // Example teleop control using serial input
    // TODO: Implement your teleop control logic here
    
    if (Serial.available() > 0) {
        char command = Serial.read();
        
        switch (command) {
            case 'w':  // Forward
                drivetrain.moveForward(200);
                break;
            case 's':  // Backward
                drivetrain.moveBackward(200);
                break;
            case 'a':  // Turn left
                drivetrain.turnLeft(150);
                break;
            case 'd':  // Turn right
                drivetrain.turnRight(150);
                break;
            case 'x':  // Stop
                drivetrain.stop();
                break;
            case 'm':  // Toggle mode
                currentMode = (currentMode == TELEOP) ? AUTONOMOUS : TELEOP;
                Serial.print("Mode changed to: ");
                Serial.println(currentMode == TELEOP ? "TELEOP" : "AUTONOMOUS");
                break;
            default:
                break;
        }
    }
}
