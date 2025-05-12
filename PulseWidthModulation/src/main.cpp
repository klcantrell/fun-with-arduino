#include <Arduino.h>

const uint8_t RED_PIN = 11;
const uint8_t RED_LED_BRIGHTNESS = 10; // PWM value (0-255)

void setup() {
    pinMode(RED_PIN, OUTPUT);
}

void loop() {
    analogWrite(RED_PIN, RED_LED_BRIGHTNESS);
}
