#include <Adafruit_BMP085.h>

#include <DS1307RTC.h>
#include <Timelib.h>
#include "structure.h"

struct SensorsValues sensorsValues;


void setup() {
Serial.begin(9600);
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
  readTemperature(sensorsValues.temperature);
  #endif
  delay(1000);
}
