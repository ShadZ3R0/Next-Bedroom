#ifndef BDD_HPP
#define BDD_HPP
#include <Arduino.h>
#include <HTTPClient.h>

class BDD{

    public:
        BDD(String nBDD, String adresseIP);
        String requeteBDD(String sql);
        String batterieBDD(float pourcentage);

    private:
        String nomBDD;
        String ip;
        HTTPClient https;
        String reponse;

};

#endif