// Define variables
int windDirectionPin = A1;  // Analog pin for wind direction
int windDirValue = 0;
// int windDirection;  // Add this line to declare windDirection variable
void setup() {
  Serial.begin(9600);
}

void loop() {
  // Read wind direction
  windDirValue = analogRead(windDirectionPin);

  // Print raw analog value to serial monitor
  Serial.print("Raw Analog Value: ");
  Serial.println(windDirValue);

// Map analog reading to wind direction
  String windDirection;

  if (windDirValue > 600 && windDirValue < 630) {
    windDirection = "North";
  } else if (windDirValue > 640 && windDirValue < 670) {
    windDirection = "Northwest";
  } else if (windDirValue > 670 && windDirValue < 700) {
    windDirection = "West";
  } else if (windDirValue > 540 && windDirValue < 570) {
    windDirection = "Southwest";
  } else if (windDirValue > 360 && windDirValue < 400) {
    windDirection = "South";
  } else if (windDirValue > 300 && windDirValue < 359) {
    windDirection = "Southeast";
  } else if (windDirValue > 250 && windDirValue < 280) {
    windDirection = "East";
  } else if (windDirValue > 440 && windDirValue < 490) {
    windDirection = "Northeast";
  } else {
    windDirection = "Unknown";
  }

  // Print wind direction to serial monitor
  Serial.print("Wind Direction: ");
  Serial.println(windDirection);
  delay(1000);  // Adjust delay as needed
}
