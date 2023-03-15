/*
* Afficheur 16x2
*/
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


#define R1 2000
#define R2 560
#define PIN_VOLTMETRE A0

#define MAX_VOLTS_INPUT 22.857F  //mettre le F à la fin pour les virgules
#define RATION_VOLT (float)(22.857F / 5.0F)


/*
* caractere special
*/
byte Ohm[8]={
  B00000,
    B00100,
    B01010,
    B10001,
    B01010,
    B11011
};

void lcdStartupScreen() {
  lcd.setCursor(5, 0);
  lcd.write((byte)0);
  lcd.print("rsys");
  lcd.setCursor(3, 0);
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
  lcd.print(value);
  lcd.print("V");
}




void setup() {
  // put your setup code here, to run once:
  lcd.createChar(0, Ohm);

  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.setCursor(4, 0);
/* 
* demande de transformation forcé demanandé par la fonction write '(byte)0'
*/
  lcd.write((byte)0);
  lcd.print("rsys");

  lcd.setCursor(0, 1);
  lcd.print("Voltmetre");
  delay(2000);
  lcd.clear();
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
