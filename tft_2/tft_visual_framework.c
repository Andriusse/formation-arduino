#include <Arduino.h>
#include "tft_visual_frame_framework.h"

void makeCadre(uint8_t x, uint8_t y, uint8_t w, uint8_t h, const char *title){ // mettre uint16 si écran >4 pouces
  setFloatValueInCadre(x,y,w,h,0.0F,2);
}

void setFloatValueInCadre(uint8_t x, uint8_t y, uint8_t w, uint8_t h, float value, uint8_t precision){

  
}