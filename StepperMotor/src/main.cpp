#include <Arduino.h>
#include <Stepper.h>

static const int stepsPerRevolution = 2048;
static const int buttonPin = 7;

bool clockWise = true;
int lastButtonState = HIGH;

// Initialize the stepper library on pins 8 through 11
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  myStepper.setSpeed(10); // 10 RPM, adjust as needed
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == LOW && lastButtonState == HIGH) {
    clockWise = !clockWise;
  }

  myStepper.step(clockWise ? 1 : -1);

  lastButtonState = buttonState;
}
