#include <Arduino.h>

const int TILT_SWITCH_PIN = 4;
const int GREEN_LED_PIN = 2;
const int RED_LED_PIN = 3;

void setup() {
  pinMode(TILT_SWITCH_PIN, INPUT_PULLUP);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
}

void loop() {
  int tiltState = digitalRead(TILT_SWITCH_PIN);

  if (tiltState == HIGH) {
    digitalWrite(RED_LED_PIN, HIGH);
    digitalWrite(GREEN_LED_PIN, LOW);
  } else {
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, HIGH);
  }
}
