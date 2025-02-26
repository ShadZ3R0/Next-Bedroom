#include <Arduino.h>
#include "Batterie.hpp"

void setup() {
  pinMode(A0, INPUT);
  pinMode(D0, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Batterie bat(A0, D0);
  Serial.println(bat.getPourcentage());
  delay(100);
}