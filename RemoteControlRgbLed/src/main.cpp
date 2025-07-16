#include <Arduino.h>
#include <IRremote.h>

// Pin definitions for circuit wiring
const int IR_RECEIVER_PIN = 9; // Connect IR receiver data pin here
const int RED_PIN = 5;         // Red LED pin
const int GREEN_PIN = 6;       // Green LED pin
const int BLUE_PIN = 10;       // Blue LED pin

enum ColorState
{
  OFF,
  WHITE,
  RED,
  BLUE,
  GREEN,
  MAGENTA,
  CYAN,
  YELLOW
};

String command;
int brightness = 0;            // Current brightness level (0-255)
ColorState currentColor = OFF; // Track current color state

// Function declarations
void setColor(ColorState color);
void turnOff();
void setBrightness(int newBrightness);
void applyCurrentColor();

void setup()
{
  Serial.begin(9600);

  // Initialize RGB LED pins
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  // Initialize IR receiver
  IrReceiver.begin(IR_RECEIVER_PIN, ENABLE_LED_FEEDBACK);
}

void loop()
{
  while (IrReceiver.decode() == 0)
    ;
  delay(200);

  // Decode IR command
  switch (IrReceiver.decodedIRData.decodedRawData)
  {
  case 0xBA45FF00:
    command = "power";
    break;
  case 0xB847FF00:
    command = "function";
    break;
  case 0xF609FF00:
    command = "scroll_up";
    break;
  case 0xF807FF00:
    command = "scroll_down";
    break;
  case 0xE916FF00:
    command = "zero";
    break;
  case 0xF30CFF00:
    command = "one";
    break;
  case 0xE718FF00:
    command = "two";
    break;
  case 0xA15EFF00:
    command = "three";
    break;
  case 0xF708FF00:
    command = "four";
    break;
  case 0xE31CFF00:
    command = "five";
    break;
  case 0xA55AFF00:
    command = "six";
    break;
  default:
    command = "unknown";
    break;
  }

  if (command != "unknown")
  {
    Serial.print("Command: ");
    Serial.println(command);

    // Handle RGB LED commands
    if (command == "power")
    {
      setColor(WHITE); // White at max brightness
      setBrightness(255); // Set brightness to maximum;
    }
    else if (command == "zero")
    {
      setColor(WHITE);
    }
    else if (command == "function")
    {
      turnOff(); // Turn off completely
    }
    else if (command == "scroll_up")
    {
      setBrightness(brightness == 0 ? 10 : brightness * 1.2); // Increase brightness by 20%
    }
    else if (command == "scroll_down")
    {
      setBrightness(brightness * 0.8); // Decrease brightness by 20%
    }
    else if (command == "one")
    {
      setColor(RED); // Red
    }
    else if (command == "two")
    {
      setColor(BLUE); // Blue
    }
    else if (command == "three")
    {
      setColor(GREEN); // Green
    }
    else if (command == "four")
    {
      setColor(MAGENTA); // Magenta
    }
    else if (command == "five")
    {
      setColor(CYAN); // Cyan
    }
    else if (command == "six")
    {
      setColor(YELLOW); // Yellow
    }
  }

  IrReceiver.resume();
}

// Function implementations
void setColor(ColorState color)
{
  currentColor = color;
  applyCurrentColor();
}

void turnOff()
{
  currentColor = OFF;
  applyCurrentColor();
}

void setBrightness(int newBrightness)
{
  brightness = newBrightness;
  if (brightness > 230)
    brightness = 255;
  if (brightness < 10)
    brightness = 0;
  applyCurrentColor(); // Reapply current color with new brightness
}

void applyCurrentColor()
{
  switch (currentColor)
  {
  case OFF:
    analogWrite(RED_PIN, 0);
    analogWrite(GREEN_PIN, 0);
    analogWrite(BLUE_PIN, 0);
    break;
  case WHITE:
    Serial.println("Setting WHITE to brightness: " + String(brightness));
    analogWrite(RED_PIN, brightness);
    analogWrite(GREEN_PIN, brightness);
    analogWrite(BLUE_PIN, brightness);
    break;
  case RED:
    analogWrite(RED_PIN, brightness);
    analogWrite(GREEN_PIN, 0);
    analogWrite(BLUE_PIN, 0);
    break;
  case BLUE:
    analogWrite(RED_PIN, 0);
    analogWrite(GREEN_PIN, 0);
    analogWrite(BLUE_PIN, brightness);
    break;
  case GREEN:
    analogWrite(RED_PIN, 0);
    analogWrite(GREEN_PIN, brightness);
    analogWrite(BLUE_PIN, 0);
    break;
  case MAGENTA:
    analogWrite(RED_PIN, brightness);
    analogWrite(GREEN_PIN, 0);
    analogWrite(BLUE_PIN, brightness);
    break;
  case CYAN:
    analogWrite(RED_PIN, 0);
    analogWrite(GREEN_PIN, brightness);
    analogWrite(BLUE_PIN, brightness);
    break;
  case YELLOW:
    analogWrite(RED_PIN, brightness);
    analogWrite(GREEN_PIN, brightness);
    analogWrite(BLUE_PIN, 0);
    break;
  }
}
