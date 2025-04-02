#ifndef CapteurRFID_HPP
#define CapteurRFID_HPP

#include <MFRC522.h>
#include <SPI.h>


// Définition des pins pour le module MFRC522
#define SS_PIN 21   // Pin de sélection du module (GPIO5 sur l'ESP32)
#define RST_PIN 22 // Pin de réinitialisation du module (GPIO22 sur l'ESP32)

class CapteurRFID{

    private:

    MFRC522 mfrc522;  // Objet pour interagir avec le module MFRC522
    bool carteDetecter; // Variable pour vérifier si une carte est détectée
    

    public: 

      // Constructeur
      CapteurRFID(int ssPin, int rstPin);

      // Méthode pour initialiser le module RFID
      void begin();
  
      // Méthode pour lire une carte RFID
      bool lireCarte();
  
      // Méthode pour afficher les informations de la carte RFID
      void displayCarteInfo();
    

};

#endif