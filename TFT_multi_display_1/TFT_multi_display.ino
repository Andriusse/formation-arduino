#include <Adafruit_BMP085.h>

#include <DS1307RTC.h>
#include <Timelib.h>

#include "tft_positions.h"
#include <Adafruit_GFX.h>     // Core graphics library
#include <Adafruit_ST7735.h>  // Hardware-specific library for ST7735
// #include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>
#define TFT_CS 10
#define TFT_RST 8  // Or set to -1 and connect to Arduino RESET pin
#define TFT_DC 9

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  // put your setup code here, to run once:
  tft.initR(INITR_BLACKTAB);
  screenSetup();
   #ifdef PRESSURE_SENSOR
  setupPressureUnit();
  #endif
  delay(900);
  tft.fillScreen(TFT_BACKGROUND_COLOR);
  readAndShowDatetime();
}

void loop() {
  readAndShowDatetime();
  #ifdef PRESSURE_SENSOR
  readPressure();
  #endif
  #ifdef TEMPERATURE_SENSOR
  readTemperature();
  #endif
  delay(1000);
}
