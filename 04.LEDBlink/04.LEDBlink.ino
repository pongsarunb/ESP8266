/*
  D7  -> LED(ANODE) ขายาว
  G   -> LED(CATHODE) ขาสั้น
*/
const int ledPin = D7;
int timeOff = 500;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
    digitalWrite(ledPin, HIGH);
    delay(timeOff);
    
    digitalWrite(ledPin, LOW);
    delay(timeOff);
}
