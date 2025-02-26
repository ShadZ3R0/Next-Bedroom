#ifndef BATTERIE_HPP
#define BATTERIE_HPP

class Batterie{

    public:
        Batterie(int brocheTension, int brocheLed);
        float getTension();
        float getPourcentage();

    private:
        float tension;
        float pourcentage;
        int brocheTension;
        int brocheLed;

};

#endif