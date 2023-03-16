/*
* Afficheur 16x2
*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//LiquidCrystal_I2C lcd(0x27, 16, 4);
LiquidCrystal_I2C lcd(0x3F,16,2);

#define R1 2000
#define R2 560
#define PIN_VOLTMETRE A0

#define MAX_VOLTS_INPUT 22.857F  //mettre le F à la fin pour les virgules
#define RATION_VOLT (float)(22.857F / 5.0F)


/*
* caractere special
*/
byte Ohm[8] = {
  B00000,
  B00100,
  B01010,
  B10001,
  B01010,
  B11011
};

void lcdStartupScreen() {
  lcd.setCursor(5, 0);
 // lcd.write((byte)0);
  lcd.print("rsys");


  lcd.setCursor(0, 1);
  lcd.print("voltmetre");
}

float calculateVin(uint16_t vADC) {
  return 5.0F / 1024.0F * vADC * RATION_VOLT;
}

void printvoltagevalue(float value) {

  lcd.setCursor(0, 1);
  lcd.print("                ");

  lcd.setCursor(0, 1);
  lcd.print("Voltmetre: ");
   lcd.setCursor(9, 1);
  lcd.print(value);
  lcd.print("V");
}




void setup() {
  // put your setup code here, to run once:


  Serial.begin(9600);

  lcd.init();
  /* 
* demande de transformation forcé demanandé par la fonction write '(byte)0'
*/
 // lcd.createChar(0, Ohm);
  lcd.backlight();

  lcdStartupScreen();

  delay(2000);
  //lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  printvoltagevalue(calculateVin(analogRead(PIN_VOLTMETRE)));

  //  Serial.print("valeur lue : ");
  //float calculateting=calculateVin(analogRead(PIN_VOLTMETRE));
  //  Serial.println(calculateVin(analogRead(PIN_VOLTMETRE)));
  //  Serial.println(analogRead(PIN_VOLTMETRE));
  delay(900);
}
