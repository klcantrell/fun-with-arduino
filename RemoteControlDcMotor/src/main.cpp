#include <Arduino.h>
#include <IRremote.h>

// Pin definitions for circuit wiring
const int IR_RECEIVER_PIN = 9;    // Connect IR receiver data pin here
const int MOTOR_ENABLE_PIN = 5;   // Connect to motor driver enable pin (ENA)
const int MOTOR_INPUT1_PIN = 4;   // Connect to motor driver input 1 (IN1)
const int MOTOR_INPUT2_PIN = 3;   // Connect to motor driver input 2 (IN2)

// Motor control variables
int motorSpeed = 0;               // Current speed (0-255)
bool motorDirection = true;       // true = forward, false = reverse
const int SPEED_STEP = 25;        // Speed increment/decrement
const int MIN_SPEED = 100;
const int MAX_SPEED = 255;
const int JUMPSTART_THRESHOLD = 150;

String command;

// Function declarations
void speedUp();
void slowDown();
void setForward();
void setReverse();
void updateMotorDirection();

void setup() {
  Serial.begin(9600);
  
  // Initialize IR receiver
  IrReceiver.begin(IR_RECEIVER_PIN, ENABLE_LED_FEEDBACK);
  
  // Set motor control pins as outputs
  pinMode(MOTOR_ENABLE_PIN, OUTPUT);
  pinMode(MOTOR_INPUT1_PIN, OUTPUT);
  pinMode(MOTOR_INPUT2_PIN, OUTPUT);
  
  // Initialize motor (stopped)
  analogWrite(MOTOR_ENABLE_PIN, 0);
  updateMotorDirection();
  
  Serial.println("IR Remote DC Motor Control Ready");
  Serial.println("Commands: volume_up=speed up, volume_down=slow down");
  Serial.println("          next=forward, previous=reverse");
}

void loop() {
  while (IrReceiver.decode() == 0);
  delay(200);
  
  // Decode IR command
  switch (IrReceiver.decodedIRData.decodedRawData) {
    case 0xB946FF00: // volume_up
      command = "volume_up";
      speedUp();
      break;
    case 0xEA15FF00: // volume_down
      command = "volume_down";
      slowDown();
      break;
    case 0xBC43FF00: // next
      command = "next";
      setForward();
      break;
    case 0xBB44FF00: // previous
      command = "previous";
      setReverse();
      break;
    default:
      command = "unknown";
      break;
  }
  
  if (command != "unknown") {
    Serial.print("Command: ");
    Serial.print(command);
    Serial.print(" | Speed: ");
    Serial.print(motorSpeed);
    Serial.print(" | Direction: ");
    Serial.println(motorDirection ? "Forward" : "Reverse");
  }
  
  IrReceiver.resume();
}

void speedUp() {
  int previousSpeed = motorSpeed;
  motorSpeed = min(motorSpeed + SPEED_STEP, MAX_SPEED);
  
  // Enforce minimum speed
  if (motorSpeed > 0 && motorSpeed < MIN_SPEED) {
    motorSpeed = MIN_SPEED;
  }
  
  // Jumpstart motor if going from 0 to speed 100-150
  if (previousSpeed == 0 && motorSpeed >= MIN_SPEED && motorSpeed <= JUMPSTART_THRESHOLD) {
    analogWrite(MOTOR_ENABLE_PIN, 255);
    delay(25);
  }
  
  analogWrite(MOTOR_ENABLE_PIN, motorSpeed);
}

void slowDown() {
  if (motorSpeed <= MIN_SPEED) {
    motorSpeed = 0;
  } else {
    motorSpeed = max(motorSpeed - SPEED_STEP, MIN_SPEED);
  }

  analogWrite(MOTOR_ENABLE_PIN, motorSpeed);
}

void setForward() {
  motorDirection = true;
  updateMotorDirection();
}

void setReverse() {
  motorDirection = false;
  updateMotorDirection();
}

void updateMotorDirection() {
  if (motorDirection) {
    // Forward direction
    digitalWrite(MOTOR_INPUT1_PIN, HIGH);
    digitalWrite(MOTOR_INPUT2_PIN, LOW);
  } else {
    // Reverse direction
    digitalWrite(MOTOR_INPUT1_PIN, LOW);
    digitalWrite(MOTOR_INPUT2_PIN, HIGH);
  }
}
