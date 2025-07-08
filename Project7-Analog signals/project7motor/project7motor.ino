#include <Servo.h>  // Include the Servo library

Servo myServo;      // Create a Servo object

void setup() {
  myServo.attach(7);  // Attach the servo to digital pin 7
}

void loop() {
  myServo.write(180);  // Move the servo to 90 degrees
  delay(5000);
  myServo.write(0);   // Move the servo to 0 degrees
  delay(5000);
}