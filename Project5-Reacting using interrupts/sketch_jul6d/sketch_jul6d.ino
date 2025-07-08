void setup() {
  // put your setup code here, to run once:
pinMode(6, INPUT_PULLUP);
pinMode(4, OUTPUT); // Set Grove LED pin (4) as output

  Serial.begin(9600); // Initialize the serial port with a baud rate of 9600 (samples to sec)
  Serial.println("Setup complete!"); // Debug statement
}


void loop() {
  int buttonState = digitalRead(6); // Read the state of the button pin

  if (buttonState == LOW) { // Button is pressed (connected to ground)
    digitalWrite(4, HIGH);  // Turn Grove LED on
    Serial.println("LED turned ON."); 
  } else { // Button is not pressed
    digitalWrite(4, LOW);   // Turn Grove LED off
       Serial.println("LED turned OFF."); 
  }
}