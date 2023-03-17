#include "config.h"
#ifdef DUMMY_TEMPERATURE
float readTemperature(){
  return sensorsValues.temperature;

}
#endif