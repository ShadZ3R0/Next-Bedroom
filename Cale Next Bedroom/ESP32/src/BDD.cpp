#include "BDD.hpp"
#include <SPIFFS.h>

BDD::BDD(String nBDD, String adresseIP){

    if(!SPIFFS.begin()){
        Serial.println("Erreur SPIFFS");
        return;
    }
    File fichier = SPIFFS.open("/config.txt", "r");
    if(!fichier){
        Serial.println("Fichier /config.txt non-trouvé");
        return;
    }
    while(fichier.available()){
        String ligne = fichier.readStringUntil('\n');
        if(ligne.startsWith("id=")){
            BDD::identifiant = ligne.substring(3);
            Serial.print("Identifiant : ");
            Serial.println(BDD::identifiant);
        }
        else if(ligne.startsWith("mdp=")){
            BDD::motDePasse = ligne.substring(4);
            Serial.print("Mot de Passe : ");
            Serial.println(BDD::motDePasse);
        }
    }
    fichier.close();
    BDD::nomBDD = nBDD;
    BDD::ip = "https://" + adresseIP + "/datas.php";

}

String BDD::requeteBDD(String sql){

    if(WiFi.status() == WL_CONNECTED){
        BDD::https.begin(BDD::ip);
        BDD::https.addHeader("Content-Type", "application/x-www-form-urlencoded");
        BDD::reponse = BDD::https.POST(sql);
        Serial.print("Réponse HTTP : ");
        Serial.println(BDD::reponse);
        return(BDD::reponse);
    }
    else{
        return("Erreur réseau");
    }

}

String BDD::batterieBDD(float tension, float pourcentage){

    if(WiFi.status() == WL_CONNECTED){
        BDD::https.begin(BDD::ip);
        BDD::https.addHeader("Content-Type", "application/x-www-form-urlencoded");
        BDD::reponse = BDD::https.POST("tension=" + String(tension) + "pourcentage=" + String(pourcentage));
        Serial.print("Réponse HTTP : ");
        Serial.println(BDD::reponse);
        return(BDD::reponse);
    }
    else{
        return("Erreur réseau");
    }

}