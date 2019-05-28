/*
 * Document
 * https://randomnerdtutorials.com/guide-for-mq-2-gas-smoke-sensor-with-arduino/
 * 
 * Circuit
 * MQ2 +++ MCU
 * ----     ---
 * VCC  ->  VIN
 * GND  ->  GND
 * A0  ->  A0
 */

int LedRedPin = 4;    //GPIO4 (D2)
int LedGreenPin = 5;  //GPIO5 (D1)
int MQ2Sensor = A0;

int sensorThres = 1000;

void setup() {
  Serial.begin(9600);
  pinMode(MQ2Sensor, INPUT);
  pinMode(LedRedPin, OUTPUT);
  pinMode(LedGreenPin, OUTPUT);
}

void loop() {
  int analogSensor = analogRead(MQ2Sensor);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
    digitalWrite(LedRedPin, HIGH);
    digitalWrite(LedGreenPin, LOW);
  }
  else
  {
    digitalWrite(LedRedPin, LOW);
    digitalWrite(LedGreenPin, HIGH);
  }
  delay(100);
}
