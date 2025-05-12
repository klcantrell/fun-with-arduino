#include <Arduino.h>

const int x_pin = A0;
const int y_pin = A1;
const int switch_pin = 2;

void setup()
{
    Serial.begin(9600); // Initialize serial communication
    pinMode(x_pin, INPUT); // Set x-axis pin as input
    pinMode(y_pin, INPUT); // Set y-axis pin as input
    pinMode(switch_pin, INPUT_PULLUP); // Set switch pin as input with pull-up
}

void loop()
{
    int x_value = analogRead(x_pin); // Read x-axis
    int y_value = analogRead(y_pin); // Read y-axis
    int switch_state = digitalRead(switch_pin); // Read switch (pressed = LOW)

    Serial.print("X: ");
    Serial.print(x_value);
    Serial.print(", Y: ");
    Serial.print(y_value);
    Serial.print(", Switch: ");
    Serial.println(switch_state == LOW ? "Pressed" : "Released");

    delay(200); // Small delay for readability
}
