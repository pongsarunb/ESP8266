/*
  D7(13)  -> LED(ANODE) ขายาว
  D2(4)   -> Switch Button (กดติดปล่อยดับ)
  
  G   -> LED(CATHODE) ขาสั้น และ Switch Button
*/

const int ledPin = 13; //D7 = 13
const int buttonPin = 4; //D2 = 4

int timeOff = 500;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if(buttonState == LOW){       //กด
    digitalWrite(ledPin, HIGH);
  } else {                      //ปล่อย
    digitalWrite(ledPin, LOW);
  }

  delay(timeOff);
}
