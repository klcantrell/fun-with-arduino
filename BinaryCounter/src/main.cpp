#include <Arduino.h>
#include <stdint.h>

uint8_t const LED_1 = 11;
uint8_t const LED_2 = 10;
uint8_t const LED_3 = 9;
uint8_t const LED_4 = 8;

uint8_t count = 1; // 1 - 15

void setup()
{
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
}

void loop()
{
  if (count > 15)
  {
    count = 1;
  }

  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, LOW);
  digitalWrite(LED_3, LOW);
  digitalWrite(LED_4, LOW);
  delay(1000);

  digitalWrite(LED_1, (count & 0b0001) ? HIGH : LOW);
  digitalWrite(LED_2, (count & 0b0010) ? HIGH : LOW);
  digitalWrite(LED_3, (count & 0b0100) ? HIGH : LOW);
  digitalWrite(LED_4, (count & 0b1000) ? HIGH : LOW);
  delay(1000);

  count++;
}
