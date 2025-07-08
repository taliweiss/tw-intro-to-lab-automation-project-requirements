#include <MD_PWM.h>

const int potPin = A0;     // Rotary potentiometer connected to A0
MD_PWM pwm4(4);            //Output pin: Pin 4, controlled via software PWM (MD_PWM)
const uint16_t PWM_FREQ = 30;    // in Hz

void setup() {
  Serial.begin(9600);
  pwm4.begin(PWM_FREQ);
  pwm4.enable();
  pwm4.write(255/4);
}

void loop() {
  int potValue = analogRead(potPin);      // gets values from 0 to 1023
  Serial.println(potValue);
}