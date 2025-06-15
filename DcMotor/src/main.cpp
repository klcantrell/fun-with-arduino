#include <Arduino.h>

// Motor control pin assignments
const int motorEnablePin = 5;
const int motorInput1Pin = 4;
const int motorInput2Pin = 3;

// Global variables for speed and direction
int motorSpeed = 150; // Speed range: 0 (off) to 255 (full speed)
int motorDir1 = LOW;
int motorDir2 = HIGH;

void setup() {
  // Set motor control pins as outputs
  pinMode(motorEnablePin, OUTPUT);
  pinMode(motorInput1Pin, OUTPUT);
  pinMode(motorInput2Pin, OUTPUT);

  // Set initial direction
  digitalWrite(motorInput1Pin, motorDir1);
  digitalWrite(motorInput2Pin, motorDir2);

  // Jumpstart motor at full speed
  analogWrite(motorEnablePin, 255);
  delay(25);

  // Set speed to global variable
  analogWrite(motorEnablePin, motorSpeed);
}

void loop() {
}
