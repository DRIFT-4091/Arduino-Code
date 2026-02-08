#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include <Arduino.h>

class Drivetrain {
public:
    // Constructor
    Drivetrain();
    
    // Initialization
    void begin();
    
    // Motor control methods
    void setLeftMotor(int speed);
    void setRightMotor(int speed);
    void drive(int leftSpeed, int rightSpeed);
    void stop();
    
    // Autonomous control
    void moveForward(int speed);
    void moveBackward(int speed);
    void turnLeft(int speed);
    void turnRight(int speed);
    
    // Teleop control
    void teleopControl(int forward, int turn);
    
private:
    // Pin definitions
    int leftMotorPin1;
    int leftMotorPin2;
    int rightMotorPin1;
    int rightMotorPin2;
    int leftMotorEnable;
    int rightMotorEnable;
    
    // Helper methods
    void setMotorDirection(bool isLeft, bool forward);
    void setMotorSpeed(bool isLeft, int speed);
};

#endif // DRIVETRAIN_H
