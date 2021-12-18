//
// Created by Diogo Babo on 18/12/2021.
//

#ifndef PROJ_DE_AED_LUGGAGE_H
#define PROJ_DE_AED_LUGGAGE_H


#include "Passenger.h"
#include "Flight.h"

class Luggage {
private:
    Passenger pi;
    Flight fi;
    int numLuggage;
public:
    Luggage(Passenger p,Flight f);

};


#endif //PROJ_DE_AED_LUGGAGE_H
