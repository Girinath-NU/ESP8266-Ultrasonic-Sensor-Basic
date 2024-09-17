# Ultrasonic Sensor with ESP8266
This project demonstrates how to interface an ultrasonic sensor (such as the HC-SR04) with the ESP8266 microcontroller to measure distance.

# Components Needed:
ESP8266 (NodeMCU or similar)
Ultrasonic Sensor (HC-SR04)
Jumper wires
Breadboard (optional)

# Sensor Pin Layout:
VCC: Power supply (typically 5V)
GND: Ground
Trig: Trigger pin (connected to GPIO5, which is labeled as D1 on the ESP8266)
Echo: Echo pin (connected to GPIO4, which is labeled as D2 on the ESP8266)

# Circuit Connection:
Trig Pin (ESP8266) -> GPIO5 (labeled D1)
Echo Pin (ESP8266) -> GPIO4 (labeled D2)
VCC -> 5V (on ESP8266)
GND -> GND (on ESP8266)

# How the Ultrasonic Sensor Works:
The Trig pin is set HIGH for 10 microseconds to send out an ultrasonic pulse.
The Echo pin listens for the return of the ultrasonic wave, which bounces back after hitting an object.
The time taken by the pulse to travel to the object and back is used to calculate the distance.
Distance (cm) = (duration / 2) * 0.0344

# Code Description:
The code sends a pulse from the ultrasonic sensor and reads the echo to determine the time taken. This time is then used to calculate the distance, which is printed to the Serial Monitor.

cpp
Copy code
// Define pins for the ultrasonic sensor
const int trigPin = 5;  // GPIO5, which is labeled as D1 on ESP8266
const int echoPin = 4;  // GPIO4, which is labeled as D2 on ESP8266

void setup() {
  Serial.begin(9600);  // Initialize serial communication at 9600 baud rate
  pinMode(trigPin, OUTPUT);  // Set the Trig pin as an OUTPUT
  pinMode(echoPin, INPUT);   // Set the Echo pin as an INPUT
}

void loop() {
  long duration;
  int distance;

  // Clear the Trig pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Set the Trig pin high for 10 microseconds to start the measurement
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the Echo pin, and measure the time it takes for the pulse to return
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in cm (duration / 2 because the pulse travels to the obstacle and back)
  distance = duration * 0.0344 / 2;

  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Check if an obstacle is detected (optional, set threshold distance as needed)
  if (distance < 10) {
    Serial.println("Obstacle detected!");
  }

  // Wait for a short time before taking another measurement
  delay(500);
}

# Example Output:
When the sensor detects an object within its range, the distance will be printed to the Serial Monitor. For example:

makefile
Copy code
Distance: 15 cm
Distance: 9 cm
Obstacle detected!
Distance: 25 cm

# Notes:
The sensor might need 5V power, while the ESP8266 works on 3.3V logic. Ensure the sensor and microcontroller are compatible, and consider using a voltage divider or logic level converter for the Echo pin if needed.
The range of the HC-SR04 is from 2cm to 400cm.
