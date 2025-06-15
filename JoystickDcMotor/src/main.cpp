#include <Arduino.h>

// Joystick pin assignments
const int x_pin = A0;
const int y_pin = A1;
const int switch_pin = 2;

// Motor control pin assignments
const int motorEnablePin = 5;
const int motorInput1Pin = 4;
const int motorInput2Pin = 3;

void setup()
{
  pinMode(x_pin, INPUT);             // Set x-axis pin as input
  pinMode(y_pin, INPUT);             // Set y-axis pin as input
  pinMode(switch_pin, INPUT_PULLUP); // Set switch pin as input with pull-up

  // Set motor control pins as outputs
  pinMode(motorEnablePin, OUTPUT);
  pinMode(motorInput1Pin, OUTPUT);
  pinMode(motorInput2Pin, OUTPUT);
}

void loop()
{
  // int x_value = analogRead(x_pin);            // Read x-axis
  int y_value = analogRead(y_pin); // Read y-axis
  // int switch_state = digitalRead(switch_pin); // Read switch (pressed = LOW)

  int motorSpeed;
  int motorDir1;
  int motorDir2;
  if (y_value > 500 && y_value < 524)
  {
    motorSpeed = 0; // Stop the motor if y_value is in the dead zone
    motorDir1 = LOW;
    motorDir2 = LOW;
  }
  else
  {
    motorSpeed = map(abs(y_value - 512), 0, 512, 0, 255); // Map speed from 0 to 255
    motorDir1 = y_value >= 524 ? HIGH : LOW;
    motorDir2 = y_value <= 500 ? HIGH : LOW;
  }
  digitalWrite(motorInput1Pin, motorDir1);
  digitalWrite(motorInput2Pin, motorDir2);

  analogWrite(motorEnablePin, motorSpeed);
}
