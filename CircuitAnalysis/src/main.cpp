#include <Arduino.h>
#include <stdint.h>

uint8_t const ANALOG_PIN = A1;  // Define analog pin A1
uint8_t const RED_LED = 8;     // Define LED pin
uint16_t sensorValue = 0;       // Variable to store the sensor reading
float voltage = 0;              // Variable to store the calculated voltage

void setup() {
  Serial.begin(9600);      // Initialize serial communication
  pinMode(RED_LED, OUTPUT); // Set LED pin as output
}

void loop() {
  // Read the analog value (0-1023)
  sensorValue = analogRead(ANALOG_PIN);
  
  // Convert the analog reading (0-1023) to voltage (0-5V)
  voltage = (sensorValue / 1023.) * 5.0;
  
  // Print the results to Serial Monitor
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  Serial.print(" - Voltage: ");
  Serial.print(voltage);
  Serial.println("V");
  
  // Control LED based on voltage
  if (voltage >= 4.0) {
    digitalWrite(RED_LED, HIGH);  // Turn LED on
  } else {
    digitalWrite(RED_LED, LOW);   // Turn LED off
  }
  
  delay(500); // Wait before the next reading
}
