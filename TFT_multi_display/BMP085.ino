#include "config.h"
  #ifdef BMP180

  Adafruit_BMP085 bmp;
  bool setupPressureUnit() {
    return bmp.begin();
  }
  bool readPressure() {
    uint16_t presshp=0L;
    presshp=bmp.readPressure()/100L;
    return true;
  }
  #ifdef BMP180_TEMPERATURE
  float readTemperature(){
    float t0=0.0F;
    t0=bmp.readTemperature();
    return true;
  }
  #endif
#endif