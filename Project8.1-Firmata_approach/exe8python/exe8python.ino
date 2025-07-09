#include <MsTimer2.h>

const int ledPin = 4;  
volatile bool ledState =false;
unsigned long toggleInterval = 5000; // Unsigned = cannot be negative. without const  it make it changeable
int Resonsebutton= 6;

void turn_off() {
  digitalWrite(ledPin, LOW);         // Turn off the LED
  ledState = false;
  MsTimer2::stop();                  // Stop the timer
  Serial.println("Timer expired: LED turned OFF");
}

void handleInterrupt() {
  // Restart the timer when interrupt occurs (e.g., button press on pin 2)
  MsTimer2::stop();                  // Stop any existing timer
  MsTimer2::start();
  digitalWrite(ledPin, HIGH);        // Turn LED on immediately
  ledState = true;
  Serial.println("Interrupt triggered: LED turned ON and timer started");
}

void setup() {
  Serial.begin(9600);         // Start serial communication
  pinMode(ledPin, OUTPUT);    // Set LED pin as output
  pinMode(Resonsebutton, INPUT);
  Serial.println("Ready to receive commands...");
  MsTimer2::set(toggleInterval, turn_off);

  attachInterrupt(digitalPinToInterrupt(2), handleInterrupt, RISING);
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n'); // Read input from serial
    input.trim();                                // Clean up input

    unsigned long newInterval = input.toInt();   // Convert to number
    if (newInterval > 0) {
      toggleInterval = newInterval;
      MsTimer2::set(toggleInterval, turn_off);
         
      Serial.print("Interval updated to: ");
      Serial.println(toggleInterval);
    }
  }
}