#include "BDD.hpp"
#include <SPIFFS.h>

BDD::BDD(String nBDD, String adresseIP){

    BDD::nomBDD = nBDD;
    BDD::ip = adresseIP;

}

String BDD::requeteBDD(String sql){

    if(WiFi.status() == WL_CONNECTED){
        BDD::https.begin(BDD::ip);
        BDD::reponse = BDD::https.POST(sql);
        Serial.print("Réponse HTTP : ");
        Serial.println(BDD::reponse);
        return(BDD::reponse);
    }
    else{
        return("Erreur réseau");
    }

}

String BDD::batterieBDD(float pourcentage){

    if(WiFi.status() == WL_CONNECTED){
        BDD::https.begin(BDD::ip);
        BDD::reponse = BDD::https.POST("UPDATE cale SET batterie = " + String(pourcentage) + " WHERE employee = 1;");
        Serial.print("Réponse HTTP : ");
        Serial.println(BDD::reponse);
        return(BDD::reponse);
    }
    else{
        return("Erreur réseau");
    }

}