#include <Arduino.h>
#include <Servo.h>

Servo myservo;

const int servoPin = 8; // Pin for the servo
const int photoresistorPin = A0; // Pin for the photoresistor

void setup() {
  myservo.attach(servoPin);
  pinMode(photoresistorPin, INPUT); // Set pin A0 as input for the photoresistor
}

void loop() {
  int lightLevel = analogRead(photoresistorPin); // Read the light level from the photoresistor
  int servoPosition = map(lightLevel, 200, 1023, 0, 180); // Map light level to servo position
  servoPosition = constrain(servoPosition, 0, 180); // Ensure the servo position is within bounds
  myservo.write(servoPosition); // Set the servo position
  delay(100); // Add a 100 ms delay
}
