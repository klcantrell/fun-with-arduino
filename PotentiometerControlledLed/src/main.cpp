#include <Arduino.h>

uint8_t const POTENTIOMETER_PIN = A1;
uint8_t const LED_PIN = 6;

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  pinMode(POTENTIOMETER_PIN, INPUT);
}

void loop()
{
  uint16_t potentiometer_value = analogRead(POTENTIOMETER_PIN);
  float brightness = map(potentiometer_value, 0, 1023, 0, 255);
  analogWrite(LED_PIN, brightness);
  delay(10);
}
