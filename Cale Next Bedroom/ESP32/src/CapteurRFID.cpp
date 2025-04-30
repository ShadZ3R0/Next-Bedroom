#include "CapteurRFID.hpp"
#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>

// Constructeur de la classe CapteurRFID
CapteurRFID::CapteurRFID(int ssPin, int rstPin) 
    : mfrc522(ssPin, rstPin), carteDetecter(false) {}

// Méthode pour initialiser le module RFID
void CapteurRFID::begin() {
    Serial.begin(115200);  // Démarre la communication série
    SPI.begin();  // Démarre la communication SPI
    mfrc522.PCD_Init();  // Initialise le module MFRC522
    Serial.println("Module RFID initialisé.");
}

// Méthode pour lire une carte RFID
bool CapteurRFID::lireCarte() {
    // Vérifie si une carte est présente
    if (!mfrc522.PICC_IsNewCardPresent()) {
        return false;
    }

    // Sélectionne la carte
    if (!mfrc522.PICC_ReadCardSerial()) {
        return false;
    }

    carteDetecter = true;  // Une carte a été détectée
    return true;
}

// Méthode pour afficher les informations de la carte RFID
void CapteurRFID::displayCarteInfo() {
    if (carteDetecter) {
        Serial.print("carte detecter : ");
        for (byte i = 0; i < mfrc522.uid.size; i++) {
            Serial.print(mfrc522.uid.uidByte[i], HEX);
            Serial.print(" ");
        }
        Serial.println();
        carteDetecter = false;  // Réinitialise l'état de la carte détectée
    } else {
        Serial.println("Aucune carte détectée.");
    }
}