#include <Arduino.h>

int const LATCH_PIN = 11;
int const CLOCK_PIN = 9;
int const DATA_PIN = 12;

void setup()
{
  // Initialize the pins
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
}

byte LEDS = 0xFA;

// flipping LEDs example
void loop()
{
  // Shift out the LED states
  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, LEDS);
  digitalWrite(LATCH_PIN, HIGH);
  delay(1000);

  LEDS = ~LEDS;
}

// byte LEDS = 0xFE;

// // circular shift left through the LEDs example
// void loop()
// {
//   // Shift out the LED states
//   digitalWrite(LATCH_PIN, LOW);
//   shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, LEDS);
//   digitalWrite(LATCH_PIN, HIGH);
//   delay(1000);

//   LEDS =  (LEDS << 1) | (LEDS >> 7); // Circular shift left
// }

// byte LEDS = 0xAA;

// void loop()
// {
//   // Shift out the LED states
//   digitalWrite(LATCH_PIN, LOW);
//   shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, LEDS);
//   digitalWrite(LATCH_PIN, HIGH);
//   delay(1000);

//   LEDS >>= 1; // Shift the bits to the right
//   if (LEDS == 0x00) {
//     LEDS = 0xAA; // Reset to the initial pattern if all LEDs are off
//   }
// }

// byte LEDS = 0x00;

// // binary counter for LEDs
// void loop()
// {
//   // Shift out the LED states
//   digitalWrite(LATCH_PIN, LOW);
//   shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, LEDS);
//   digitalWrite(LATCH_PIN, HIGH);
//   delay(200);

//   LEDS++;

//   // not strictly necessary since bytes wrap around automatically when they overflow
//   if (LEDS > 0xFF)
//   {
//     // Reset to 0 if it exceeds 255
//     LEDS = 0x00;
//   }
// }

// byte LEDS = 0xAA;

// // alternating pattern of LEDs
// void loop() {
//   // Shift out the LED states
//   digitalWrite(LATCH_PIN, LOW);
//   shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, LEDS);
//   digitalWrite(LATCH_PIN, HIGH);
//   delay(200);

//   LEDS = ~LEDS; // Toggle the LED states

//   digitalWrite(LATCH_PIN, LOW);
//   shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, LEDS);
//   digitalWrite(LATCH_PIN, HIGH);
//   delay(200);
// }
