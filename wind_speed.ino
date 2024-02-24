const int WIND_SPEED_PIN = 2;  // Replace with the actual pin to which the anemometer is connected
volatile int numWindTurns = 0;
unsigned long lastWindTime = 0;

void setup() {
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(WIND_SPEED_PIN), handleWind, RISING);
}

void loop() {
  // Perform other tasks if needed

  // Check wind speed every 2 seconds
  if (millis() - lastWindTime > 2000) {
    // Print the number of turns
    Serial.print("Wind Turns in last 2 seconds: ");
    Serial.println(numWindTurns);

    // Calculate wind speed
    float windSpeedMPH = (numWindTurns / 2.0) / (1492.0 / 1000.0);
    
    // Print the calculated wind speed
    Serial.print("Wind Speed: ");
    Serial.print(windSpeedMPH);
    Serial.println(" MPH");

    // Reset counter and update time
    numWindTurns = 0;
    lastWindTime = millis();

    // Add a delay to allow more pulses to accumulate
    delay(500);
  }
}

void handleWind() {
  // Increment wind turns counter on each pulse
  numWindTurns++;
}
