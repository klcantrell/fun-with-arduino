#include <Arduino.h>

// Pin definitions
const int incrementButton = 7;
const int decrementButton = 8;
const int ledPin = 11;
const int buzzerPin = 4;

// LED brightness (0-255)
int brightness = 0;
const int brightnessStep = 26;

void setup() {
  // Configure pins
  pinMode(incrementButton, INPUT);
  pinMode(decrementButton, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  // Initialize LED to off
  analogWrite(ledPin, brightness);
}

void loop() {
  // Read button states (buttons are active LOW with pullup resistors)
  bool incrementPressed = digitalRead(incrementButton);
  bool decrementPressed = digitalRead(decrementButton);
  
  // Adjust brightness based on button presses
  if (incrementPressed) {
    brightness += brightnessStep;
    // Ensure we don't exceed maximum
    if (brightness > 255) {
      brightness = 255;
    }
  }
  
  if (decrementPressed) {
    brightness -= brightnessStep;
    // Ensure we don't go below minimum
    if (brightness < 0) {
      brightness = 0;
    }
  }
  
  // Check if we're at min or max brightness and activate buzzer if needed
  if (brightness == 0 || brightness == 255) {
    // Buzz the buzzer
    tone(buzzerPin, 1000, 150);  // 1000Hz tone for 150ms
  } else {
    // Stop the buzzer if not at min or max brightness
    noTone(buzzerPin);
  }
  
  // Update the LED brightness
  analogWrite(ledPin, brightness);
  
  // Small delay to prevent too rapid changes and handle button debounce
  delay(100);
}
