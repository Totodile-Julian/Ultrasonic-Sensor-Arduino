#include <NewPing.h>

#define TRIGGER_PIN  9
#define ECHO_PIN     10
#define MAX_DISTANCE 140

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

const int temperaturePin = A0;

void setup() {
  Serial.begin(9600); // Starts the serial communication
}

void loop() {
  int analogValue = analogRead(temperaturePin);
  float temperatureCelsius = map(analogValue, 0, 1023, -40, 125);
  float temperatureKelvin = temperatureCelsius + 273.15;

  Serial.print("Temperature: ");
  Serial.print(temperatureKelvin);
  Serial.print(" K");

  unsigned int distance = sonar.ping_median(); // Do multiple pings (default=5), discard out-of-range pings, and return median in microseconds

  Serial.print(" Distance: ");
  Serial.print(distance);
  Serial.println(" mm");

  delay(1000);
}
