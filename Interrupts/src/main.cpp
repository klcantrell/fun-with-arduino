#include <Arduino.h>
#include <TimerOne.h>

void toggleYellowLed();

boolean yellowLedOn = false;

const int RED_LED_PIN = 9;
const int YELLOW_LED_PIN = 10;

void setup()
{
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  Timer1.initialize(500000); // Initialize Timer1 to trigger every second
  Timer1.attachInterrupt(toggleYellowLed);
}

void loop()
{
  digitalWrite(RED_LED_PIN, HIGH);
  delay(1000);
  digitalWrite(RED_LED_PIN, LOW);
  delay(1000);
}

void toggleYellowLed()
{
  yellowLedOn = !yellowLedOn;
  digitalWrite(YELLOW_LED_PIN, yellowLedOn ? HIGH : LOW);
}
