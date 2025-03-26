#include <Arduino.h>
#include "Batterie.hpp"

Batterie::Batterie(int brocheTension, int brocheLed){

    Batterie::brocheTension = brocheTension;
    Batterie::brocheLed = brocheLed;

}

float Batterie::getTension(){

    return(3.3 - (analogRead(Batterie::brocheTension) * 3.3 / 4095));

}

float Batterie::getPourcentage(){

    Batterie::pourcentage = getTension() * 100 / 3.3;
    if(Batterie::pourcentage < 20){
        digitalWrite(Batterie::brocheLed, HIGH);
    }
    else{
        digitalWrite(Batterie::brocheLed, LOW);
    }
    return(Batterie::pourcentage);

}