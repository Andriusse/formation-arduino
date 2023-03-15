/**
* fonction d'attente serie pour la saisie
* @param msTimeout millis de timeout pour l'attente
*/
void waitSerialUntilNotAvailable(uint16_t msTimeout = 15000) {
  uint16_t counter = 0;
  Serial.flush();
  while (Serial.available() == 0 && counter < msTimeout) {
    counter += 300;
    delay(300);
  }
}
/**
* var globale du nom utilisateur
*/
char nameStr[10] = "NONAME";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("DEMAT BREIZH,\n votre nom : ");
  waitSerialUntilNotAvailable();
  if (Serial.available() > 0) {
    uint8_t sizeRead = Serial.available();
    Serial.readBytesUntil('\n', nameStr, 10);
    if (sizeRead < 10) {
      nameStr[sizeRead - 1] = '\0';
    } else {
      nameStr[9] = '\0';
    }
  } else {
    Serial.println("je n'ai pas votre nom");
  }
  Serial.println(nameStr);
}

void loop() {
  Serial.print("DEMAT ");
  Serial.println(nameStr);
  delay(1000);
}
