#include "BDD.hpp"

BDD::BDD(){
  SPIFFS.begin();
  File fileid = SPIFFS.open("/id.txt", "r");
  while (fileid.available()) {
    BDD::id += (char)fileid.read();
  }
  fileid.close();

  File filemdp = SPIFFS.open("/mdp.txt", "r");
  while (filemdp.available()) {
    BDD::mdp += (char)filemdp.read();
  }
  filemdp.close();

  File fileaddresse = SPIFFS.open("/addresse.txt", "r");
  while (fileaddresse.available()) {
    BDD::ip += (char)fileaddresse.read();
  }
  fileaddresse.close();
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
        BDD::reponse = BDD::https.POST(String(pourcentage) + '|' + BDD::id + '|' + BDD::mdp);
        Serial.print("Réponse HTTP : ");
        Serial.println(BDD::reponse);
        return(BDD::reponse);
    }
    else{
        return("Erreur réseau");
    }

}