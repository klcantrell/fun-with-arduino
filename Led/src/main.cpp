#include <Arduino.h>

const int LED_PIN = 9;
int BRIGHTNESS = 0;
int FADE_AMOUNT = 5;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  const char* favorite_color = "blue";
  analogWrite(LED_PIN, BRIGHTNESS);
  BRIGHTNESS = BRIGHTNESS + FADE_AMOUNT;

  if (BRIGHTNESS >= 255) {
    Serial.println(favorite_color);
    FADE_AMOUNT = -FADE_AMOUNT;
  } else if (BRIGHTNESS <= 0) {
    FADE_AMOUNT = -FADE_AMOUNT;
  }
  delay(30);
}
