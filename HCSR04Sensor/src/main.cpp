#include <Arduino.h>

int const TRIGGER_PIN = 12;
int const ECHO_PIN = 11;

void setup() {
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  int const duration = pulseIn(ECHO_PIN, HIGH);
  Serial.println(("Duration: %d microseconds\n", duration));

  int const distanceInMeters = duration * 0.000343; // Speed of sound is 343 meters per second
  int const distanceInInches = duration * 0.0135; // Convert to inches
  Serial.print("Distance: ");
  Serial.print(distanceInMeters);
  Serial.print(" m, ");
  Serial.print(distanceInInches);
  Serial.println(" in");

  delay(1000);
}

// 150 microseconds to go 1.25 inches
// 550 microseconds to go 4 inches
// slope is ~300 meters per second or roughly the speed of sound
