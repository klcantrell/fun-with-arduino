#include <Arduino.h>

const int POT_PIN = A1;
const int BUZZER_PIN = 8;

void setup() 
{
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(POT_PIN, INPUT);
}

void loop() 
{
  int pot_value = analogRead(POT_PIN);
  int delay_time = map(pot_value, 0, 1023, 40, 10000);
  
  // Generate square wave
  digitalWrite(BUZZER_PIN, HIGH);
  delayMicroseconds(delay_time);
  digitalWrite(BUZZER_PIN, LOW);
  delayMicroseconds(delay_time);
}
