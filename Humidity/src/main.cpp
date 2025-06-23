#include <Arduino.h>
#include <DHT.h>

#define TYPE DHT11

int const DHT_PIN = 2;

DHT dht(DHT_PIN, TYPE);

float humidity;
float temperatureF;
float temperatureC;

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  humidity = dht.readHumidity();
  temperatureF = dht.readTemperature(true);
  temperatureC = dht.readTemperature();

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%, Temperature: ");
  Serial.print(temperatureF);
  Serial.print("°F / ");
  Serial.print(temperatureC);
  Serial.println("°C");

  delay(2000);
}
