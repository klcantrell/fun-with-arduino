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
  Serial.begin(9600);
}

void loop() {
  lcd.clear();

  float firstNumber = 0;
  float secondNumber = 0;

  lcd.setCursor(0, 0);
  lcd.print("Enter your first");
  lcd.setCursor(0, 1);
  lcd.print("number:");
  while (!Serial.available());
  firstNumber = Serial.parseFloat();
  lcd.print(firstNumber);
  delay(1000); // Wait for a second to show the first number
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Enter your second");
  lcd.setCursor(0, 1);
  lcd.print("number:");
  while (!Serial.available());
  secondNumber = Serial.parseFloat();
  lcd.print(secondNumber);
  delay(1000); // Wait for a second to show the second number
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Enter your operation");
  lcd.setCursor(0, 1);
  lcd.print("(+, -, *, /):");
  while (!Serial.available());

  String operation = " ";
  while (!Serial.available());
  operation = Serial.readString();
  lcd.clear();

  if (operation != "+" && operation != "-" && operation != "*" && operation != "/") {
    lcd.setCursor(0, 0);
    lcd.print("Invalid operation: ");
    lcd.setCursor(0, 1);
    lcd.print(operation);
  } else {
    lcd.setCursor(0, 0);
    lcd.print("The result is:");
    lcd.setCursor(0, 1);
    if (operation == "+") {
        lcd.print(firstNumber + secondNumber);
    } else if (operation == "-") {
        lcd.print(firstNumber - secondNumber);
    } else if (operation == "*") {
        lcd.print(firstNumber * secondNumber);
    } else if (operation == "/") {
        if (secondNumber != 0) {
            String formatted = String((double)firstNumber / (double)secondNumber, 2);
            lcd.print(formatted);
        } else {
            lcd.print("Error: Div by 0");
        }
    }
  }

  delay(5000); // Display result for 5 seconds
}
