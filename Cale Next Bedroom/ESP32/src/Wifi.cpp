#include "Wifi.hpp"
#include <WiFi.h>



Wifi::Wifi(const char* ssid, const char* password)
    : ssid(ssid), password(password) {}

void Wifi::connect() {
    Serial.begin(115200);
    delay(1000);
    Serial.println("\nConnecting to WiFi...");
    WiFi.mode(WIFI_STA); // Mode Station
    WiFi.begin(ssid, password); // Connexion au réseau WiFi

    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(100);
    }

    Serial.println("\nConnected to the WiFi network");
    getNetworkInfo();
}

void Wifi::getNetworkInfo() {
    if (WiFi.status() == WL_CONNECTED) {
        Serial.print("[*] Network information for ");
        Serial.println(ssid);

        Serial.println("[+] BSSID : " + WiFi.BSSIDstr()); // Adresse MAC du réseau WiFi
        Serial.print("[+] Gateway IP : ");
        Serial.println(WiFi.gatewayIP());  // Adresse IP de la passerelle
        Serial.print("[+] Subnet Mask : ");
        Serial.println(WiFi.subnetMask()); // Masque de sous-réseau
        Serial.println("[+] RSSI : " + String(WiFi.RSSI()) + " dB"); // Puissance du signal WiFi
        Serial.print("[+] ESP32 IP : ");
        Serial.println(WiFi.localIP()); // IP locale de l'ESP32
    }
}

bool Wifi::isConnected() {
    return WiFi.status() == WL_CONNECTED;
}