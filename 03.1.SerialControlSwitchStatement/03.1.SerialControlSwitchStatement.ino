/*
  Note uses LED_BUILTIN for SHIPSET CP2102
  Note use D4 for SHIPSET CH340
*/
const int ledPin = D4;
int timeOff = 100;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() > 0){
    int inRead = Serial.read();

    switch(inRead){
      case '1': digitalWrite(ledPin, HIGH);
        break;
      case '0': digitalWrite(ledPin, LOW);
        break;
      default: digitalWrite(ledPin, LOW);
    }
    delay(timeOff);
  }
}
