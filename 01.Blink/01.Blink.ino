/*
  Note uses LED_BUILTIN for SHIPSET CP2102
  Note use D4 for SHIPSET CH340
*/

void setup() {
  pinMode(D4, OUTPUT);          // Initialize the LED_BUILTIN pin as an output
}

void loop() {
  digitalWrite(D4, LOW);        // Turn the LED on (Note that LOW is the voltage level
  delay(1000);                  // Wait for a second

  digitalWrite(D4, HIGH);       // Turn the LED off by making the voltage HIGH
  delay(1000);                  // Wait for a seconds (to demonstrate the active low LED)
}
