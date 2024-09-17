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

