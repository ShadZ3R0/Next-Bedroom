#include "Batterie.hpp"
#include "BDD.hpp"

void setup() {
  pinMode(A0, INPUT);
  pinMode(D0, OUTPUT);
  Serial.begin(9600);
  WiFi.begin("D224", "&aqw1AQW&aqw1AQW");
  Serial.println("Connecting to WIFI…");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  delay(1000);
  BDD batBDD("test", "http://172.30.50.15/datas.php");
  batBDD.requeteBDD("test");
}

void loop() {
}