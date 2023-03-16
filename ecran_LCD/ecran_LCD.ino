#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735

#include <SPI.h>


  // For the breakout board, you can use any 2 or 3 pins.
  // These pins will also work for the 1.8" TFT shield.
  #define TFT_CS        10
  #define TFT_RST        9 // Or set to -1 and connect to Arduino RESET pin
  #define TFT_DC         8



Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setupScreen(){
tft.setCursor(10,10);
tft.setTextSize(2);
tft.setTextColor(0x7FB8);
tft.print("Orsys");
tft.setCursor(10,50);
tft.setTextColor(0xFFFF);

  
}



void setup(void) {
  Serial.begin(9600);


  // Use this initializer if using a 1.8" TFT screen:
  tft.initR(INITR_BLACKTAB);      // Init ST7735S chip, black tab

  delay(1000);
}

void loop() {

}

