//
// Created by Diogo Babo on 18/12/2021.
//

#ifndef PROJ_DE_AED_LUGGAGE_H
#define PROJ_DE_AED_LUGGAGE_H


#include "Passenger.h"
#include "Flight.h"

class Luggage {
private:
    int fi;
    int numLuggage;
public:
    Luggage(int fi,int n);
    Luggage();
    int getNumLuggage();
    int getid();
    void setNumLuggage(int numLuggage);
};


#endif //PROJ_DE_AED_LUGGAGE_H
