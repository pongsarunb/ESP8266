/*
 * Document
 * https://www.instructables.com/id/Interface-PIR-Sensor-With-NodeMCU/
 * 
 * Circuit
 * PIR +++ MCU
 * ----     ---
 * VCC  ->  VIN
 * GND  ->  GND
 * OUT  ->  D4 (GPIO 2)
 */

int PirPin = 13;     //GPIO7 (D7)
int LedPin = 4;     //GPIO4 (D2)

void setup() {
  Serial.begin(9600);
  pinMode(PirPin, INPUT);
  pinMode(LedPin, OUTPUT);
}

void loop() {
  long state = digitalRead(PirPin);

  if(state == HIGH) {
      Serial.println("Motion detected!");
      digitalWrite (LedPin, HIGH);
      delay(1000);
    }
    else {
      Serial.println("Motion absent!");
      digitalWrite (LedPin, LOW);
      delay(1000);
    }
}
