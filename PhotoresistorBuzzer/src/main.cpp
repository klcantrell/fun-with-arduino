#include <Arduino.h>

int const PHOTORESISTOR_PIN = A0;
const int BUZZER_PIN = 8;

void setup() 
{
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(PHOTORESISTOR_PIN, INPUT);
}

void loop() 
{
  int lightLevel = analogRead(PHOTORESISTOR_PIN);
  int buzzerWaveDelayTime = map(lightLevel, 0, 1023, 1000, 2000);
  
  // Generate square wave
  digitalWrite(BUZZER_PIN, HIGH);
  delayMicroseconds(buzzerWaveDelayTime);
  digitalWrite(BUZZER_PIN, LOW);
  delayMicroseconds(buzzerWaveDelayTime);
}
