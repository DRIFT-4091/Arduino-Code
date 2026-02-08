// Pin definitions for motor control
const int leftMotorPin1 = 2;
const int leftMotorPin2 = 3;
const int leftMotorEnable = 5;
const int rightMotorPin1 = 4;
const int rightMotorPin2 = 7;
const int rightMotorEnable = 6;

// Mode selection
enum Mode {
    AUTONOMOUS,
    TELEOP
};

Mode currentMode = TELEOP;

void setup() {
    // Initialize serial communication
    Serial.begin(9600);
    
    // Set pin modes
    pinMode(leftMotorPin1, OUTPUT);
    pinMode(leftMotorPin2, OUTPUT);
    pinMode(leftMotorEnable, OUTPUT);
    pinMode(rightMotorPin1, OUTPUT);
    pinMode(rightMotorPin2, OUTPUT);
    pinMode(rightMotorEnable, OUTPUT);
    
    // Initialize motors to stopped state
    stopMotors();
    
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

// Motor control functions
void setLeftMotor(int speed) {
    if (speed >= 0) {
        digitalWrite(leftMotorPin1, HIGH);
        digitalWrite(leftMotorPin2, LOW);
    } else {
        digitalWrite(leftMotorPin1, LOW);
        digitalWrite(leftMotorPin2, HIGH);
    }
    analogWrite(leftMotorEnable, constrain(abs(speed), 0, 255));
}

void setRightMotor(int speed) {
    if (speed >= 0) {
        digitalWrite(rightMotorPin1, HIGH);
        digitalWrite(rightMotorPin2, LOW);
    } else {
        digitalWrite(rightMotorPin1, LOW);
        digitalWrite(rightMotorPin2, HIGH);
    }
    analogWrite(rightMotorEnable, constrain(abs(speed), 0, 255));
}

void drive(int leftSpeed, int rightSpeed) {
    setLeftMotor(leftSpeed);
    setRightMotor(rightSpeed);
}

void stopMotors() {
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, LOW);
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, LOW);
    analogWrite(leftMotorEnable, 0);
    analogWrite(rightMotorEnable, 0);
}

void moveForward(int speed) {
    drive(speed, speed);
}

void moveBackward(int speed) {
    drive(-speed, -speed);
}

void turnLeft(int speed) {
    drive(-speed, speed);
}

void turnRight(int speed) {
    drive(speed, -speed);
}

void autonomousControl() {
    // Example autonomous sequence
    // TODO: Implement your autonomous control logic here
    
    moveForward(150);
    delay(2000);
    
    turnRight(100);
    delay(1000);
    
    moveForward(150);
    delay(2000);
    
    stopMotors();
    delay(1000);
}

void teleopControl() {
    // Example teleop control using serial input
    // TODO: Implement your teleop control logic here
    
    if (Serial.available() > 0) {
        char command = Serial.read();
        
        switch (command) {
            case 'w':  // Forward
                moveForward(200);
                break;
            case 's':  // Backward
                moveBackward(200);
                break;
            case 'a':  // Turn left
                turnLeft(150);
                break;
            case 'd':  // Turn right
                turnRight(150);
                break;
            case 'x':  // Stop
                stopMotors();
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
