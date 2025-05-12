#include <Arduino.h>

uint8_t const YELLOW_LED_PIN = 4;
uint8_t const RED_LED_PIN = 7;
uint16_t const DELAY_TIME_MS = 1000;

void setup() {
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
}

void loop() {
  for (uint8_t i = 0; i < 3; i++) {
    digitalWrite(YELLOW_LED_PIN, HIGH);
    delay(DELAY_TIME_MS);
    digitalWrite(YELLOW_LED_PIN, LOW);
    delay(DELAY_TIME_MS);
  }

  for (uint8_t i = 0; i < 5; i++) {
    digitalWrite(RED_LED_PIN, HIGH);
    delay(DELAY_TIME_MS);
    digitalWrite(RED_LED_PIN, LOW);
    delay(DELAY_TIME_MS);
  }
}
