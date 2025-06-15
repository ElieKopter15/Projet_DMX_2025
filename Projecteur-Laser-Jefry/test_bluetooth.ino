#include "BluetoothSerial.h"

// Crée une instance Bluetooth
BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);            // Moniteur série
  SerialBT.begin("ESP32_BT_TEST"); // Nom visible du module
  Serial.println("Bluetooth prêt. Jumelage depuis votre téléphone.");
}

void loop() {
  // Si on reçoit quelque chose en Bluetooth, l'affiche sur le moniteur série
  if (SerialBT.available()) {
    char c = SerialBT.read();
    Serial.write(c); // Affiche ce qu'on reçoit
  }

  // Tu peux aussi envoyer depuis le moniteur série vers le Bluetooth
  if (Serial.available()) {
    char c = Serial.read();
    SerialBT.write(c);
  }
}
