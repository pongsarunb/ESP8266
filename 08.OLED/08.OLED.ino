/*
 * I2C Bus Communication
 * ---------------------
 * 
 * ติดตั้ง Library "acrobotic"
 * https://github.com/acrobotic/Ai_Ardulib_SSD1306
 * 
 * Document
 * https://learn.acrobotic.com/tutorials/post/esp8266-oled-display-using-i2c
 * 
 * Circuit
 * OLED +++ MCU
 * ----     ---
 * VCC  ->  3V
 * GND  ->  GND
 * SCL  ->  D1
 * SDA  ->  D2
 */
 
#include <Wire.h>
#include <ACROBOTIC_SSD1306.h>

void setup()
{
  Wire.begin();  
  oled.init();                      // Initialze SSD1306 OLED display
  oled.clearDisplay();              // Clear screen
  
  oled.setTextXY(0,5);              // Set cursor position, start of line 0
  oled.putString("TEST OLED");
  oled.setTextXY(2,6);              // Set cursor position, start of line 2
  oled.putString("DR.TUN");
}

void loop()
{
  
}
