// This code uses an ultrasonic sensor to measure distance.
// The distance is then used to control a buzzer.

// Defines pins numbers
const int trigPin = 5;
const int echoPin = 6;
const int buzzerPin = 8;


// Defines variables
long duration;
int distance = 0;

void setup() {
  // Sets the trigPin as an Output
  pinMode(trigPin, OUTPUT);

  // Sets the echoPin as an Input
  pinMode(echoPin, INPUT);

  // Sets the buzzerPin as an Output
  pinMode(buzzerPin, OUTPUT);

  // Starts the serial communication
  Serial.begin(9600);
}

void loop() {
  // Measures the distance to the nearest object using the ultrasonic sensor
  distance = measureDistance();

  // Checks the distance and turns on the buzzer accordingly
  if (distance < 50) {
    // The object is very close
    digitalWrite(buzzerPin, HIGH);
  } else if (distance > 50 && distance < 150) {
    // The object is within range
    digitalWrite(buzzerPin, HIGH);
    delay(10 * (distance - 50));
    digitalWrite(buzzerPin, LOW);
  } else if (distance > 150 && distance < 200) {
    // The object is getting close
    digitalWrite(buzzerPin, HIGH);
    delay(1000);
    digitalWrite(buzzerPin, LOW);
  } else {
    // The object is far away
    digitalWrite(buzzerPin, LOW);
  }

  // Waits for 10 microseconds before clearing the trigPin
  delayMicroseconds(10);

  // Clears the trigPin
  digitalWrite(trigPin, LOW);

  // Waits for 2 microseconds
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);

  // Waits for 10 microseconds
  delayMicroseconds(10);

  // Clears the trigPin
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  distance = duration * 0.034 / 2;

  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance); // distance is the returned integer, it is the distance in cm
}

// This function measures the distance to the nearest object using the ultrasonic sensor.
long measureDistance() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);

  // Waits for 2 microseconds
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);

  // Waits for 10 microseconds
  delayMicroseconds(10);

  // Clears the trigPin
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  long duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  return duration * 0.034 / 2;

}
