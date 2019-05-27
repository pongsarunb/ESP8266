/*
 * ติดตั้ง Library "SSD1306" และ GFX
 * https://github.com/adafruit/Adafruit_SSD1306
 * https://github.com/adafruit/Adafruit-GFX-Library
 * ติดตั้ง Library "LiquidCrystal_I2C" (Manual)
 * 1. Download "https://github.com/marcoschwartz/LiquidCrystal_I2C/archive/master.zip"
 * 2. Copy Unzip folder to "C:\Users\XXX\Documents\Arduino\libraries"
 * 
 * Document
 * https://randomnerdtutorials.com/esp32-esp8266-dht-temperature-and-humidity-oled-display/
 * https://randomnerdtutorials.com/esp32-esp8266-i2c-lcd-arduino-ide/
 * 
 * Circuit
 * DHT22 +++ MCU
 * ----     ---
 * VCC  ->  3V
 * GND  ->  GND
 * OUT  ->  D4 (GPIO 2)
 * 
 * I2C LCD +++ MCU
 * ---------------
 * GND  -> GND
 * VCC  -> VIN
 * SDA  -> GPIO 4 (D2)
 * SCL  -> GPIO 5 (D1)
 */

#include <LiquidCrystal_I2C.h>
#include <DHT.h>

int lcdColumns = 16;
int lcdRows = 2;
LiquidCrystal_I2C lcd(0x3F, lcdColumns, lcdRows); 

#define DHTPIN 2     // Digital pin connected to the DHT sensor

// Uncomment the type of sensor in use:
//#define DHTTYPE    DHT11     // DHT 11
#define DHTTYPE    DHT22     // DHT 22 (AM2302)
//#define DHTTYPE    DHT21     // DHT 21 (AM2301)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);

  dht.begin();

  lcd.init();
  lcd.backlight();
}

void loop() {
  //read temperature and humidity
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print(" %, Temp: ");
    Serial.print(t);
    Serial.println(" Celsius");
  }
  // clear display
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print(" ");
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(h);
  lcd.print(" %");

  delay(5000);
}
