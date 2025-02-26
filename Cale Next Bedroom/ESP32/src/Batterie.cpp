#include <Arduino.h>
#include "Batterie.hpp"

Batterie::Batterie(int brocheTension, int brocheLed){

    Batterie::brocheTension = brocheTension;
    Batterie::brocheLed = brocheLed;

}

float Batterie::getTension(){

    return(analogRead(Batterie::brocheTension));

}

float Batterie::getPourcentage(){

    Batterie::pourcentage = getTension() * 100 / 4095;
    if(Batterie::pourcentage < 20){
        digitalWrite(Batterie::brocheLed, HIGH);
    }
    else{
        digitalWrite(Batterie::brocheLed, LOW);
    }
    return(Batterie::pourcentage);

}