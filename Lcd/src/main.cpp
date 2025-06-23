#include <Arduino.h>
#include <LiquidCrystal.h>

int const RS = 7; // Register Select pin
int const EN = 8; // Enable pin
int const D4 = 9; // Data pin 4
int const D5 = 10; // Data pin 5
int const D6 = 11; // Data pin 6
int const D7 = 12; // Data pin 7

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

void setup() {
  lcd.begin(16, 2); // Initialize the LCD with 16 columns and 2 rows
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Counting to 10");

  for (int i = 1; i <= 10; i++) {
    lcd.setCursor(0, 1);
    lcd.print(i);
    delay(1000);
  }

  lcd.clear();
}
