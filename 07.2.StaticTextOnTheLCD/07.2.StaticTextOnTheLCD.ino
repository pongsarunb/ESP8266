/*
   * ติดตั้ง Library -> 
 * 1. Download "https://github.com/marcoschwartz/LiquidCrystal_I2C/archive/master.zip"
 * 2. Copy Unzip folder to "C:\Users\XXX\Documents\Arduino\libraries"
 * 
 * Documentation
 * -------------
 * https://randomnerdtutorials.com/esp32-esp8266-i2c-lcd-arduino-ide/
 * 
 * Circuit
 * I2C LCD +++ MCU
 * ---------------
 * GND  -> GND
 * VCC  -> VIN
 * SDA  -> GPIO 4 (D2)
 * SCL  -> GPIO 5 (D1)
 * 
 * 
 * "Scan LCD Address"
 *  ----------------
 */
#include <LiquidCrystal_I2C.h>

// set the LCD number of columns and rows
int lcdColumns = 16;
int lcdRows = 2;

// set LCD address, number of columns and rows
// if you don't know your display address, run an I2C scanner sketch
LiquidCrystal_I2C lcd(0x3F, lcdColumns, lcdRows);  

void setup(){
  // initialize LCD
  lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();
}

void loop(){
  // set cursor to first column, first row
  lcd.setCursor(0, 0);
  // print message
  lcd.print("Hello, World!");
  delay(1000);
  // clears the display to print new message
  lcd.clear();
  // set cursor to first column, second row
  lcd.setCursor(0,1);
  lcd.print("Hello, World!");
  delay(1000);
  lcd.clear(); 
}
