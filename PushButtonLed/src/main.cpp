#include <Arduino.h>

int const BUTTON_PIN = 7;
int const LED_PIN = 8;

int pendingChange = LOW;
int ledState = LOW;
int lastButtonState = LOW;
unsigned int lastDebounceTime = 0;
unsigned int debounceDelay = 100;

void setup()
{
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState != lastButtonState)
  {
    lastDebounceTime = millis();
  }
  else if (millis() - lastDebounceTime > debounceDelay)
  {
    if (buttonState == HIGH)
    {
      pendingChange = HIGH;
    }

    if (buttonState == LOW && pendingChange == HIGH)
    {
      ledState = !ledState;
      digitalWrite(LED_PIN, ledState);
      pendingChange = LOW;
    }
  }

  lastButtonState = buttonState;

  delay(10); // Small delay to prevent bouncing
}
