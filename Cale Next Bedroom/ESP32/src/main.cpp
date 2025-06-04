#include "Batterie.hpp"
#include "BDD.hpp"

Batterie bat(A0, D0);
String sSID;
String mdpWiFi;
BDD bDD;

void setup() {
  Serial.begin(9600);

  SPIFFS.begin();
  
  File fileSSID = SPIFFS.open("/SSID.txt", "r");
  while (fileSSID.available()) {
    sSID += (char)fileSSID.read();
  }
  fileSSID.close();

  File filemdpWiFi = SPIFFS.open("/mdpWiFi.txt", "r");
  while (filemdpWiFi.available()) {
    mdpWiFi += (char)filemdpWiFi.read();
  }
  filemdpWiFi.close();

  pinMode(A0, INPUT);
  pinMode(D0, OUTPUT);

  WiFi.begin(sSID, mdpWiFi);
  Serial.println("Connecting to WIFI…");

  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  delay(1000);
  bDD.batterieBDD(bat.getPourcentage());
}

void loop() {
  
}