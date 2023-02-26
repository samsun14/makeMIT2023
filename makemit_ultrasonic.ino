const int trigPin = 9;
const int echoPin = 10;
// defines variables
long duration;
int distance;
int x = 0;
int y = 0;
#include <Servo.h>
Servo servo1;

void setup() {
  servo1.attach(11);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
}
void loop() {
  if (distance < 40) {
    servo1.write(90);
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    delay(5000);
    x = 0;
    y = 0;
  } else {
    servo1.write(0);
    y = 1;
  }

  if (x < 25){
    x = x - 1 + pow(2,y);
  } else{
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    x = 0;
  }
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  Serial.println(x);
  delay(200);
} 
