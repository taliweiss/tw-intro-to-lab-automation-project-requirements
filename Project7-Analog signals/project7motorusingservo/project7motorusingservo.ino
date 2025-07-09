#include <MD_PWM.h>
#include <Servo.h>  // Include the Servo library

Servo myServo;      // Create a Servo object

const int potPin = A0;     // Rotary potentiometer connected to A0
MD_PWM pwm4(4);            //Output pin: Pin 4, controlled via software PWM (MD_PWM)
const uint16_t PWM_FREQ = 30;    // in Hz

void setup() {
  Serial.begin(9600);
  pwm4.begin(PWM_FREQ);
  pwm4.enable();
  pwm4.write(255/4);
  myServo.attach(7);  // Attach the servo to digital pin 7
}

void loop() {
  int potValue = analogRead(potPin);      // gets values from 0 to 1023
  Serial.println(potValue);
  myServo.write(potValue);  // Move the servo to 90 degrees
  delay(1000);
}