#include <DS1307RTC.h>
#include <Timelib.h>
#include "config.h"
#include "structure.h"

struct SensorsValues sensorsValues;


void setup() {
#ifdef OUTPUT_ACTIONNER
  setupOutput();
#endif
#ifdef PRESSURE_SENSOR
  setupPressureUnit();
#endif
  delay(900);
  //tft.fillScreen(TFT_BACKGROUND_COLOR);
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
#ifdef OUTPUT_ACTIONNER
  loopOutput();
#endif
  delay(1000);
}
