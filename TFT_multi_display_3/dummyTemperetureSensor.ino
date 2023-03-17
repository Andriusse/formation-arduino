#include "config.h"
#ifdef DUMMY_TEMPERATURE
float readTemperature() {
  sensorsValues.temperature = 0.0F;
  return sensorsValues.temperature;
}
#endif