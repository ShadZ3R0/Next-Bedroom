#ifndef BDD_HPP
#define BDD_HPP
#include <Arduino.h>
#include <HTTPClient.h>
#include <SPIFFS.h>

class BDD{

    public:
        BDD();
        String requeteBDD(String sql);
        String batterieBDD(float pourcentage);

    private:
        String ip;
        String id;
        String mdp;
        HTTPClient https;
        String reponse;

};

#endif