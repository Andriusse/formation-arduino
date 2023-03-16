#define R1 2000
#define R2 560
#define PIN_VOLTMETRE A0

#define MAX_VOLTS_INPUT 22.857F
#define RATION_VOLT (float)(22.857F / 5.0F)
#define RATIO_ADC (float)(5.0F / 1024.0F)
float calculateVin(uint16_t vADC) {
  return  RATIO_ADC * (float) vADC * RATION_VOLT;
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Valeur lue : ");
  Serial.println(calculateVin(analogRead(PIN_VOLTMETRE)));
  delay(900);
}
