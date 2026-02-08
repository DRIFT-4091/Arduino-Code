#include "Drivetrain.h"

// Constructor
Drivetrain::Drivetrain() {
    // Default pin assignments (can be modified)
    leftMotorPin1 = 2;
    leftMotorPin2 = 3;
    leftMotorEnable = 5;
    rightMotorPin1 = 4;
    rightMotorPin2 = 7;
    rightMotorEnable = 6;
}

// Initialize the drivetrain
void Drivetrain::begin() {
    // Set pin modes
    pinMode(leftMotorPin1, OUTPUT);
    pinMode(leftMotorPin2, OUTPUT);
    pinMode(leftMotorEnable, OUTPUT);
    pinMode(rightMotorPin1, OUTPUT);
    pinMode(rightMotorPin2, OUTPUT);
    pinMode(rightMotorEnable, OUTPUT);
    
    // Initialize motors to stopped state
    stop();
}

// Set left motor speed and direction
void Drivetrain::setLeftMotor(int speed) {
    setMotorDirection(true, speed >= 0);
    setMotorSpeed(true, abs(speed));
}

// Set right motor speed and direction
void Drivetrain::setRightMotor(int speed) {
    setMotorDirection(false, speed >= 0);
    setMotorSpeed(false, abs(speed));
}

// Drive with independent motor speeds
void Drivetrain::drive(int leftSpeed, int rightSpeed) {
    setLeftMotor(leftSpeed);
    setRightMotor(rightSpeed);
}

// Stop all motors
void Drivetrain::stop() {
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, LOW);
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, LOW);
    analogWrite(leftMotorEnable, 0);
    analogWrite(rightMotorEnable, 0);
}

// Move forward at specified speed
void Drivetrain::moveForward(int speed) {
    drive(speed, speed);
}

// Move backward at specified speed
void Drivetrain::moveBackward(int speed) {
    drive(-speed, -speed);
}

// Turn left at specified speed
void Drivetrain::turnLeft(int speed) {
    drive(-speed, speed);
}

// Turn right at specified speed
void Drivetrain::turnRight(int speed) {
    drive(speed, -speed);
}

// Teleop control using forward and turn inputs
void Drivetrain::teleopControl(int forward, int turn) {
    int leftSpeed = forward + turn;
    int rightSpeed = forward - turn;
    
    // Constrain to valid PWM range
    leftSpeed = constrain(leftSpeed, -255, 255);
    rightSpeed = constrain(rightSpeed, -255, 255);
    
    drive(leftSpeed, rightSpeed);
}

// Helper: Set motor direction
void Drivetrain::setMotorDirection(bool isLeft, bool forward) {
    int pin1 = isLeft ? leftMotorPin1 : rightMotorPin1;
    int pin2 = isLeft ? leftMotorPin2 : rightMotorPin2;
    
    if (forward) {
        digitalWrite(pin1, HIGH);
        digitalWrite(pin2, LOW);
    } else {
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, HIGH);
    }
}

// Helper: Set motor speed (PWM)
void Drivetrain::setMotorSpeed(bool isLeft, int speed) {
    int enablePin = isLeft ? leftMotorEnable : rightMotorEnable;
    analogWrite(enablePin, constrain(speed, 0, 255));
}
