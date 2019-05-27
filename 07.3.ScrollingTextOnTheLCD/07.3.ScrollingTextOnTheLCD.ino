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

String messageStatic = "Static message";
String messageToScroll = "This is a scrolling message with more than 16 characters";

void scrollText(int row, String message, int delayTime, int lcdColumns) {
  for (int i=0; i < lcdColumns; i++) {
    message = " " + message;  
  } 
  message = message + " "; 
  for (int pos = 0; pos < message.length(); pos++) {
    lcd.setCursor(0, row);
    lcd.print(message.substring(pos, pos + lcdColumns));
    delay(delayTime);
  }
}

void setup(){
  // initialize LCD
  lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();
}

void loop(){
  // set cursor to first column, first row
  lcd.setCursor(0, 0);
  // print static message
  lcd.print(messageStatic);
  // print scrolling message
  scrollText(1, messageToScroll, 250, lcdColumns);
}
