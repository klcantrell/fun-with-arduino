#include <Arduino.h>
#include <LiquidCrystal.h>
#include <DHT.h>

#define TYPE DHT11

int const RS = 7;  // Register Select pin
int const EN = 8;  // Enable pin
int const D4 = 9;  // Data pin 4
int const D5 = 10; // Data pin 5
int const D6 = 11; // Data pin 6
int const D7 = 12; // Data pin 7
int const DHT_PIN = 2;

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);
DHT dht(DHT_PIN, TYPE);

float humidity;
float temperatureF;
float temperatureC;

void setup()
{
  lcd.begin(16, 2); // Initialize the LCD with 16 columns and 2 rows
  dht.begin();
}

void loop()
{
  humidity = dht.readHumidity();
  temperatureF = dht.readTemperature(true);
  temperatureC = dht.readTemperature();

  lcd.setCursor(0, 0);
  lcd.print("H:");
  lcd.print(round(humidity));
  lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print("T:");
  lcd.print(round(temperatureF));
  lcd.print((char)223); // Degree symbol
  lcd.print("F/");

  lcd.print(round(temperatureC));
  lcd.print((char)223); // Degree symbol
  lcd.print("C");

  delay(500);
  lcd.clear();
}
