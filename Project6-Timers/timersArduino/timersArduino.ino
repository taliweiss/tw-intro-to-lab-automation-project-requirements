volatile bool ledOn = false;
unsigned long ledOnTime = 0;
const unsigned int ledDuration = 5000; // 5 seconds
volatile bool ledState = LOW; 
const int Pin13=13;

#include <MsTimer2.h>

// Interrupt Service Routine (ISR)
void handleInterrupt() {
  ledOn = true; // Set flag when interrupt occurs
  digitalWrite(Pin13, HIGH);
  MsTimer2::start();
}

void toggleLED() {
  ledState = !ledState;
  digitalWrite(Pin13, ledState);
  ledOn = false;
   MsTimer2::stop();
}

void setup() {
  pinMode(6, INPUT);
  pinMode(2, INPUT_PULLUP); // Configure interrupt pin (2) as input with internal pull-up resistor
  pinMode(Pin13, OUTPUT);       // Configure Grove LED pin as output

  // Attach interrupt to pin 2, trigger on FALLING edge (button press)
 attachInterrupt(digitalPinToInterrupt(2), handleInterrupt, RISING);
  // attachInterrupt(digitalPinToInterrupt(2), ISR_BUTTON, CHANGE);

  Serial.begin(9600); // Initialize serial communication
  Serial.println("Interrupt pin setup complete!");

  MsTimer2::set(ledDuration, toggleLED); // 5000 ms period
 
}

void loop() {
  for (int i = 0; i< 10000; i++){
    Serial.println("calculating...");
}
}

