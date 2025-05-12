#include <Arduino.h>

int const PHOTORESISTOR_PIN = A0;
int const GREEN_LED_PIN = 7;
int const RED_LED_PIN = 8;

int const LIGHT_THRESHOLD = 500;

void setup() 
{
  Serial.begin(9600);
  
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(PHOTORESISTOR_PIN, INPUT);
}

void loop() 
{
  int lightLevel = analogRead(PHOTORESISTOR_PIN);
  
  Serial.print("Light level: ");
  Serial.println(lightLevel);
  
  if (lightLevel > LIGHT_THRESHOLD) 
  {
    digitalWrite(GREEN_LED_PIN, HIGH);
    digitalWrite(RED_LED_PIN, LOW);
  } 
  else 
  {
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, HIGH);
  }
  
  delay(100);
}
