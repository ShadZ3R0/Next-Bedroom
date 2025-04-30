#include "CapteurRFID.hpp"
#include <SPI.h>
#include <MFRC522.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <Wire.h>
/*
// Définir les pins pour le module RFID
#define SS_PIN 21  // Pin SDA (Slave Select)
#define RST_PIN 22 // Pin de Reset

// Créer une instance de la classe MFRC522
MFRC522 mfrc522(SS_PIN, RST_PIN);  // Création d'un objet MFRC522

void setup() {
  // Initialisation de la communication série
  Serial.begin(115200);
  
  // Initialisation du module RFID
  SPI.begin();  // Démarre la communication SPI
  mfrc522.PCD_Init();  // Initialisation du module RC522

  Serial.println("Approchez votre carte RFID...");
}

void loop() {
  // Vérifie si une carte est présente
  if (mfrc522.PICC_IsNewCardPresent()) {
    // Sélectionne la carte RFID
    if (mfrc522.PICC_ReadCardSerial()) {
      Serial.println("Carte détectée !");
      
      // Affiche le numéro de série de la carte
      Serial.print("UID de la carte : ");
      for (byte i = 0; i < mfrc522.uid.size; i++) {
        Serial.print(mfrc522.uid.uidByte[i], HEX);
        Serial.print(" ");
      }
      Serial.println();
      
      // Stoppe la lecture de la carte
      mfrc522.PICC_HaltA();
    }
  }
}
*/