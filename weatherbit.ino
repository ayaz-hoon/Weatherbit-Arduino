#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme; // Create BME280 sensor object

void setup() {
  Serial.begin(9600);
  
  if (!bme.begin(0x76)) { // Set the I2C address to 0x76
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
}

void loop() {
  Serial.print("Temperature: ");
  Serial.print(bme.readTemperature());
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(bme.readHumidity());
  Serial.println(" %");

  Serial.print("Pressure: ");
  Serial.print(bme.readPressure() / 100.0F);
  Serial.println(" hPa");

  Serial.print("Altitude: ");
  Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  Serial.println(" meters");

  Serial.println();

  delay(2000); // Wait for 2 seconds before reading again
}
