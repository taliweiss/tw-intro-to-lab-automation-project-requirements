volatile bool ledOn = false;
unsigned long ledOnTime = 0;
const unsigned int ledDuration = 5000; // 5 seconds
unsigned long startTime = 0; 

// Interrupt Service Routine (ISR)
void handleInterrupt() {
  ledOn = true; // Set flag when interrupt occurs
  digitalWrite(LED_BUILTIN, HIGH);
  startTime=millis();
  Serial.println("Interrupt IS TRUE!");
}

void setup() {
  pinMode(6, INPUT);
  pinMode(2, INPUT_PULLUP); // Configure interrupt pin (2) as input with internal pull-up resistor
  pinMode(LED_BUILTIN, OUTPUT);       // Configure Grove LED pin (4) as output

  // Attach interrupt to pin 2, trigger on FALLING edge (button press)
 attachInterrupt(digitalPinToInterrupt(2), handleInterrupt, RISING);
  // attachInterrupt(digitalPinToInterrupt(2), ISR_BUTTON, CHANGE);

  Serial.begin(9600); // Initialize serial communication
  Serial.println("Interrupt pin setup complete!");
}

void loop() {
  // Check if LED is on and if 5 seconds passed
  if (ledOn && millis() - startTime >= ledDuration) {
    digitalWrite(LED_BUILTIN, LOW);
    ledOn = false;
  }}

