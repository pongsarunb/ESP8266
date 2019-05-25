/*
  Note uses LED_BUILTIN for SHIPSET CP2102
  Note use D4 for SHIPSET CH340
*/
const int ledPin = D4;
int timeOn = 1000;
int timeOff = 500;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.print("LED On/Off ");
  Serial.println(timeOn + timeOff);
}

void loop() {
  digitalWrite(ledPin, LOW);
  Serial.println("LED is ON");
  delay(timeOn);

  digitalWrite(ledPin, HIGH);
  Serial.println("LED is OFF");
  delay(timeOff);
}
